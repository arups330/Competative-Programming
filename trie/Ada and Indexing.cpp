#include<bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie* child[26];
    int is_end;
    trie()
    {
        memset(child,0,sizeof(child));
        is_end=0;
    }
}*root;

void insert(string str)
{
    struct trie *cur=root;
    for(char ch:str)
   {
       int idx=ch-'a';
       if(cur->child[idx]==NULL)
          cur->child[idx]=new trie;

       cur=cur->child[idx];
       cur->is_end++;
   }

}
int search(string str)
{
    struct trie *cur=root;

    for(char ch:str)
    {
        int idx=ch-'a',ans=0;
        if(cur->child[idx]==NULL)
        return ans;
      cur=cur->child[idx];
    }
    return cur->is_end;
}
void del(trie* cur)
{
    for (int i = 0; i <26; i++)
        if (cur->child[i])
            del(cur->child[i]);

    delete (cur);
}

void solve()
{
    int i,n,k;
    root=new trie;
    cin>>n>>k;
    set<string>dub;
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
        dub.insert(s);
    }
    int res=0;
    while(k--)
    {
        string s;
        cin>>s;
        cout<<search(s)<<endl;
    }


}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        del(root);
    }
}
