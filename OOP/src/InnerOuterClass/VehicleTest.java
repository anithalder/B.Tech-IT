abstract class Vehicle {
    public abstract void vehicleType();
}

class VehicleTest {
    public static void main(String[] args) {
        // Using anonymous inner classes
        Vehicle car = new Vehicle() {
            @Override
            public void vehicleType() {
                System.out.println("This is a car.");
            }
        };

        Vehicle bike = new Vehicle() {
            @Override
            public void vehicleType() {
                System.out.println("This is a bike.");
            }
        };

        car.vehicleType();
        bike.vehicleType();
    }
}