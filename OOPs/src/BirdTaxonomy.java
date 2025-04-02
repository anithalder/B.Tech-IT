abstract class Bird {
    Bird() {
        System.out.println("Bird constructor called");
    }

    abstract void fly();

    abstract void eat();

    abstract void sleep();

    abstract void makeSound();

    abstract void wingSpan();

    abstract void habitat();
}

class Penguin extends Bird {

}

public class BirdTaxonomy {

}
