#include<iostream>
#include<cstring>

using namespace std;

int main(){
	string str1 = " i like" ;
	string str2 = " string class";
	string str3 = str1 + str2;
	
	cout << str1 << endl;
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
	cout << "입력하시오:" << endl;
	cin >> str4;
	cout << "입력한 문자열 :" << str4 << endl;
	return 0;
}