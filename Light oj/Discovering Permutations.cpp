#include<bits/stdc++.h>
using namespace std;
int z;
int n,k;

void recur(string s,int l,int r)
{
    if(k==0)return;
    if(l==r)
    {
        cout<<s<<endl;
        k--;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            recur(s,l+1,r);
        }
    }
}
void solve()
{
    //int n,k;
    cin>>n>>k;
    string s="";
    for(int i=0;i<n;i++)
    s+=('A'+i);
    cout<<"Case "<<z<<":\n";
    recur(s,0,n-1);


}
main()
{
    int t;
    cin>>t;
    for(z=1;z<=t;z++)
    solve();
    return 0;
    
}
