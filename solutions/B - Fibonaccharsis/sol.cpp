#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
const int N = 1e5 + 10;

void tc(){
    int n,k; cin>>n>>k;
    ll ans = 0;
    for(int i=0;i<=n;i++){
        int sz = 1 , ai = i , prev = n;
        while(ai >= 0){
            sz++;
            int temp = ai;
            ai = prev - ai;
            prev = temp;
            if(sz == k && ai >= 0){
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}

//=========================================================
int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--) tc();
    return 0;
}