vector<int> divs(int x){
	vector<int>res;
	int i = 2;
	for(i = 2; i <= x/i ; ++i){
		if(x % i == 0){
			int a = x / i , b = i;
			res.pb(a);
			if( a != b)
				res.pb(b);
			
		}
	}
	return res;
}


bool is_prime(int x){
	if(x == 1){
		return 0;
	}
	for(int i = 2 ; i * i <= x ; ++i){
		if(x % i == 0) return 0;
	}
	return 1;
}


void PFs(int x, vector<int>&mp){
	for(int i = 2; i * i <= x; i++){
    while(x % i == 0 && x > 0) mp[i]++, x /= i;
  }
  if(x > 1)
    mp[x]++;
}



vector<pair<int,int>> factors(int n){
	vector<pair<int,int>>res;
	for(int i=2;i*i<=n;++i){
		int cnt = 0;
		while(n % i == 0){
			cout<<"i = " << i<<"\n";
			n /= i;
			cnt++;
		}
		res.pb({i,cnt});
	}
	
 	if(n>1)res.pb({n,1});
	return res;
}





vector<bool> sieve(int n){
	vector<bool>prime(n+1,1);
	//return 0 0 1 1 0 1 0 1 . . . (n+1)
	prime[0] = 0;
	prime[1] = 0;
	
	for(int i=2;i <= n;i++){
		if(prime[i] == 1){
			for(int j=i+i; j<=n ;j += i){
				prime[j] = 0;
			}
		}
	}
	return prime;
}




vector<vector<int>> PREFIX2D(vector<vector<int>>arr){
	int m = arr[0].size();
	int n = arr.size();
	vector<vector<int>>res(n+1);
 
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			res[i].pb(0);
		}
	}
 
	 // the segments bounded by r1,r2,c1,c2 = res[r2][c2] - res[r1][c2] - res[r2][c1] + res[r1][c1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			res[i][j] = arr[i-1][j-1] + res[i][j-1] + res[i-1][j] - res[i-1][j-1];
		}
	}
	return res;
}
 
