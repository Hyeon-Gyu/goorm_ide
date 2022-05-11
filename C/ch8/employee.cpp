/* 상속성과 다형성 파트로 객체 포인터 변수, 모 클래스가 아들 클래스의 객체까지도 가리킬 수 있다는 점을 다루는 중이다*/

#include<iostream>
#include<cstring>

using namespace std;

class Employee{ //노동자
	private:
		char name[100];
	public:
		Employee(char* name){
			strcpy(this -> name, name);
		}
		void ShowYourName(){
			cout << "name: " << endl;
		}
};

class PermanentWorker : public Employee{ // 정규직
	private:
		int salary;
	public:
		PermanentWorker(char* name, int money) : Employee(name), salary(money){}
		int Getpay() const{
			return salary;
		}
		void ShowSalaryInfo() const {
			ShowYourName();
			cout << "salary: " << Getpay() << endl << endl;
		}
};


class TemporaryWorker : public Employee{
	private:
		int workTime;
		int payPerHour;
	public:
		TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
		void AddWorkTime(int time){
			workTime+= time;
		}
		int GetPay() const { //함수 오버라이딩: PermanentWorker클래스 getpay함수와 다른역할
			return workTime * payPerHour;
		}
		void ShowSalaryInfo() const{
			ShowYourName();
			cout<< "salary: " << GeyPay() << endl << endl;
		}
};

class SalesWorker : public PermanentWorker{
	private:
		int salesResult;
		double bonusRatio;
	public:
		SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(0) {}
		void AddSalesResult(int value){
			salesResult += value;
		}
		int Getpay() const {
			return PermanentWorker:: Getpay() + (int)(salesResult * bonusRatio);
		}
		void ShowSalaryInfo() const {
			ShowYourName();
			cout << "salary: " << Getpay() << endl << endl;
		}
}
class EmployeeHandler{
	private:
		Employee* empList[50];
		int empNum;
	public:
		EmployeeHandler() : empNum(0) {}
	 	void AddEmployee(Employee* emp){    // 여기서 Employee의 객체 주소값을 이용해 객체를 list에 저장한다. Employee 아들 클래스 permanent도 적용가능.!!
			empList[empNum++] = emp;
		}
		void ShowAllSalaryInfo() const{
			/*
			for(int i = 0; i < empNum; i++)
				empList[i] -> ShowSalaryInfo();
			*/
		}
	
		void ShowTotalSalary() const{
			int sum = 0;
			/* for(int i = 0; i < empNum; i++)
				sum += empList[i] -> Getpay();
			*/
		}
		~EmployeeHandler(){
			for(int i = 0; i < empNum; i++){
				delete empList[i];
			}
		}
};


int main(){
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("KIM", 1000)); //정규직
	handler.AddEmployee(new PermanentWorker("LEE", 1500)); //정규직
	handler.AddEmployee(new PermanentWorker("JUN", 2000)); //정규직
	
	TemporaryWorker* alba = new TemporaryWorker("JUNG", 700); //임시직
	alba -> AddWorkTime(5);
	handler.AddEmployee(alba);
	
	SalesWorker* seller = new SalesWorker("HONG", 1000, 0.1);
	seller -> AddSalesResult(7000);
	handler.AddEmployee(seller);
	
	handler.ShowAllSalaryInfo(); //총 급여 정보
	handler.ShowTotalSalary(); // 총 급여 지불 예정액수
	return 0;
}