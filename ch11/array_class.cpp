#include<iostream>
#include<cstdlib>

using namespace std;

class BoundCheckIntArray{
	private:
		int* arr;
		int arrlen;
	public:
		BoundCheckIntArray(int len) : arrlen(len){
			arr = new int [len];
		}
		int& operator[] (int idx){  // 일반적인 연산자 오버로딩과 동일하다. 리턴값으로 매개변수값을 넣은 배열 값을 한다면 보통의 배열과 다를게 없다. [] 사이에 숫자를 넣는 것이 아니라, [] 다음에 숫자가 있다는 점이 어색하긴 하다.
			if(idx<0 || idx >= arrlen){ // 객체명.operator[] (매개변수) 형태가 된다.
				cout<< "배열 범위 초과" << endl;
				exit(1);
			}
			return arr[idx];
		}
		~BoundCheckIntArray(){
			delete []arr;
		}
};

int main(){
	BoundCheckIntArray arr(5);
	for(int i = 0; i < 5; i++){
		arr[i] = (i+1)*11;
	}
	for(int i = 0; i < 6; i++){
		cout << arr[i] << endl;
	}
	return 0;
}