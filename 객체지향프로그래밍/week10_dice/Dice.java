class Dice {
    // 주사위를 굴려서 1~6 사이의 정수를 반환
    public int roll() {
        return (int)(Math.floor(Math.random() * 6)) + 1;
    }
}
