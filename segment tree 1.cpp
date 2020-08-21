#include<bits/stdc++.h>
#define M 10005
using namespace std;
int a[M],tree[3*M];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left,right,mid;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[node];
    int left,right,mid,p1,p2;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b)return;
    if(b==e&&i==b)
    {
        tree[node]=newvalue;
        return;
    }
    int left,right,mid;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    init(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,4)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,4,n)<<endl;
    return 0;
}
