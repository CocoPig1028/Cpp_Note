//
//  main.cpp
//  mdCpp_1
//
//  Created by 박대영 on 12/20/23.
//

#include <iostream>
using namespace std;

//int change_val(int *p) {
//    *p = 3;
//
//    return 0;
//}
//
//int main() {
//    int number = 5;
//
//    cout << number << endl;
//    change_val(&number);
//    cout << number << endl;
//}

//int main() {
//    int a = 3;
//    int& another_a = a;
//
//    another_a = 5;
//    cout << "a: " << a << endl;
//    cout << "another_a: " << another_a << endl;
//
//    return 0;
//}

// int형 변수인 a를 정의하였고 그안에 3이라는 값을 넣어줌
// a의 참조자 another_a를 정의
// 참조자를 정하는 방법 타입 뒤에 &를 붙힌다.

// 참조자와 포인터는 상당히 유사한 개념
// 포인터 역시 다른 어떤 변수의 주소값을 보관함으로써 해당 변수에 간접적으로 연산 수행 가능

// 레퍼런스와 포인터의 차이
// 1. 레퍼런스는 정의 시에 반드시 누구의 별명인지 명시
// 레퍼런스
// int& another_a; -> 불가능
// 포인터
// int* p; -> 포인터는 가능

// 2. 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
// 레퍼런스
// int a = 10;
// int &another_a = a;
// int b = 3;
// another_a = b; -> 불가능
// 또한 &another_a = b; 도 안됨
// 포인터
// int a = 10;
// int* p = &a;
// int b = 3;
// p = &b; -> 가능

// 3. 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.
// 레퍼런스
// int a = 10;
// int &another_a = a;
// 내가 컴파일러라면 another_a를 위해 메모리 상에 공간 할당을 택하는 것 보다
// another_a를 a로 바꿔 번역
// 포인터
// int a = 10;
// int* p = &a;
// p는 메모리 상에서 당당히 8바이트를 차지하게 된다.

// * 함수 인자로 레퍼런스 받기 ( 메모리 상에 존재 )
//
//int change_val(int &p) {
//    // change_val(number)의 호출이기 때문에 int& p = number와 동일
//    p = 3;
//    // number = 3과 같은 작업
//
//    return 0;
//}
//
//int main() {
//    int number = 5;
//
//    cout << number << endl;
//    change_val(number);
//    cout << number << endl;
//}

// number를 change_val 안에 전달한 코드를 참조자를 이용해 바꿔본 코드
// int &p는 사실상 되지 않음
// int change_val(int &p) {}
// 이 부분은 change_val(nuber)로 호출할 때 이므로 사실상 int& p = number와 같음
// 포인터가 인자일 때와는 다르게 number 앞에 &를 붙일 필요가 없음
// int& a = b와 같이 한것과 일맥상통

//* 여러가지 참조자 예시
//int main() {
//    int x;
//    int& y = x; // y는 x의 또 다른 별명
//    int& z = y; // z는 x의 또 다른 별명
//    // 참조자의 참조자를 만드는 것은 문법상 금지
//    // 즉 같은 x를 참조하는 것이다.
//
//    x = 1;
//    cout << "x: " << x << " y: " << y << " z: " << z << endl;
//
//    y = 2;
//    cout << "x: " << x << " y: " << y << " z: " << z << endl;
//
//    z = 3;
//    cout << "x: " << x << " y: " << y << " z: " << z << endl;
//}

// cin << user_input;
// scanf("%d", &user_input);
// cin 이 레퍼런스로 user_input을 받아서 scanf와 같이 주소값을 전달해 줄 필요가 없음

//int main() {
//    int &ref = 4;
//
//    cout << ref << endl;
//}

// 상수는 리터럴이기 때문에 레퍼런스로 참조한는 것은 불가능
// 상수 참조자로 선언한다면 리터럴도 참조 가능
// const int &ref = 4;
// 이는
// int a = ref;
// a = 4와 동일하게 처리

//int main() {
//    int a, b;
//    int& arr[2] = {a, b};
//}

// 레퍼런스의 배열은 언어차원에서 불가능하다고 선언
// C++ 상에서 배열이 어떤식으로 처리되냐?
// 문법상 배열의 이름은 첫번째 원소의 주소값으로 변환이 될 수 있어야함
// 이때문에 arr[1] 과 같은 문장이 *(arr + 1)로 바뀌어서 처리될 수 있음
// 주소값이 존재한다는 의미는 해당 원소가 메모리 상에서 존재 -> 레퍼런스는 특별한 경우가 아닌 이상 메모리에서 공간을 차지 하지 않음
// 모순이기 때문에 언어 차원에서 금지

