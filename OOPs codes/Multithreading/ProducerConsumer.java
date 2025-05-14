import java.util.concurrent.atomic.AtomicBoolean;

class SharedArray {
    private int[] array = new int[2];
    private volatile boolean available = false;
    private AtomicBoolean lock = new AtomicBoolean(false); // test-and-set lock

    // Test-and-Set implementation
    private void acquireLock() {
        while (lock.getAndSet(true)) {
            // busy wait
        }
    }

    private void releaseLock() {
        lock.set(false);
    }

    public void produce(int number) {
        while (true) {
            acquireLock();
            if (!available) {
                array[0] = number;
                System.out.print("Produced: " + array[0] + '\t');
                available = true;
                releaseLock();
                break;
            }
            releaseLock(); // if resource unavailable, release lock and retry
            Thread.yield();
        }
    }

    public void consume() {
        while (true) {
            acquireLock();
            if (available) {
                array[1] += array[0]; // Add produced number to second position
                System.out.println("Consumed and added. Array: [" + array[0] + ", " + array[1] + "]");
                available = false;
                releaseLock();
                break;
            }
            releaseLock(); // if not available, release lock and retry
            Thread.yield();
        }
    }
}

class Producer extends Thread {
    private SharedArray sharedArray;

    public Producer(SharedArray sharedArray) {
        this.sharedArray = sharedArray;
    }

    public void run() {
        while (true) {
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
        while (true) {
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
