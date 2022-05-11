/*
dynamic_cast<T>(expn)
<>사이에는 변환하고자 하는 자료형의 이름을 두되,
객체의 포인터 또는 참조형 이어야하며
() 사이에는 변환의 대상이 와야한다.
요구한 형 변환이 적절하면 변환된 데이터를 반환하지만,
적절하지 않다면 컴파일 에러를 발생시킴 => 안전한 형변환

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
	Truck* ptruck1 = dynamic_cast<Truck*>(pcar1); // 컴파일 에러
	Car *pcar2 = new Car(120);
	Truck* ptruck2 = dynamic_cast<Truck*>(pcar2); // 컴파일 에러
	Truck *ptruck3 = new Truck(70,150);
	Car* ptruck3 = dynamic_cast<Car*>(ptruck3); // 컴파일 가능
}

// 상속 관계에 있는 유도클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환 만 가능. 즉 아들에서 부모로 형 변환 가능!