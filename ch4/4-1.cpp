//사과 구매를 목적으로 0보다 작은 수를 전달할 수 없다 는 조건을 유지할 수 있는 장치 마련하기.

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