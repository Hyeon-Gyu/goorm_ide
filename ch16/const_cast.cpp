#include<iostream>
using namespace std;
 // const_cast<T>(expn)
//const의 의미를 해제시키는 형 변환

void ShowString(char* str){
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2){
	cout << n1+n2 << endl;
}

int main(){
	const char* name = "lim hyeon gyu";
	ShowString(const_cast<char*>(name)); //name은 const 이지만 str은 const가 아니다. 원래는 인자로 값을 전달못하지만 const cast로 해제시켰기 때문에 전달 가능
	
	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2)); // 16번줄과 같이 const의 의미를 해제시킴
	return 0;
}