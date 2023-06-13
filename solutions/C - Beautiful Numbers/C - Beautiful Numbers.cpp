#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define Abdul ios::sync_with_stdio(false); cin.tie(0);

template <class T> void pr(vector<T>vec){for(int i=0;i<vec.size();i++){cout<<vec[i]<<' ';}cout<<"\n";}
template <class T> void pr(T arr[],int n){for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<"\n";}
template <class T> void pr(T x){cout << x << endl;}
void IOFILE () { freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
ll mod = 1e9 + 7;
ll mul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}


ll add(ll a, ll b){
    return ((a%mod) + (b%mod))%mod;
}

ll fastPower(ll a,ll b);
ll power_with_modEx(ll a,ll b);
ll extendedEuclid(ll a, ll b, ll& x, ll& y);
ll modInvers(ll A);
ll NcR(ll n,ll r);

const int N = 1e6 + 10;
int a , b , d;
ll fact[N];



bool excillent(int x){
    while(x){
        if(x%10 !=a && x%10 != b){
            return 0;
        }
        x /= 10;
    }
    return 1;
}


void tc(){
    for(int i=2;i<=N;++i){
        fact[i] = mul(fact[i-1] ,i);
    }
    cin >> a >> b >> d;
    ll sum = 0;
    for(int i=0;i<=d;++i){
        int dig_sum = a*i + (d-i)*b;
        if(excillent(dig_sum)){
            sum = add(sum , NcR(d,i));
        }
    }
    pr(sum);



}

int main()
{
    fact[0] = 1;
    fact[1] = 1;
   Abdul
   //IOFILE();
   int t = 1;
   //cin>>t;
   while(t--) tc();
	return 0;
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