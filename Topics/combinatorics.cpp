ll mod = 1e9 + 7;
const int N = 2e5 + 1;

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll fact[N];
//take(a,b) -> return gcd(a,b)
ll extendedEuclid(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=extendedEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

//return -> mod invers of A
ll modInvers(ll A){
    ll x1,y1;
    extendedEuclid(A,mod,x1,y1);
    return (x1%mod + mod)%mod;
}
//ncr
ll NcR(ll n,ll r)
{
  return mul(mul(fact[n],modInvers(fact[n-r])),modInvers(fact[r]));
}

//npr
ll NpR(ll n,ll r)
{
    return mul(fact[n],modInvers(fact[n-r]));
}

void get_fact(int n){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<n;++i){
	    fact[i] = mul(i, fact[i-1]);
    }
}	
