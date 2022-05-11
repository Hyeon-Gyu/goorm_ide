/*
static_cast<T>(expn)
아들에서 부모로 형 변환 시키는건 원래 허용이지만, 부모에서 아들로 형 변환시키는걸 아무조건 없이 허용해줄게. 대신 책임은 너가 져!
*/

#include<iostream>
using namespace std;

class Car{
	private:
		int fuelGauge;
	public:
		Car(int fuel) : fuelGauge(fuel) {}
		void ShowCarState(){cout << "잔여 연료랑: " << fuelGauge<< endl;}
};

class Truck : public Car{
	private:
		int freightWeight;
	public:
		Truck(int fuel, int weight) : Car(fuel) , freightWeight(weight) {}
		void ShowTruckState(){cout << "화물의 무게" << freightWeight << endl;}
};

int main(){
	Car *pcar1 = new Truck(80,200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1); //컴파일 가능
	ptruck1 -> ShowTruckState();
	
	Car *pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2); // 컴파일은 가능... 문법을 거스르는 일.. 결과는 어떻게 나올지 모름!
	ptruck2 -> ShowTruckState();
	return 0;

}