// 클래스2: Main (com.my.myApp 패키지) - YourHello 클래스를 사용
package com.my.myApp;

import com.your.hello.YourHello;

public class Main {
    public static void main(String[] args) {
        // 자신의 이름을 인자로 YourHello 객체 생성
        YourHello hm = new YourHello("");
        hm.sayHello();
    }
}
