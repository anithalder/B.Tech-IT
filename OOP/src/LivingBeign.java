interface LivingBeing {
    void eat();

    void sleep();

    void reproduce();
}

interface Animal extends LivingBeing {
    void communicate();

    void move();
}

abstract class Bird implements Animal {
    protected String species;

    public Bird(String species) {
        this.species = species;
    }

    public void move() {
        System.out.println(species + " moves like a bird");
    }

    abstract void fly();
}

class Reptile implements Animal {
    protected String species;

    public Reptile(String species) {
        this.species = species;
    }

    public void move() {
        System.out.println(species + " moves like a reptile");
    }

    public void swim() {
        System.out.println(species + " swims in water");
    }

    public void communicate() {
        System.out.println(species + " communicates with hisses");
    }

    public void eat() {
        System.out.println(species + " eats meat or plants");
    }

    public void sleep() {
        System.out.println(species + " sleeps in a den or burrow");
    }

    public void reproduce() {
        System.out.println(species + " lays eggs or gives birth to live young");
    }
}

class Crocodile extends Reptile {
    public Crocodile(String string) {
        super(string);
    }

    public void swim() {
        System.out.println(species + " swims in water");
    }

    public void communicate() {
        System.out.println(species + " communicates with growls");
    }
}

class Eagle extends Bird {
    public Eagle(String string) {
        super(string);
    }

    void fly() {
        System.out.println(species + " flies high");
    }

    public void communicate() {
        System.out.println(species + " screeches");
    }

    public void eat() {
        System.out.println(species + " eats prey");
    }

    public void sleep() {
        System.out.println(species + " sleeps in nest");
    }

    public void reproduce() {
        System.out.println(species + " lays eggs");
    }
}
