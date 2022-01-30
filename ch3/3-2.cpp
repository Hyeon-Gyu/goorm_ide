// class 내에 변수들은 private으로 제한시키는 이유 -> 정보 은닉과 관련.
// 구조체 안에 enum을 사용해 상수들을 정의 시켜도 좋지만, 새로운 이름 공간을 만들어서 namespace Serial{enum{~~~}}으로 사용해요 된다. -> Serial::상수 명 이렇게 사용

//클래스를 구성하는 변수 = 멤버변수, 클래스를 구성하는 함수 = 멤버함수. 
//inline함수는 헤더파일에 넣기!

#include<iostream>

using namespace std;

class Calculator{
	private:
		int Add_count;
		int Div_count;
		int Min_count;
		int Mul_count;
	public:
		double Add(double num1, double num2);
		double Div(double num1, double num2);
		double Min(double num1, double num2);
		double Mul(double num1, double num2);
		void ShowOpcount();
		void Init();
		
};

void Calculator::Init(){//변수들에 int를 붙여서 재선언해버리면 값이 이상해짐..!!
	Add_count = 0;
	Div_count = 0;
	Min_count = 0;
	Mul_count = 0;	
}

double Calculator::Add(double num1, double num2){
	Add_count ++;
	return num1 + num2;;
}

double Calculator::Min(double num1, double num2){
	Min_count ++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2){
	Mul_count ++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2){
	Div_count = Div_count + 1;
	return num1 / num2;
}
void Calculator::ShowOpcount(){
	cout << " 덧셈 : " << Add_count << " 뺄셈 : " << Min_count << " 곱셈 : " << Mul_count << " 나눗셈 : " << Div_count << endl;
}
int main(){
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpcount();
	return 0;
}