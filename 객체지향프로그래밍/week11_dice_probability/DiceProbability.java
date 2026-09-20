// 클래스2: 확률 클래스 (Dice 클래스를 의존관계로 사용)
class DiceProbability {
    private int num;              // 주사위를 던질 횟수
    private int[] counts;         // 1~6 각각 나온 횟수
    private double[] probabilities; // 1~6 각각의 확률
    private Dice dice;            // Dice 객체 (의존관계)

    // 생성자 오버로딩 1: 기본 생성자 (기본 100회)
    public DiceProbability() {
        this.num = 100;
        init();
    }

    // 생성자 오버로딩 2: 횟수 n을 인자로 받는 생성자
    public DiceProbability(int n) {
        this.num = n;
        init();
    }

    // 변수 초기화 함수
    public void init() {
        dice = new Dice();
        counts = new int[6];
        probabilities = new double[6];
        for (int i = 0; i < 6; i++) {
            counts[i] = 0;
            probabilities[i] = 0.0;
        }
    }

    // 확률 계산 함수 (배열에 저장)
    public void calcProbability() {
        // 주사위 num번 던지기 → 조건문 없이 배열 인덱싱으로 카운트
        for (int i = 0; i < num; i++) {
            int result = dice.roll();
            counts[result - 1]++;
        }
        // 각 면의 확률 계산
        for (int i = 0; i < 6; i++) {
            probabilities[i] = (double) counts[i] / num;
        }
    }

    // 확률 화면 출력 함수
    public void printProbability() {
        System.out.println("Total round: " + num);
        for (int i = 0; i < 6; i++) {
            System.out.printf("Dice %d: %d Probability: %.3f%n", i + 1, counts[i], probabilities[i]);
        }
    }
}
