#include<iostream>
//문제 1
using namespace std;


int BoxVolume(int num1, int num2, int num3){
	return num1 * num2 * num3;
}

int BoxVolume(int num1, int num2){
	return num1 * num2 * 1;
}

int BoxVolume(int num1){
	return num1 * 1 * 1;
}

int main(){

	cout << "[3, 3, 3]: " << BoxVolume(3, 3, 3) << std::endl;
	cout << "[5, 5, D]: " << BoxVolume(5, 5) << std::endl;
	cout << "[7, D, D]: " << BoxVolume(7) << std::endl;

	return 0;
}



//문제2
/* 매개변수 없이 SimpleFunc 함수를 호출하게 될 경우 두 함수 동시에 호출가능하기 때문에 에러가 날 것이다. 디폴트 값이 선언되어 있다고 하더라도 void 값을 호출할 경우 결국 두 매개변수 자리 모두 void를 의미하기 때문이다. */