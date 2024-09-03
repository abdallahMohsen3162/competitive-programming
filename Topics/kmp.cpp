#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define dbg(x) cout << #x << " = " << x << "\n";
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define ld long double


vector<int>Kmp(string & str){
  int n = str.size();
  vector<int> fail(n, 0);
  for (int i = 1; i < n; ++i)
  {
    int j = fail[i - 1];
    while(j > 0 and str[i] != str[j])
      j = fail[j - 1];
    if(str[i] == str[j])
      j++;

    fail[i] = j;
  }
  return fail;
}


void tc() {
  string s = "abccdeabcedgt";
  vector<int> vec = Kmp(s);
  for (int i = 0; i < vec.size(); ++i)
  {
    cout << vec[i] << ' ';
  }
}

int32_t main(){

  int tt = 1; 
  // cin >> tt;
  while(tt--)tc();
  return 0;
}
