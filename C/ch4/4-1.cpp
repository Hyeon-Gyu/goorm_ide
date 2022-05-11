//사과 구매를 목적으로 0보다 작은 수를 전달할 수 없다 는 조건을 유지할 수 있는 장치 마련하기.

//멤버함수 ex) int GetX() const; 처럼 선언할 경우 이 함수 내에서는 멤버변수를 변경하지 않겠다는 의미로 선언됨. const의 중요성!
//const함수 내에서 const 함수가 아닌 함수는 호출이 제한되며 컴파일에러가 뜬다!

#include<iostream>

using namespace std;

class FruitSeller{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
	public:
		void InitMembers(int price, int num, int money){
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = money;
		}
		int SaleApples(int money){
			int num = money/APPLE_PRICE;
			if(num <= 0){                                     // 추가된 문장 
				return false;
			}
			numOfApples -= num;
			myMoney += money;
			return num;
		}
		void ShowSalesResult(){
			cout << "남은 사과: " << numOfApples << endl;
			cout << "판매 수익: " << myMoney << endl;
		}
};

class FruitBuyer{
	int myMoney;
	int numOfApples;
	public:
		void InitMembers(int money){
			myMoney = money;
			numOfApples = 0;
		}
		void BuyApples(FruitSeller &seller, int money){
			numOfApples += seller.SaleApples(money);
			myMoney -= money;
		}
		void ShowBuyResult(){
			cout << "현재 잔액: " << myMoney << endl;
			cout << "사과 개수: " << numOfApples << endl;
		}
};