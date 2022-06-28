#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<pair<int,int>,pair<int,string>>> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;
	}
	
	sort(v.begin(), v.end());
	
	cout << v[n-1].second.second << endl;
	cout << v[0].second.second;
	return 0;
}


/*
2차원 벡터?
n * 4 배열 벡터를 만들어서 각각 비교하기?
for문 안에서 입력받고, 숫자 걸러내고, 

또 for문 돌면서 년도 비교해서 같은 년도가 있으면 월 비교 날짜 비교해서 골라내기


*/