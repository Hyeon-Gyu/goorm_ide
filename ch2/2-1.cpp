/* call by reference에는 종류가 두가지가 있다. 참조자를 이용한 call by reference와 주소 값을 이용한 call by reference가 있다.
주소 값을 이용할 경우 swap(int *ptr1, int *ptr2) 와 같이 매개변수를 주소값을 받는 방식을 이용한다. 
반대로 참조값을 이용할 경우 swap(int &val1, int &val2)와 같이 매개변수에 참조값을 기입한다. 이 방식으로 함수를 호출하게 되면 기존의 변수명에 한가지 이름 val1이 생기게 되는 것이다.*/

//Q1.
/*
#include<iostream>

using namespace std;

//인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
void func1(int& val1){
	val1++;
}
//인자로 전달된 int형 변수의 부호를 바꾸는 함수
void func2(int& val2){
	val2 = -val2;
}

int main(){
	int num1 = 10;
	int num2 = -5;
	func1(num1);
	func2(num2);
	cout << num1 << ' ' << num2 << endl;
}
*/

//Q2.
/*
참조값은 선언된 변수에만 붙여줄 수 있다. 숫자에는 붙여줄 수 없다.
*/

//Q3.
#include<iostream>

using namespace std;

void SwapPointer(int* (&ref1), int* (&ref2)){
	//int *(&ref1) = ptr1; 여기서 참조값 선언하면 함수 종료와 동시에 초기화됨.. 
	//int *(&ref2) = ptr2;
	int *ptr = ref1; //ptr1의 num1을 가리키는 주소 저장
	ref1 = ref2;
	ref2 = ptr;
}

int main(){
	int num1 = 5;
	int *ptr1=&num1;
	
	int num2 = 10;
	int *ptr2=&num2;
	
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	
	SwapPointer(ptr1,ptr2);
	
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	return 0;
}

