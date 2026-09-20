class DiceTest {
    public static void main(String[] args) {
        int totalRound = 100;
        Dice dice = new Dice();
        int[] counts = new int[6];  // 1~6 각각 나온 횟수 저장

        // 주사위 100회 굴리기
        for (int i = 0; i < totalRound; i++) {
            int result = dice.roll();
            counts[result - 1]++;
        }

        // 결과 출력
        System.out.println("Total round: " + totalRound);
        for (int i = 0; i < 6; i++) {
            double probability = (double) counts[i] / totalRound;
            System.out.printf("Dice %d: %d Probability: %.3f%n", i + 1, counts[i], probability);
        }
    }
}
