//C++에서 C언어 표준함수 호출하기

/* c를 더하고 .h를 빼라

#include<string.h> -> <cstring>
#include<stdlib.h> -> <cstdlib>
#include<math.h> -> <cmath>

*/

#include<iostream>
#include<cstring>

using namespace std;

int main(){
	char arr[20] = "abcedfg";
	cout << strlen(arr) << endl;
	
	strcat(arr, "hijk");
	cout << arr << endl;
	
	char arr2[20] = "hijk";
	strcpy(arr2, arr);
	
	cout << arr2 << endl;
	
	if(strcmp(arr,arr2) == 0){
		cout << "same" << endl;
	}
	else{
		cout << "different" << endl;
	}
	
	return 0;
}
