public class GeoArea {
    private double length, width, side, radius;
    private static final double PI = 3.14159;

    public void setLength(double length) {
        this.length = length;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public void setSide(double side) {
        this.side = side;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double rectangleArea() {
        return length * width;
    }

    public double squareArea() {
        return side * side;
    }

    public double circleArea() {
        return PI * radius * radius;
    }
}
