# 2학년 1학기 (2026-1)

상명대학교 휴먼AI공학전공 2학년 1학기 수업의 실습 코드와 과제입니다.
강의자료와 교수님이 배포한 코드는 저작권 문제로 포함하지 않았습니다. 여기 있는 것은 **직접 작성한 코드**이며, 전부 컴파일·실행을 확인했습니다.

## 과목

| 과목 | 내용 | 도구 |
|---|---|---|
| [자료구조](자료구조/) | 배열 리스트 · 선형/원형 큐 · 이차 조사 해싱 · 트라이 · 블룸 필터를 C로 직접 구현 | C (MSVC) |
| [객체지향프로그래밍](객체지향프로그래밍/) | 오버로딩 · 클래스 설계 · 패키지 · 인터페이스 과제 5개 | Java 21 |
| [데이터분석](데이터분석/) | pandas · matplotlib 시각화, 통계적 추론 실습 노트북 | Python, Colab |
| 인터랙션디자인 | 기말 프로젝트 — Unity 3인칭 보스 레이드 게임 | → [**dragon-slayer-arena**](https://github.com/yes-moon/dragon-slayer-arena) |

## 자료구조

메뉴 기반 콘솔 프로그램으로, 각 자료구조의 연산을 직접 구현하고 손으로 검증했다.

| 파일 | 구현 내용 |
|---|---|
| `array_list/array_list.c` | 고정 크기 배열 리스트 — get / traverse / search / update / insert(뒤로 밀기) / delete(앞으로 당기기) |
| `array_list_top/list_with_top.c` | `top` 인덱스로 끝을 관리하는 배열 리스트 — 삽입·삭제 시 요소 이동, 탐색·갱신 |
| `circular_queue/linear_queue_v1.c`, `_v2.c` | 선형 큐 두 가지 (front=-1 방식, front=0 방식) |
| `circular_queue/circular_queue.c` | 큐 — rear가 끝에 닿으면 요소를 앞으로 당겨 공간을 재사용(shift 방식), 빈/가득 참 판별 |
| `hashing/quadratic_probing.c` | 개방 주소법 — 이차 조사(quadratic probing), DELETED 마커로 삭제 후 탐색 유지 |
| `trie/trie_alphabet.c` | 알파벳 트라이 — 삽입 / 검색 / 재귀 삭제(자식 없는 노드 정리), 동적 할당 노드 |
| `bloom_filter/bloom_filter.c` | 블룸 필터 — 해시 함수 2개 `(a·x + b) mod 11`로 비트 배열 세팅, 거짓 양성 예시 |

```bash
cl /W3 /utf-8 자료구조\circular_queue\circular_queue.c && circular_queue.exe   # MSVC
gcc -o cq 자료구조/circular_queue/circular_queue.c && ./cq                     # gcc
```

## 객체지향프로그래밍

Colab에서 `%%writefile` + `javac`로 작성한 과제를 `.java` 파일로 정리했다. 각 폴더의 `notebook.ipynb`가 원본.

| 폴더 | 주제 |
|---|---|
| `week09_division` | 메서드 오버로딩 — `divide(int,int)` / `divide(double,double)`, 0 나누기 예외 처리 |
| `week10_dice` | `Dice` 클래스와 시뮬레이션 — 100회 굴려 눈별 확률 계산 |
| `week11_dice_probability` | 클래스 분리 — `Dice` / `DiceProbability` / 테스트 클래스 |
| `week12_hello_package` | 패키지 구조 `com.my.myApp` ↔ `com.your.hello`, import와 접근 제어 |
| `week13_ishape_interface` | `IShape` 인터페이스를 구현한 `Rectangle` / `Circle`, 다형성으로 면적·둘레 출력 |

```bash
javac -encoding UTF-8 -d out 객체지향프로그래밍/week13_ishape_interface/*.java && java -cp out ShapeTest
```

## 데이터분석

『혼자 공부하는 데이터 분석』 교재의 도서관 대출 데이터(`ns_book7.csv`)를 사용한 실습. 출력물은 용량 때문에 비웠으니 Colab에서 열어 실행하면 된다.

| 노트북 | 내용 |
|---|---|
| `week11_matplotlib_basics` | 산점도, figure 크기·DPI, `rcParams`, 마커/색상 옵션 |
| `week14_matplotlib_api` | pyplot 방식 vs 객체지향 API, 한글 폰트, 출판사별 발행 연도 산점도 |
| `week15_bar_pie_charts` | 막대·누적 막대·원 그래프, 한 화면에 여러 그래프 |
| `week16_statistical_inference` | z 점수·신뢰구간, 중심극한정리, 모수 추정 |
