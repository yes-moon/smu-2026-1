// 클래스 Rectangle: 너비, 높이를 가지고 IShape을 구현
class Rectangle implements IShape {
    protected double width;
    protected double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double getArea() {
        return width * height;
    }

    @Override
    public double getPerimeter() {
        return 2 * (width + height);
    }

    @Override
    public String toString() {
        return String.format("사각형 - 너비: %.2f, 높이: %.2f, 둘레: %.2f, 너비: %.2f",
                width, height, getPerimeter(), getArea());
    }
}
