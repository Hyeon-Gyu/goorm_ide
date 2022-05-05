#include<iostream>
#include<cstring>

using namespace std;

class String{
	private:
		int len;
		char* str;
	public:
		String(){
			len = 0;
			str = NULL;
		}
		String(char* ans){
			len = sizeof(ans) + 1;
			str = new char[len];
			strcpy(str, ans);
		}
		String(String& s){
			len = s.len;
			str = new char[len];
			strcpy(str,s.str);
		}
		~String(){
			delete []str;
		}
		String operator+ (String& s);
		String& operator+= (String& s); //str1 = str1 + str2 => str1.operator+=(str2) 결과로 str1값 변경하기
		String& operator==(String& s);
		String& operator=(String& s);
		friend ostream& operator <<(ostream& os, String& s);
		friend istream& operator >>(istream& is, String& s);
		
};

String& String::operator=(String& s){
	len = s.len;
	str = new char[len];
	strcpy(str,s.str);
	return *this;
}

String String::operator+(String& s){ // str3 = str1 + str2 -> str1.operator+(str2)을 str3에 대입하는 방식
	char* tmp = new char[len+s.len-1]; // null 길이가 두번 측정됨
	strcpy(tmp, str);
	strcat(tmp, s.str); //두 문자열 붙이기 결과로 str1+str2
	
	String tmp2(tmp);
	delete []tmp;
	return tmp2;
}

String& String::operator+=(String& s){
	len +=(s.len-1);
	char* tmp = new char[len];
	strcpy(tmp, str);
	strcat(tmp, s.str);
	str = tmp; // 굳이 이렇게 덮어써야하나..? 그냥 strcat(str,s.str)하면 끝인데..? str1은 값이 바뀌니까 이전 값도 필요없고..
	//배열은 한번 선언한 이후부턴 길이 확장이 안되기 때문에 새로 선언해서 값을 입력한 후 덮어씌우기
	//strcpy(str,s.str);
	return *this;
}

bool String::operator==(String& s){
	return strcmp(str, s.str) ? false : true;
}

ostream& operator << (ostream& os, String& s){
	os << s.str;
	return os;
}

istream& operator >> (istream& is, String& s){
	char str[100];
	is >> str;
	s = String(str);
	return is;
}