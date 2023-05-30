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
#define dbg(a,b) cout << a << " " << b << "\n";

template <class T> void pr(vector<T>vec){for(int i=0;i<vec.size();i++){cout<<vec[i]<<' ';}cout<<"\n";}
template <class T> void pr(T arr[],int n){for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<"\n";}
template <class T> void pr(T x){cout << x << endl;}
void IOFILE () { freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}

bool isPrime(int x){
    for(int i=2;i<=x/i;i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void tc(){
    int n;
    cin >> n;
    vector<int>v;
    vector<int>dp(10005,0);
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            dp[i] = 1;
        }
    }
    for(int i=2;i<=10005;++i){

        if(dp[i] && i<=n){
            int x = i;
            v.pb(i);
            while(x <= n){
                x *= i;
                if(x <= n)
                    v.pb(x);
            }
        }
    }
    pr(v.size());
    pr(v);

}


int main()
{

   //Abdul
   //IOFILE();

   int t = 1;

   //cin>>t;

   while(t--) tc();



	return 0;
}