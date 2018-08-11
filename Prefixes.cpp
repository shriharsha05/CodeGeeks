#include<bits/stdc++.h>
using namespace std;
 
ofstream outp;
 
struct node{
    node * child[26];
    int count;
};
              
node * getnewnode( )
{
    node * temp = new node;

    for(int i=0;i<26;i++)
      temp->child[i] = NULL;
      
    temp->count = 0;
    return temp;
}

void insert(node * root,string s)
{
    node *temp = root;

    for(int i=0; i<s.length();i++)
    {
        int ind = s[i] - 'a';        
        if(temp->child[ind] == NULL)
        {
            temp->child[ind] = getnewnode();
        }
        
        temp = temp->child[ind];
        temp->count++;
    }
    
}

void search(node * root,string s)
{
    int len = 0;
    node *temp = root;
    
    for(int i=0; i<s.length();i++)
    {
        int ind = s[i] - 'a';
        if(temp->child[ind] == NULL)
        {
            cout<<len<<" "<<temp->count<<"\n";
            return;
        }
        temp = temp->child[ind];    
        len++;
    }
    cout<<len<<" "<<temp->count<<"\n";
}

int main()
{
    int n;
    cin>>n;
    
    outp.open("out.txt");
    node * root = getnewnode();
    root->count = n;

    string s;
    
    for(int i=0;i<n;i++) {cin>>s; insert(root,s);}
    
    int q;
    cin>>q;
    while(q--)
    {
        string st;
        cin>>st;
        search(root,st);
    }
}