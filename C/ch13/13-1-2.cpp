#include<iostream>

using namespace std;

template <typename T>
T SumArray(T arr[], int len){
	T sum = 0;
	for(int i = 0; i < len; i++){
		sum+= arr[i];
	}
	return sum;
}

int main(){
	int arr1[] = {1,2,3};
	cout << SumArray(arr1, sizeof(arr1)/sizeof(int)) << endl;
	double arr2[] = {1.1,2.2,3.3};
	cout << SumArray(arr2, sizeof(arr2)/sizeof(double)) << endl;
}