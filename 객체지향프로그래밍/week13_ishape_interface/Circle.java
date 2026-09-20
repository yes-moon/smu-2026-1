// 클래스 Circle: 반지름을 가지고 IShape을 구현
class Circle implements IShape {
    protected double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public String toString() {
        return String.format("원 - 반지름: %.2f, 둘레: %.2f, 너비: %.2f",
                radius, getPerimeter(), getArea());
    }
}
