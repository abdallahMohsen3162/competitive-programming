#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define pb push_back
#define pp pop_back

template <class T> void pr(vector<T>vec){for(int i=0;i<vec.size();i++){cout<<vec[i]<<' ';}cout<<"\n";}
template <class T> void pr(T arr[],int n){for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<"\n";}
template <class T> void pr(T x){cout << x << endl;}


/*

vector<int>adj[N];
bool vis[N];

int counter = 0;

void dfs(int i){
   vis[i] = 1;
   for(int a:adj[i]){
      if(vis[a])continue;
      dfs(a);
   }
};


int conectedComponents(int){
   int cnt = 0;
   for(int i = 1;i<=n;++i){
      if(!vis[i]){
         cnt++;
         dfs(i);
      }
   }
   return cnt;
}
*/
bool flag = false;


void SSS()
{
   int n; cin >> n;
   int arr[n];
   fi(n){
      cin >> arr[i];
   }
   int ev = INT_MIN;
   fi(n){
      if(arr[i] % 2 == 0){
         if(arr[i] < ev){
            no return;
         }
         ev = arr[i];
      }
      
   }
   
   ev = INT_MIN;
   fi(n){
      if(arr[i] % 2 != 0){
         if(arr[i] < ev){
            no return;
         }
         ev = arr[i];
      }
   }
   
   yes;
   
   
}

/*
3
3 4 2
*/
int main()
{

   int t = 1; 
   cin>>t;
   while(t--){
        SSS();
   }

    
	return 0;
}