#include<bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie* child[26];
    bool is_end;
    trie()
    {
        memset(child,0,sizeof(child));
        is_end=false;
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
   }
   cur->is_end=true;

}
int search(string str)
{
    struct trie *cur=root;
    int c=1,ans=1;
    for(char ch:str)
    {
        int idx=ch-'a';

        for(int i=0;i<26;i++)
        {
            if(i!=idx and cur->child[i]!=NULL)
            {
                ans=c;
                break;
            }
        }
 cur=cur->child[idx];
 c++;
    }
    return ans;
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
    int i,n;
    root=new trie;
    cin>>n;
    set<string>dub;
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
        dub.insert(s);
    }
    int res=0;
    for(string x:dub)
    {
       res+=search(x);
    }
   cout<<res<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        del(root);
    }
}
