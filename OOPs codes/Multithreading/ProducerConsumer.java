class SharedArray {
    private int[] array = new int[2];
    private boolean available = false;

    public synchronized void produce(int number) {
        while (available) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        array[0] = number;
        System.out.print("Produced: " + array[0] + '\t');
        available = true;
        notify();
    }

    public synchronized void consume() {
        while (!available) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        array[1] += array[0]; // Add produced number to second position
        System.out.println("Consumed and added. Array: [" + array[0] + ", " + array[1] + "]");
        available = false;
        notify();
    }
}

class Producer extends Thread {
    private SharedArray sharedArray;

    public Producer(SharedArray sharedArray) {
        this.sharedArray = sharedArray;
    }

    public void run() {
        for (int i = 0;; i++) { // Produce 10 numbers
            int number = (int) (Math.random() * 10) + 1;
            sharedArray.produce(number);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    private SharedArray sharedArray;

    public Consumer(SharedArray sharedArray) {
        this.sharedArray = sharedArray;
    }

    public void run() {
        for (int i = 0;; i++) { // Consume 10 numbers
            sharedArray.consume();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ProducerConsumer {
    public static void main(String[] args) {
        SharedArray sharedArray = new SharedArray();
        Producer producer = new Producer(sharedArray);
        Consumer consumer = new Consumer(sharedArray);

        producer.start();
        consumer.start();
    }
}