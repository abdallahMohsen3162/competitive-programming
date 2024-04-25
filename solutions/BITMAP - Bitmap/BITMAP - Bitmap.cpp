//https://www.spoj.com/problems/BITMAP/
#include<bits/stdc++.h>
#define int long long
using namespace std;

#define F first
#define S second
int mx = 1000000;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool valid(int&i, int&j, int&n, int&m){
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return true;
}

void tc(){  
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, mx));
	queue<pair<pair<int, int>, int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == '1'){
				q.push({{i, j}, 0});
				arr[i][j] = 0;
			}
		}
	}

	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int i = cur.F.F, j = cur.F.S , w = cur.S;
		for(int k = 0; k < 4; k++){
			int nx = i + dx[k] , ny = j + dy[k];
			if(valid(nx, ny, n, m)){
				if(arr[nx][ny] == mx){
					q.push({{nx, ny}, w + 1});
					arr[nx][ny] = w + 1;
				}
			}
		}
	} 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}
 
int32_t main(){
  int tt = 1; 
  cin >> tt;
  while(tt--)tc();
  return 0;
}
