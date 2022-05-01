//객체를 대상으로 하는 배열 클래스에 관한 코드

// 객체를 저장하는 배열 클래스 - 2. Point 객체의 주소를 저장하는 배열 기반의 클래스

//

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

 

typedef Point* POINT_PTR;

 

class BoundCheckPointPtrArray{

	private:

		POINT_PTR* arr;

		int arrlen;

		BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {} //복사생성자

		BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr){ return *this;} //대입연산자

	public:

		BoundCheckPointPtrArray(int len) : arrlen(len) {

			arr = new POINT_PTR[len]; // 객체의 주소들을 넣을 수 있는 객체기반 배열 생성

		}

		POINT_PTR& operator[] (int idx) {

			if(idx < 0 || idx >= arrlen){

				cout << "범위밖" << endl;

				exit(1);

			}

			return arr[idx];

		}

		POINT_PTR operator[] (int idx) const {

			if(idx < 0 || idx >= arrlen){

				cout << "범위밖" << endl;

				exit(1);

			}

			return arr[idx];

		}	

		int GetArrLen() const {return arrlen;}

		~BoundCheckPointPtrArray() {delete []arr;}

};

 

int main(){

	BoundCheckPointPtrArray arr(3);

	arr[0] = new Point(3,4);

	arr[1] = new Point(5,6);

	arr[2] = new Point(7,8);

	for(int i= 0; i < arr.GetArrLen(); i++){

		cout << *(arr[i]); //*없애면 주소값 볼 수 있음

	}

	delete arr[0];

	delete arr[1];

	delete arr[2];

	return 0;

}