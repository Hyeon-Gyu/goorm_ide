#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
#include<cstring>

using namespace std;

vector<int> g[1001];
bool visited[1001];


void dfs(int s){
	if(visited[s] == true) return;
	visited[s] = true;
	cout << s << " ";
	for(int i=0; i<g[s].size();i++){
		int next = g[s][i];
		if(!visited[next])
			dfs(next);
	}
}

void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(int i=0; i<g[x].size();i++){
			int y = g[x][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = true;
			}
		}
	}
}


int main(){
	int n, l, s;
	int n1,n2;
	cin >> n >> l >> s;
	for(int i=0; i<l;i++){
		cin >> n1 >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}

	for(int i=1;i<=n;i++){
		sort(g[i].begin(), g[i].end());
	}
	
	dfs(s);
	cout << endl;
	
	for(int i=1;i<=n;i++){ //bfs를 위해 초기화
		visited[i] = false;
	}
	//memset(visited,false,sizeof(visited));
	bfs(s);
	return 0;
}

