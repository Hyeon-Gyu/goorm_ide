// using namespace std; 의 의미

/* 이름 공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략"을 명령하는 것 
원래 같으면 using std::cout, using std::endl; 처럼 iostream 헤더파일 안에 있는 std 이름 공간에 있는 함수들을 일일이 불러오면서 선언해야했지만 그게 이제는 아니다. 
*/



#include<iostream>
#include<cstring>
int init_menu();
void make_account();
void deposit();
void withdraw();
void print_all();

using namespace std;

enum switch_choice {m_account = 1, depo,with,print,close}; 

typedef struct inf{
	int ID;
	char name[10];
	int money;
}inform;	

inform account[10];
int account_num = 0;

int main(){
	
	while(1){
		int choice = 0;
		choice = init_menu();
		
		switch(choice){
			case m_account:
				make_account();
				break;
			case depo:
				deposit();
				break;
			case with:
				withdraw();
				break;
			case print:
				print_all();
				break;
			case close:
				return 0;
			default:
				cout <<"you choose a wrong number!" << endl;
				
		}
	}
	return 0;
}


int init_menu(){
	int ans = 0;
	cout << "-----Menu-----"<< endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
	cin >> ans;
	return ans;
}

void make_account(){
	int id;
	char name[10];
	int money;
	
	cout << "[계좌개설] " << endl;
	cout << "계좌 ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << endl;
	
	account[account_num].ID = id;
	strcpy(account[account_num].name, name);
	account[account_num].money = money;
	account_num ++;
}

void deposit(){
	int id;
	int deposit_money;
	cout << "[입  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> deposit_money;
	
	for(int i = 0; i < account_num; i++){
		if(account[i].ID == id){
			account[account_num].money += deposit_money;
			cout << "입금 완료" << endl;
			return;
		}
		else{cout << "계좌 오류";}
	}
}

void withdraw(){
	int id;
	int withdraw_money;
	cout << "[출  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> withdraw_money;
	
	for(int i = 0; i < account_num; i++){
		if(account[i].ID == id){
			if(account[i].money < withdraw_money){
				cout <<"잔액 부족" <<endl;
				return;
			}
			else{
				account[i].money -= withdraw_money;
				cout << "출금 완료" << endl;
				return;
			}
		}
	}
	cout << "계좌오류" << endl;
	return;
}

void print_all(){
	for(int i = 0; i < account_num; i++){
		cout << "계좌: " << account[i].ID << endl;
		cout << "이름: " << account[i].name << endl;
		cout << "잔액: " << account[i].money << endl;
		cout << endl;
	}
	return;
}