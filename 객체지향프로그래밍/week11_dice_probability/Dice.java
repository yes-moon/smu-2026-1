// 클래스1: 주사위 (주10에서 구현한 것 재사용)
class Dice {
    // 주사위를 굴려서 1~6 사이의 정수를 반환
    public int roll() {
        return (int)(Math.floor(Math.random() * 6)) + 1;
    }
}
