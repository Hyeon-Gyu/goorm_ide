#include<iostream>

using namespace std;

class Point{
	private:
		int xpos, ypos;
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
};

template <typename T>
T SwapData(T& data1, T& data2){
	T tmp;
	tmp = data1;
	data1 = data2;
	data2 = tmp;
	return 0;
}

int main(){
	Point p1(1,1);
	Point p2(2,2);
	SwapData(p1,p2);
	p1.ShowPosition();
	p2.ShowPosition();
}