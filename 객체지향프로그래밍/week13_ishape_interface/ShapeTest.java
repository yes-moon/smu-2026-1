// 메인 클래스
class ShapeTest {
    public static void main(String[] args) {
        // 원: 반지름 3
        Circle circle = new Circle(3);
        // 사각형: 너비 5, 높이 10
        Rectangle rectangle = new Rectangle(5, 10);

        // toString() 오버라이드 결과 출력
        System.out.println(circle);
        System.out.println(rectangle);
    }
}
