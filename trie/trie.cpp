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
bool search(string str)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        int idx=ch-'a';
        if(cur->child[idx]==NULL)
        return false;

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
int main()
{
    int n,i;
    root =new trie;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
    }
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        if(search(str))
        cout<<str<<" is present\n";
        else
        {
            cout<<str<<"is not present\n";
        }


    }
    return 0;
}
