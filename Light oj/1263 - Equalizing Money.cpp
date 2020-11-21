#include<bits/stdc++.h>
using namespace std;
const int mx=1e3+10;
int a[mx],sum=0,c=0;
bool vis[mx];
vector<int>adj[mx];
int z;
void dfs(int node)
{
    vis[node]=1;
    sum+=a[node];
    c++;
    for(int x:adj[node])
        if(!vis[x])dfs(x);
}

void solve()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof a);
    memset(vis,0,sizeof vis);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

        for(i=0;i<mx;i++)
            adj[i].clear();

    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     printf("Case %d: ",z);

    set<int>s;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            sum=0;
            c=0;
            dfs(i);
            //cout<<sum<<" "<<c<<endl;
            if(sum%c)
            {
               printf("No\n");
                return;
            }
            s.insert(sum/c);
        }

    }

    (s.size()==1)?printf("Yes\n"):printf("No\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
        solve();
    return 0;
}
