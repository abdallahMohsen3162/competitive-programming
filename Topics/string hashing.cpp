#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 1e6 + 10, mod = 1e9 + 7, base = 31;

int pw[N];
int inv[N];
int pref[N];
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

void pre(){
  pw[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < N; i++){
    pw[i] = (base * pw[i-1])%mod;
    inv[i] = power(pw[i], mod - 2);
  }
}

int generateHash(string & str){
  int hashValue = 0;
  for(int i = 0; i < str.size(); i++){
    int idx = str[i] - 'a' + 1;
    hashValue = add(hashValue, mul(idx, pw[i]));
    pref[i] = hashValue;
  }
  return hashValue;
}



int getHash(int l, int r){
  if(l == 0){
    return pref[r];
  }
  return mul(add(pref[r], -pref[l-1]), inv[l]);
}

int calc(string s){
  int ret = 0;
  for(int i = 0; i < s.size(); i++){
    ret = add(ret, mul(s[i] - 'a' + 1, pw[i]));
  }
  return ret;
}

void answerTc(){
  string a, b;
  cin >> a >> b;
  int b_ha = calc(b);

  generateHash(a);

  vector<int> ans;
  for(int i = 0; i < a.size(); i++){
    int hv2 = getHash(i, i + b.size() - 1);
    if(b_ha == hv2){
      ans.push_back(i + 1);
    }
  }


  if(ans.size() == 0){
    cout << "Not Found";
  }else{
    cout << ans.size() << "\n";
    for(int a: ans){
      cout << a << " ";
    }
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
