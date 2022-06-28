#include<iostream>
#include<vector>

using namespace std;





int main(){
	int r,c; // r = 가로 행, c = 세로 열
	cin >> c >> r;
	int ans[r] = {0,}; //한 줄씩 입력받아서 하나씩 분리시켜야한다.
	int maze[r][c] = {0,}; //전부 0으로 초기화
	
	for(int i=0;i<c;i++){
		cin >> ans[i]; //한칸에 하나씩 들어가는게 하니라 한방에 숫자가 다 들어감;;
		for(int j=0;j<r;j++){
			maze[i][j] = ans[j];//1차원배열의 수를 2차원배열에 넣어 미로완성
			
		}
		for(int j=0;j<r;j++){
			ans[j] = 0;
		}
	}
	
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			cout << maze[j][i];
		}
		cout << endl;
	}

}