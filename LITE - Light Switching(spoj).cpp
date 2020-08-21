#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
struct add
{
    int sum,toggle;
    //add():toggle(0),sum(0) {}
}tree[4*mx];
void prop(int node,int b,int e)
{
    tree[node].toggle=0;
    int left,right,mid;
    left=2*node;
    right=2*node+1;
    mid=(b+e)/2;
    tree[left].toggle^=1;
    tree[right].toggle^=1;
    tree[left].sum=1+mid-b-tree[left].sum;
    tree[right].sum=e-mid-tree[right].sum;
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return 0;
    if(i<=b&&j>=e)return tree[node].sum;
    if(tree[node].toggle)
        prop(node,b,e);
    int left, right,mid,p1,p2;
    left=2*node;
    right=left+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return;
    if(i<=b&&j>=e)
    {
        tree[node].toggle^=1;
        tree[node].sum=e-b+1-tree[node].sum;
        return;
    }
    if(tree[node].toggle)
        prop(node,b,e);
    int mid=(b+e)/2;
    update(node*2,b,mid,i,j);
    update(2*node+1,mid+1,e,i,j);
    tree[node].sum=tree[2*node].sum+tree[node*2+1].sum;
}
int main()
{
    int m,n,i,j,k,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>k>>x>>y;
        if(k)cout<<query(1,1,n,x,y)<<endl;
       else update(1,1,n,x,y);
    }
    return 0;
}
