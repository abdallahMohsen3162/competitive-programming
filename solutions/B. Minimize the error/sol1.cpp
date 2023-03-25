#include <iostream>
#include <set>

using namespace std;

long long GETNUMOFERRORS(long long arr1[],long long arr2[],int n)
{
    long long res = 0;

    for(int i=0;i<n;i++) res += (arr1[i] - arr2[i])*(arr1[i] - arr2[i]);
    return res;
}

pair<long long,long long> GETMAXDIFFERENCE(long long arr1[],long long arr2[],int n)
{
    int max_i = 0;long long max_v = abs(arr1[0] - arr2[0]);

    for(int i=0; i<n;i++)
    {
        if(abs(arr1[i] - arr2[i]) > max_v)
        {
            max_v = abs(arr1[i] - arr2[i]);
            max_i = i;
        }
    }
    pair<long long,long long>res(max_i,max_v);
    return res;
}

int main()
{


    long long k1,k2;
    int n;
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
    }
    int ope = k1+k2;

    while(ope)
    {
        auto i = GETMAXDIFFERENCE(arr1,arr2,n);
        int index = i.first;
        if(arr1[index] > arr2[index]) arr1[index]--;
        else arr2[index]--;
        ope--;
    }

    cout << GETNUMOFERRORS(arr1,arr2,n);
    return 0;
}




 