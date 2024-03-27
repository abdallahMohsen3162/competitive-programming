const int N = 5001, base1 = 29, base2 = 31;
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int pw1[N], pw2[N];
int inv1[N], inv2[N];

int add(int a, int b, int mod){
  return (0ll + a + b + mod) % mod;
}

int mul(int a, int b, int mod){
  return ((a % mod) * (b % mod)) % mod;
}


int power(int a, int b, int mod){
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
  vector<int> pref1, pref2; 
  int n;

  Hashing(string & str){
    n = str.size();
    pref1.resize(n, 0);
    pref2.resize(n, 0);
    int hashValue1 = 0, hashValue2 = 0;
    for(int i = 0; i < n; i++){
      int idx = str[i] - 'a' + 1;
      hashValue1 = add(hashValue1, mul(idx, pw1[i], mod1), mod1);
      hashValue2 = add(hashValue2, mul(idx, pw2[i], mod2), mod2); 
      pref1[i] = hashValue1;
      pref2[i] = hashValue2;
    }
  }

  pair<int, int> query_hash(int l, int r){ 
    if(l == 0){
      return {pref1[r], pref2[r]};
    }
    int hash1 = mul(add(pref1[r], -pref1[l-1], mod1), inv1[l], mod1);
    int hash2 = mul(add(pref2[r], -pref2[l-1], mod2), inv2[l], mod2);
    return {hash1, hash2};
  }

};

void pre(){
  pw1[0] = pw2[0] = 1;
  inv1[0] = inv2[0] = 1;
  for(int i = 1; i < N; i++){
    pw1[i] = (base1 * pw1[i-1])%mod1;
    pw2[i] = (base2 * pw2[i-1])%mod2; 
    inv1[i] = power(pw1[i], mod1 - 2, mod1);
    inv2[i] = power(pw2[i], mod2 - 2, mod2); 
  }
}
