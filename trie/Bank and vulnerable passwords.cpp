#include<bits/stdc++.h>
using namespace std;
int z;
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
bool search(string str)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        cur=cur->child[idx];

    }
    for(int i=0;i<26;i++)
    if(cur->child[i]!=NULL)return false;

    return true;

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
    int n,i;

    root =new trie;
    cin>>n;
    set<string>dub;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s;
        dub.insert(s);
        insert(s);
    }
    //cout<<"Case "<<z<<": ";
  if(dub.size()!=n)
  {
      cout<<"vulnerable\n";
      return;
  }
  for(string x:dub)
  {
      if(search(x)==false)
      {
          cout<<"vulnerable\n";
          return;
      }
  }
cout<<"non vulnerable\n";

}
int main()
{
    int t=1;
    //cin>>t;
    for(z=1;z<=t;z++)
    {
        solve();
         del(root);
    }
    return 0;
}
