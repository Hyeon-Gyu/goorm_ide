//객체를 대상으로 하는 배열 클래스에 관한 코드

// 객체를 저장하는 배열 클래스 - 1. Point 객체를 저장하는 배열 기반의 클래스

 

#include<iostream>

#include<cstdlib>

 

using namespace std;

 

class Point{

	private:

		int xpos, ypos;

	public:

		Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

		friend ostream& operator<<(ostream& os, const Point& pos);

}; 

 

ostream& operator<< (ostream& os, const Point& pos){

	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;

	return os;

}

 

class BoundCheckPointArray{

	private:

		Point* arr;

		int arrlen;

		BoundCheckPointArray(const BoundCheckPointArray& arr) {} //복사생성자

		BoundCheckPointArray& operator=(const BoundCheckPointArray& arr){ return *this;} //대입연산자

	public:

		BoundCheckPointArray(int len) : arrlen(len) {

			arr = new Point[len]; // 객체들을 넣을 수 있는 객체기반 배열 생성

		}

		Point& operator[] (int idx) {

			if(idx < 0 || idx >= arrlen){

				cout << "범위밖" << endl;

				exit(1);

			}

			return arr[idx];

		}

		Point& operator[] (int idx) const {

			if(idx < 0 || idx >= arrlen){

				cout << "범위밖" << endl;

				exit(1);

			}

			return arr[idx];

		}	

		int GetArrLen() const {return arrlen;}

		~BoundCheckPointArray() {delete []arr;}

};

 

int main(){

	BoundCheckPointArray arr(3);

	arr[0] = Point(3,4);

	arr[1] = Point(5,6);

	arr[2] = Point(7,8);

	for(int i= 0; i < arr.GetArrLen(); i++){

		cout << arr[i] << endl;

	}

	return 0;

}