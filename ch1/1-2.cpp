#include<iostream>


using namespace std;

int swap(int* num1, int* num2){
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int swap(char* ch1, char* ch2){
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
	
}

int main(){
	int num1 = 20;
	int num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;
	
	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;
	
	return 0;
}