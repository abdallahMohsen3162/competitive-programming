#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int A , B , k;
        cin >> A >> B >> k;
        int a[k] , b[k];
        map<int , int> m1 , m2;
        for(int i=0;i<k;i++){
            cin >> a[i];
            m1[ a[i] ]++;
        }

        for(int i = 0;i<k;i++){
            cin >> b[i];
            m2[ b[i] ]++;
        }
        long long ans = 0;
        for(int i=0;i<k;i++){
            m1[ a[i] ]--;
            m2[ b[i] ]--;
            ans += k - i - 1 - (m1[ a[i] ] + m2[ b[i] ]);

        }
        cout << ans <<"\n";
    }



	return 0;
}
