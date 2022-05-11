
//heap 영역에 동적할당하는 방법 c언어에서는 malloc,free를 썼다면 c++에서는 new,delete를 사용한다.

/*  int* ptr1 = new int;
	double* ptr2 = new double;
	int* arr1 = new int[3];
	double* arr2 = new double[20]; */

//char* str = (char*)malloc((char)*len);       char* str = new arr[len];

//동적할당되어 힙에 할당된 변수도 포인터 말고 참조자로 접근할 수 있다!

/* 
int* ptr = new int;
int* &ref = *ptr;
ref = 20;
cout << *ptr << endl; 출력결과 20
*/

#include<iostream>

using namespace std;

typedef struct __Point{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2){
	Point* ptr3 = new Point;	
	ptr3 -> xpos = p1.xpos + p2.xpos;
	ptr3 -> ypos = p1.ypos + p2.ypos;
	return *ptr3;
}

int main(){
	Point* ptr1 = new Point;
	Point* ptr2 = new Point;

	ptr1 -> xpos = 5; ptr1 -> ypos = 5;
	ptr2 -> xpos = 10; ptr2 -> ypos = 10;
	Point &ref = PntAdder(*ptr1, *ptr2);
	cout << ref.xpos << ' ' << ref.ypos << endl;
	delete ptr1;
	delete ptr2;
//	delete ptr3;
	delete &ref;
	return 0;
}
