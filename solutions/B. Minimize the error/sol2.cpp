#include <iostream>
#include <set>

using namespace std;

int main()
{


    int n,k1,k2;
    multiset<long long> ms;
    cin >> n >> k1 >> k2;

    long long*arr1 = new long long[n];
    long long*arr2 = new long long[n];

    for(int i= 0;i<n;i++)
    {
        cin >> arr1[i];
    }

    for(int i= 0;i<n;i++)
    {
        cin >> arr2[i];
        long long ABSLUTEDIFFERENCE = abs(arr1[i] - arr2[i]);
        ms.insert(ABSLUTEDIFFERENCE);
    }
    //cout << " -----------\n";
    long long oper = k1+k2;
    while(oper)
    {
        auto it = ms.end();
        it--;
        long long val = *it;
        ms.erase(it);
        --oper;
        val = abs(val - 1);
        ms.insert(val);
    }

    long long sum = 0;
    for(auto x:ms)
        sum += (x)*(x);

    cout << sum;

    return 0;
}











 