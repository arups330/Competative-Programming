#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int a[mx];
struct info
{
   int propagation,sum;
}tree[3*mx];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        return;
    }
    int left,right,mid;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[node].sum+carry*(e-b+1);
    int left,right,mid,p1,p2;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,j,carry+tree[node].propagation);
    p2=query(right,mid+1,e,i,j,carry+tree[node].propagation);
    return p1+p2;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)return;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].propagation+=x;
        return;
    }
    int left,right,mid;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].propagation;
}
int main()
{
    int n,k,i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    init(1,1,n);
    cout<<query(1,1,n,2,5)<<endl;
    update(1,1,n,2,3,1);
     cout<<query(1,1,n,2,5)<<endl;
     return 0;

}
