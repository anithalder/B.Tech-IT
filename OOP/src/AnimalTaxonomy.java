public class AnimalTaxonomy {
    public static void main(String[] args) {
        // Create instances of each animal
        Eagle eagle = new Eagle("Bald Eagle");
        Crocodile crocodile = new Crocodile("Nile Crocodile");

        // Demonstrate Eagle behaviors
        System.out.println("\nEagle Behaviors:");
        eagle.eat();
        eagle.sleep();
        eagle.reproduce();
        eagle.move();
        eagle.fly();
        eagle.communicate();

        // Demonstrate Crocodile behaviors
        System.out.println("\nCrocodile Behaviors:");
        crocodile.eat();
        crocodile.sleep();
        crocodile.reproduce();
        crocodile.move();
        crocodile.swim();
        crocodile.communicate();
    }
}
