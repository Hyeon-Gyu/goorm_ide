//typedef은 별명만들기와 똑같다. typedef int speed_t; 라고 하면 int k; 와 speed k;는 같은 의미이다. _t는 접미사처럼 붙여주고 선언해야한다.

#include<iostream>

using namespace std;

struct Point{
	int xpos;
	int ypos;
	
	void MovePos(int x, int y){
		xpos += x;
		ypos += y;
	}
	
	void AddPoint(const Point &pos){
		xpos += pos.xpos;
		ypos += pos.ypos;
	}
	
	void ShowPosition(){
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};


int main(){
	Point pos1 = {12,4};
	Point pos2 = {20,30};
	
	pos1.MovePos(-7,10);
	pos1.ShowPosition();
	
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}