// 배열들의 레퍼런스
//int main() {
//    int arr[3] = {1, 2, 3};
//    int(&ref)[3] = arr;
//    // ref가 arr를 참조하도록 하였음
//    // ref[0]은 ref[0]을 참조, 이후도 같음
//    // 배열의 레퍼런스의 경우 참조하기 위해 배열의 크기를 명시하여야 함
//
//    ref[0] = 2;
//    ref[1] = 3;
//    ref[2] = 1;
//
//    cout << arr[0] << arr[1] << arr[2] << endl;
//
//    return 0;
//}

// 레퍼런스를 리턴하는 함수
//int function_1() {
//    int a = 2;
//    return a;
//}
//
//int main() {
//    int b = function_1(); //function_1의 a가 b에 저장
//    // function이 종료되고 나면 a는 메모리에서 사라지게 됨
//    // main 내에서는 a를 직접 만날 길이 없음
//    return 0;
//}

//int& function_1() {
//    int a = 2;
//    return a; //int& 이기 때문에 참조자를 리턴
//    // 문제는 리턴하는 function_1안에 정의되어있는 a는 함수의 리턴과 함께 사라짐
//}
//
//int main() {
//    int b = function_1();
//    b = 3;
//    return 0;
//}

// int& ref = a;
// int b = ref;
// 와 같은 꼴이지만 a가 사라져서 현재 별명만 남음
// 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심

// 외부 변수의 레퍼런스를 리턴
//int & function_1(int& a) {
//    a = 5;
//    return a;
//}
//
//int main() {
//    int b = 2;
//    int c = function_1(b);
//
//    cout << c << endl;
//    return 0;
//}
// function_1(b)를 실행한 시점에서 a는 main의 b를 참조하고 있게 된다.
// function_1이 리턴한 참조자는 아직 살아있는 변수 b를 계속 참조
// int c = function_1(b);
// 이는 그냥 c에 현재의 b의 값인 5를 대인하는 것과 동일한 문장이 된다.
// 참조자를 리턴하는 경우의 장점
// C언어에서 엄청나게 큰 구조체가 있을 때 해당 구조체 변수를 그냥 리턴하면 전체 복사가 발생해서 오래 걸림
// 해당 구조체를 가리키는 포인터를 리턴하면 그냥 포인터 주소 한번 복사로 매우 빠르게 끝남
// 마찬가지로 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관 없이 딱 한 번의 주소값 복사로 전달이 끝나게 된다.

// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
//int function_1() {
//    int a = 5;
//    return a;
//}
//
//int main() {
//    int& c = function_1();
//    return 0;
//}

// int& c = function_1();
// 함수의 리턴값은 해당 문장이 끝나면 사라지므로 참조자를 만들게 되면 바로 다음에 댕글링 레퍼런스가 되어버림
// int& c = funtion_1();
// c = 2;
// 위와 같은 작업을 하면 런타임 오류를 발생

// C++에서 중요한 예외 규칙이 있음
int function_1() {
    int a = 5;
    return a;
}

int main() {
    const int& c = function_1();
    cout << "c: " << c << endl;
    
    return 0;
}
// function_1의 리턴값을 참조자로 받았음
// const 참조자로 받았더니 문제없이 컴파일
// 리턴값도 정상적으로 출력
// 원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상
// int&로 받았을 때에는 컴파일 자체가 아노디었음
// 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 리턴값의 생명이 연장

// * 레퍼런스가 메모리에 존재하지 않아도 되는 경우
// 1. 레퍼런스가 함수 내에서 별칭으로만 쓰이는 경우, 컴파일러 내부 동작은 모르지만, 별칭을 replace하는 방식으로만 구현한다면 실제 메모리에 변수를 만들 필요가 없을듯

// * 메모리에 존재해야 하는 경우
// 1. 인자로 넘기는 경우, 해당 함수에서 지역변수가 되어야 하는데, 참조 대상의 주소값을 함수의 지역변수로 넘기는 일이 일어나면 메모리를 점유
// 2. 리턴값을 상수 참조자로 받는 경우, 상수 참조자는 상수는 리터럴이든 가리키는 대상이 있었어야 할텐데 없으니, 함수 내의 변수나 리터럴의 주소값을 가지는 식으로 메모리에 존재
