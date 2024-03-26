#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 1e6 + 10, mod = 1e9 + 7, base = 31;

int pw[N];
int inv[N];

int add(int a, int b){
  return (0ll + a + b + mod) % mod;
}

int mul(int a, int b){
  return (a % mod * b % mod) % mod;
}

int power(int a, int b){
  int ans=1;
  while(b>0)
  {
    if(b&1){
       ans=(ans*a)%mod;
    }
    a=(a*a)%mod;
    b>>=1;
  }
  return ans;
}


class Hashing{
public:
  vector<int> pref;
  int n;

  Hashing(string & str){
    n = str.size();
    pref.resize(n, 0);
    int hashValue = 0;
    for(int i = 0; i < n; i++){
      int idx = str[i] - 'a' + 1;
      hashValue = add(hashValue, mul(idx, pw[i]));
      pref[i] = hashValue;
    }
  }

  int query_hash(int l, int r){
    if(l == 0){
      return pref[r];
    }
    return mul(add(pref[r], -pref[l-1]), inv[l]);
  }

};
void pre(){
  pw[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < N; i++){
    pw[i] = (base * pw[i-1])%mod;
    inv[i] = power(pw[i], mod - 2);
  }
}




void answerTc(){
  string a, b;
  cin >> a >> b;
  vector<int> ans;
  if(b.size() > a.size()){
    cout << "Not Found\n";
    return;
  }

  Hashing bh(b) , ah(a);
  int n = a.size(), m = b.size();
  int val = bh.query_hash(0, m - 1);
  for(int i = 0; i < n; i++){
    if(i + m - 1 >= n) break;
    if(ah.query_hash(i, i + m - 1) == val){
      ans.push_back(i + 1);
    }
  }
  if(ans.size() == 0){
    cout << "Not Found\n";
    return;
  }
  cout << ans.size() << "\n";
  for(int a: ans){
    cout << a << " ";
  }
  cout << "\n";
}


int32_t main(){
  pre();

  int tt = 1; 
  cin >> tt;
  while(tt--)
    answerTc();
  return 0;
}
