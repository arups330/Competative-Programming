#include<bits/stdc++.h>
using namespace std;

struct trie
{
    bool is_end;
    unordered_map<char,trie*>mp;
    trie()
    {
        is_end=false;
    }
}*root;

void insert(string str)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
            cur->mp[ch]=new trie;
        cur=cur->mp[ch];
    }
    cur->is_end=true;
}

bool search(string str)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
        return false;
        cur=cur->mp[ch];
    }
    return cur->is_end;
}
int main()
{
    root=new trie;
    int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		insert(str);
	}
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(search(str))
		{
			cout<<str<<" is present\n";
		}
		else
		{
			cout<<str<<" is not present\n";
		}
	}
}
