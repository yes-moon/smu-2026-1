// Main 클래스
class DiceProbabilityTest {
    public static void main(String[] args) {
        // 주사위를 100회 던지는 확률 객체 생성
        DiceProbability dp = new DiceProbability(100);
        dp.calcProbability();
        dp.printProbability();
    }
}
