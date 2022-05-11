#include<iostream>
#include<cstring>
using namespace std;

class first{
	private:
		char * strOne;
	public:
		first(char* str){
			strOne = new char [strlen(str) + 1];
		}
		virtual ~first(){
			cout << "~first()" << endl;
			delete []strOne;
		}
};

class second{
	private:
		char* strTwo;
	public:
		second(char* str1, char* str2): first(str1){
			strTwo = new char [strlen(str2) + 1];
		}
		~second(){
			cout <<"~second()" << endl;
			delete []strTwo;
		}
};

int main(){
	first* ptr = new second("simple", "complex");
	delete ptr;
	return 0;
}