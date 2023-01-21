//Joy Shree Kriskna
    #include<bits/stdc++.h>
    #define fast  ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define rep(i,n) for(i=0;i<n;i++)
    #define rep1(i,n) for(i=n-1;i>=0;i--)
    #define rep2(j,t) for(j=1;j<=t;j++)
    #define rep3(i,a,b) for(i=a;i<=b;i++)
    #define PI acos(-1)
    #define remove(s) s.erase(unique(s.begin(),s.end()),s.end());
    //#define lcm(a,b) ((a*b)/__gcd(a,b))
    #define endl "\n"
    #define countsetbit(n) __builtin_popcount(n)
    #define al(v) v.begin(),v.end()
    #define int int64_t
    using namespace std;
    //int z;

    void solve()
   {
       int n,k,i;
       cin>>n>>k;
       int a[n];
       rep(i,n)  cin>>a[i];

       int low = 1, high = 1e10+1;
       int ans;

       while(low<=high)
       {
        int mid = (low+high)/2,sum = 0;
        int cnt=1;
        rep(i,n)
        {
            sum+=a[i];
            if(a[i]>mid){cnt=k+1;break;}
            if(sum>mid)
            {
              sum=a[i];
              cnt++;
            }
        }
        if(cnt<=k){
          high=mid-1;
          ans=mid;
        }
        else low=mid+1;


       }
       cout<<ans<<endl;

   }
 main()
      {
           fast;
//   	    #ifndef ONLINE_JUDGE
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
// #endif
           int t=1;
           cin>>t;
           for(int z=1;z<=t;z++)
           solve();
          return 0;
      }
//arupsaha52
//1704052_Arup
