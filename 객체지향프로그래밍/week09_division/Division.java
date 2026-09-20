//Division.java
public class Division {
    // 정수 나눗셈
    public int divide(int a, int b) {
        if (b == 0) {
            System.out.println("오류: 0으로 나눌 수 없습니다.");
            return 0;
        }
        System.out.println("divide(int, int) 호출됨");
        return a / b;
    }
    
    // 실수 나눗셈
    public double divide(double a, double b) {
        if (b == 0.0) {
            System.out.println("오류: 0으로 나눌 수 없습니다.");
            return 0.0;
        }
        System.out.println("divide(double, double) 호출됨");
        return a / b;
    }
    
    // 정수 3개 나눗셈
    public int divide(int a, int b, int c) {
        if (b == 0 || c == 0) {
            System.out.println("오류: 0으로 나눌 수 없습니다.");
            return 0;
        }
        System.out.println("divide(int, int, int) 호출됨");
        return a / b / c;
    }
    
    // 문자열 나눗셈
    public double divide(String a, String b) {
        try {
            double numA = Double.parseDouble(a);
            double numB = Double.parseDouble(b);
            if (numB == 0.0) {
                System.out.println("오류: 0으로 나눌 수 없습니다.");
                return 0.0;
            }
            System.out.println("divide(String, String) 호출됨");
            return numA / numB;
        } catch (NumberFormatException e) {
            System.out.println("오류: 문자열을 숫자로 변환할 수 없습니다.");
            return 0.0;
        }
    }
    
    public static void main(String[] args) {
        Division calc = new Division();
        
        System.out.println("결과: " + calc.divide(10, 2));
        System.out.println("결과: " + calc.divide(10, 0));
        System.out.println("결과: " + calc.divide(9.0, 3.0));
        System.out.println("결과: " + calc.divide(9.0, 0.0));
        System.out.println("결과: " + calc.divide(20, 5, 2));
        System.out.println("결과: " + calc.divide("20", "4"));
        System.out.println("결과: " + calc.divide("9", "0"));
        System.out.println("결과: " + calc.divide("smu", "2"));
    }
}
