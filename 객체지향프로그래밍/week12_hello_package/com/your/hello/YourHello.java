// 클래스1: YourHello (com.your.hello 패키지)
package com.your.hello;

public class YourHello {
    String toWhom = "world";

    // 기본 생성자
    public YourHello() {
    }

    // 인사할 대상을 인자로 받는 생성자
    public YourHello(String toWhom) {
        this.toWhom = toWhom;
    }

    // 인사 출력 함수
    public void sayHello() {
        System.out.printf("hello %s", toWhom);
    }
}
