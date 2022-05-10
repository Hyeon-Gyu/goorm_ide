//보통은 예외사항이 보이면 if를 써서 제외시키는 편이다. 하지만 이번 장에선 try,catch,throw를 활용할 예정이다.

try{
	//예외 발생 지역
}
catch{
	//try블록에서 발생한 예외를 처리하는 코드가 담기는 곳
}

//try와 catch는 하나의 문장이므로, 항상 이어서 등장해야한다. 중간에 다른 문구가 와서도 안된다!

throw expn;
//throw는 예외가 발생했음을 알리는 문장의 구성에 사용된다.
//expn는 보통 예외객체, 예외 데이터라고 불린다.

#include<iostream>
using namespace std;

int main(){
	int n1,n2;
	cout << "두개 숫자 입력:" << endl;
	cin >> n1 >> n2;
	
	try{
		if(n2 == 0)
			throw n2;
		cout << "나눗샘의 몫:" << n1/n2 << endl;
		cout << "나눗셈의 나머지:" << n1%n2 << endl;
	}
	catch(int expn){
		cout << "제수는 " << expn << "이 될 수 없음!"  << endl;
		cout << "restart" << endl;
	}
	cout << "end of main" << endl;
	return 0;
}