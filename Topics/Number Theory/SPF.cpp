/*
Smallest prime factor SPF preprocessed by sieve
and used to calculate prime factors in log(N) rather than SQRT(N)
``Algorithm``
Given X
add the SPF[X] to the map and (x /= SPF[x])
add the SPF[X] to the map and (x /= SPF[x])....
and so on till x = 1

*/
const int N = 1e6 + 1;
int SPF[N];
void sieve(){
  for(int i = 1; i < N; i++){
    SPF[i] = i;
  }

  for(int x = 2; x <= N; x++){
    for(int i = x*x; i < N; i += x){
      if(SPF[i] != i) continue;
      SPF[i] = x;
    }
  }
}

void PFs(int x, map<int, int>&mp){
  while(x > 1){
    mp[SPF[x]]++;
    x /= SPF[x];
  }
}