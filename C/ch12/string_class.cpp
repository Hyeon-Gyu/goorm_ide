#include<iostream>
#include<cstring>

using namespace std;

int main(){
	string str1 = " i like" ;
	string str2 = " string class";
	string str3 = str1 + str2; // string 클래스끼리는 덧셈연산 가능( + 연산자 오버로딩으로 인해서)
	
	cout << str1 << endl; // <<연산자 오버로딩 적용됨
	cout << str2 << endl;
	cout << str3 << endl;
	
	str1 += str2;
	if(str1 == str3){
		cout << "동일 문자열" << endl;
	}
	else{
		cout << "불일치" << endl;
	}
	string str4;
	cout << "입력하시오:";
	cin >> str4; // >>연산자 오버로딩 적용
	cout << "입력한 문자열 :" << str4 << endl;
	return 0;
}