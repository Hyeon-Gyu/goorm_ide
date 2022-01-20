#include<iostream>

//함수의 인라인화
/*#define SQUARE(x) ((x) * (x)) -  매크로 함수 : 전처리기에 의해 처리

inline int SQURE(int x){
	return x*x;
}  // 컴파일러가 처리

*/
//namespace
namespace functioning1{
	void func();
}

namespace functioning2{
	void func();
}


using namespace std;

int main(){
//	cout << SQUARE(5) << endl;  
	functioning1::func();
	functioning2::func();

	return 0;
}

void functioning1::func(){
	cout << "functioning1함수" << endl;
}

void functioning2::func(){
	cout << "functioning2함수" << endl;
}
