#include<iostream>

using namespace std;

class Point{
	private:
		int xpos, ypos;
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y){}
		void ShowPosition() {
			cout << '[' << xpos << "," << ypos << ']' << endl;
		}
		Point& operator++(){
			xpos += 1;
			ypos += 1;
			return *this;
		}
		friend Point& operator--(Point& ref);
	
		Point operator-(){
			Point pos(-xpos, -ypos);
			return pos;
		}
	
		Point operator~(){
			Point pos(ypos, xpos);
			return pos;
		}
};
/*
Point& operator-- (Point& ref){
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

*/

int main(){
	Point pos(1,2);
	Point pos1(5,10);
	Point pos2;
	++pos;
	pos.ShowPosition();
/*
	--pos;
	pos.ShowPosition();
	
	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
*/	
	pos2 = ~pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}