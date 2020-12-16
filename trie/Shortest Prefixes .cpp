#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <bitset>
using namespace std;

struct trie
{
    struct trie *child[26];
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
    int ans=str.size();
    for(int i=0;i<ans;i++)
    {
        char ch=str[i];
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
    int c=0,ans=str.size();
    for(int i=0;i<ans;i++)
    {
        char ch=str[i];
        int idx=ch-'a';

      cur=cur->child[idx];
      if(cur->is_end<=1)
      {
          cur->is_end++;
          return c;
      }
       c++;
    }
    ans--;
    cur->is_end++;
    return ans;
}
int main()
{
    int i,n;
    root=new trie;
    string s;
    vector<string>v;
    int c=0;
    while(cin>>s)
    {
        insert(s);
        v.push_back(s);
    }
    for(int j=0;j<v.size();j++)
    {
        string x=v[j];
        cout<<x<<" ";

        int num=search(x);

        for(i=0;i<=num;i++)
        cout<<x[i];
        cout<<endl;
    }
    return 0;
}
