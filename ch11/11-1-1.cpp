#include<iostream>
#include<cstring>

using namespace std;

class Gun{
	private:
		int bullet;
	public:
		Gun(int bnum) : bullet(bnum){}
		void Shot(){
			cout << "Bang" << endl;
			bullet --;
		}
	
};

class Police{
	private:
		int handcuffs;
		Gun* pistol;
	public:
		Police(int bnum, int bcuff) : handcuffs(bcuff){ //디폴트 생성자
			if(bnum > 0 ) 
				pistol = new Gun(bnum);
			else
				pistol = NULL;
		}
		Police(const Police& rhs){
			cout <<"복사생성자 사용" << endl;
			this -> handcuffs = rhs.handcuffs;
			this -> pistol = rhs.pistol;			
		}
		void PutHandCuff(){
			cout << "SNAP" << endl;
			handcuffs--;
		}
		void Shot(){
			if(pistol == NULL){
				cout << "Hut Bang" << endl;
			}
			else
				pistol -> Shot();
		}
		~Police(){
			if(pistol!= NULL)
				delete pistol;
		}
	
		Police& operator=(const Police& ref){
			cout << "대입연산자 사용" << endl;
			handcuffs = ref.handcuffs;
			pistol = ref.pistol;
			return *this;
		}
};	
/*
Police::Police(const Police& rhs){ // 복사생성자
	cout <<"복사생성자 사용" << endl;
	this -> handcuffs = rhs.handcuffs;
	this -> pistol = rhs.pistol;
}
*/
int main(){
	Police officer(10,5);
	Police man(0,0);
	Police man2(0,0);
	man = officer;
	
	officer(man2);
	
}