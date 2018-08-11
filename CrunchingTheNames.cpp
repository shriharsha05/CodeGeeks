#include <bits/stdc++.h>
using namespace std;
long find_ind(string a, string s[] , long t)
{
    long ind=0;
    for(long i=0;i<t;i++)
    {
        if(s[i]==a)
            ind = i;
    }
    return ind+1;
}

long find_val(string a,string s[] , long t)
{
    long k = find_ind(a,s,t);
    long val=0;
    for(long i=0;i<a.length();i++)
    {
        if(i==0)
            val+=(a[i]-65)+1;
        else
            val+=(a[i]-97)+1;
    }
    return val*k;
}

int main() 
{
    long t = 0;
    cin>>t;
    string s[t];
    for(long i=0;i<t;i++)
        cin>>s[i];
    sort(s,s+t);
    int q;
    cin>>q;
    while(q--)
    {
        string a;
        cin>>a;
        cout<<find_val(a,s,t)<<endl;
    }
    return 0;
}