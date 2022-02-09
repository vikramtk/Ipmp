#include<bits/stdc++.h>
using namespace std;

const int size=26;

struct trie
{
    struct trie *characters[size];
    bool isendofword;
};

struct trie* newnode()
{
    struct trie*root = new trie;
    
    root->isendofword=false;
    
    for(int i=0;i<size;i++)
    root->characters[i]=NULL;
    
    return root;
}

void insert(struct trie*root,string key)
{
    struct trie* cur=root;
    
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
    if(cur->characters[index]==NULL)
    cur->characters[index]=newnode();
    cur=cur->characters[index];
    }
    cur->isendofword=true;
}

int search(struct trie*root,string s)
{
    struct trie*cur=root;
    
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        if(cur->characters[index]==NULL)
        return 0;
        cur=cur->characters[index];
    }
    return cur->isendofword;
}

int main()
{
    string keys[]={"sure","survivor","an","ant","the","there"};
    int n=sizeof(keys)/sizeof(keys[0]);
    
    struct trie*root=newnode();
    
    for(int i=0;i<n;i++)
    insert(root,keys[i]);
    
    cout<<search(root,"sure");
    cout<<search(root,"ants");
    cout<<search(root,"there");
}
