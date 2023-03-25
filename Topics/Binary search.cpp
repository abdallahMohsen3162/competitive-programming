#include <iostream>
using namespace std;



int BS(int arr[],int n,int x,int target,int l,int h)
{
    int i = l,j=h;

    int res = -1;
    while(i<=j)
    {
        int m = (i+j)/2;
        if(arr[m] + x < target)
            i = m+1;
        else if(arr[m] + x > target)
            j = m-1;
        else if(arr[m] + x == target)
        {
            res = m;
            break;
        }
    }
    return res;
}

int main()
{

    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    int n = sizeof(arr)/sizeof(arr[0]);



    int c = 0;
    cout << "\n Binary search nlog(n) solution\n" <<endl;
    while(arr[c] <= 10)
    {
        int BSRES = BS(arr,n,arr[c],10,0,n-1) ;
        if(BSRES != -1)
            cout << arr[c] << ' ' << arr[BSRES] << endl;
        c++;
    }



    cout << "\n Linear search n*n solution\n" <<endl;

    for(auto i:arr)
    {
        for(auto j:arr)
        {
            if(i+j==10) cout << i << ' ' << j <<endl;
        }
    }



    return 0;
}
