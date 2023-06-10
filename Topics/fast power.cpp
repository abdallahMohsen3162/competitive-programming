#define ll long long

ll mod = 1e9 + 7;

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}

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
