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


const int N = 1e7 + 1;


class DSU{
public:
    vector<int>par;
    vector<int>sz;

    int numOfCom , szOfLargest;


    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;++i){
            par[i] = i;
            sz[i] = 1;
  
        }
        numOfCom = n;
        szOfLargest = 1;
    }

    int _find(int a){
        while(par[a] != a){
            a = par[a];
        }
        return par[a] = a;
    }

    bool _union(int a,int b){
        int pb = _find(a);
        int pa = _find(b);

        if(pb == pa){
             return 0;
        }
        if(sz[pa] > sz[pb]){
            par[pb] = pa;
            sz[pa] += sz[pb];
        }else{
            par[pa] = pb;
            sz[pb] += sz[pa];
        }
        szOfLargest = max(szOfLargest,max(sz[pb],sz[pa]));
        numOfCom--;
        return 1;
    }

    int get_sz(int x){
        int ind = _find(x);
        return sz[ind];
    }


};


class edge{
public:
  int a,b;
  ll w;

  bool operator<(edge&e) const{
    return w < e.w;
  }
};


vector<edge>mst;

ll kroksal(int n,vector<edge>&v){
  sort(v.begin(),v.end());
  DSU ds(n);
  for(auto e:v){
    if(ds._union(e.a, e.b)){
      mst.pb({e.a , e.b , e.w});
    }
    if(ds.numOfCom == 1){
      break;
    }
  }

  if(ds.numOfCom != 1){
    return -1;
  }

  ll cost = 0;
  for(auto e:mst){
    cost += e.w;
  }
  return cost;
}


void tc(){
  int n,m;
  cin>>n>>m;
  int a , b ;ll w;
  vector<edge>v;
  fi(m){
    cin >> a >> b >> w;
    v.pb({a,b,w});
  }



  ll ans = kroksal(n, v);

  if(ans == -1){
    pr("IMPOSSIBLE");
  }else{
    pr(ans);
  }





}
int main()
{


  ios::sync_with_stdio(false);
  cin.tie(0);
//  freopen("closing.in","r",stdin);
//  freopen("closing.out","w",stdout);

  int t = 1;

  //cin>>t;

  while(t--) tc();



  return 0;
}
