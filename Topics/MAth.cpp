#define ll long long

ll mod = 1e9 + 7;
ll mul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}

int nearest_multible(int x, int m){
    return round(x/m)*m;
}

double log_to_base(int x, int base){
    return (log10(x)/log10(base));
}

//fast power
ll fastPower(ll a,ll b){
	ll res = 1;
	while (b>0)
	{
		if(b%2==1){
			res *= a;
		}
		a = a*a;
		b = b / 2;
	}
	return res;
}

//fast power using mod
ll power_with_modEx(ll a,ll b){
	ll res = 1;
	while (b>0)
	{
		if(b%2==1){
			res = mul(res,a);
		}
		a = mul(a, a);
		b = b / 2;
	}
	return res;
}



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
ll modInvers(ll A,ll mod){
    ll x1,y1;
    extendedEuclid(A,mod,x1,y1);
    return (x1%mod + mod)%mod;
}


