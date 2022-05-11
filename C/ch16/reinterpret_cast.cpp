/* 
포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용함

reinterpret_cast<T>(expn)

전혀 연관성 없고 상속 관계도 아닌 두 클래스를 위 변환을 사용한다면 컴파일 에러 없이 가능하다. 하지만 값은 기대 못한다..

보통은 주소값을 가진 ptr를 출력하고 이를 다시 정수로 되돌리고 싶을 때 사용한다.

*/

#include<iostream>
using namespace std;

int main(){
	int num = 72;
	int* ptr = &num;
	
	int Adr = reinterpret_cast<int>(ptr); //주소값을 정수로 변환
	cout << "Adr: " << Adr << endl;
	
	int* rptr = reinterpret_cast<int*>(Adr); //정수를 다시 주소값으로 변경
	cout << "Value :" << *rptr << endl;
	return 0;
}