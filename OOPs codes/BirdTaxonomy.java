abstract class Bird {
    Bird(String name) {
        System.out.println("Bird name: " + name);
    }

    abstract void eat();

    abstract void sleep();

    abstract void makeSound();

    abstract void wingSpan();

    abstract void habitat();
}

// Non-Flying Bird Category
abstract class NonFlyingBird extends Bird {
    NonFlyingBird(String name) {
        super(name);
        System.out.println("This bird cannot fly.");
    }
}

// Flying Bird Category
abstract class FlyingBird extends Bird {
    FlyingBird(String name) {
        super(name);
        System.out.println("This bird can fly.");
    }
}

// Penguin inherits from NonFlyingBird
class Penguin extends NonFlyingBird {
    Penguin(String name) {
        super(name); // Calls NonFlyingBird's constructor
    }

    void swim() {
        System.out.println("Penguins can swim.");
    }

    void eat() {
        System.out.println("Penguins eat fish.");
    }

    void sleep() {
        System.out.println("Penguins sleep in the water or on land.");
    }

    void makeSound() {
        System.out.println("Penguins make a honking sound.");
    }

    void wingSpan() {
        System.out.println("Penguins have a small and flippery wingspan.");
    }

    void habitat() {
        System.out.println("Penguins are found in cold regions like Antarctica.");
    }
}

// Sparrow inherits from FlyingBird
class Sparrow extends FlyingBird {
    Sparrow(String name) {
        super(name); // Calls FlyingBird's constructor
    }

    void eat() {
        System.out.println("Sparrows eat seeds and insects.");
    }

    void sleep() {
        System.out.println("Sparrows sleep in trees or bushes.");
    }

    void makeSound() {
        System.out.println("Sparrows chirp.");
    }

    void wingSpan() {
        System.out.println("Sparrows have a small wingspan.");
    }

    void habitat() {
        System.out.println("Sparrows are found in urban areas and gardens.");
    }
}

public class BirdTaxonomy {
    public static void main(String[] args) {
        Penguin penguin = new Penguin("Emperor Penguin");
        penguin.swim();
        penguin.eat();
        penguin.sleep();
        penguin.makeSound();
        penguin.wingSpan();
        penguin.habitat();
        System.out.println("-----------------");
        Sparrow sparrow = new Sparrow("House Sparrow");
        sparrow.eat();
        sparrow.sleep();
        sparrow.makeSound();
        sparrow.wingSpan();
        sparrow.habitat();
    }
}
