#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,sum=0;
        cin>>n>>k;
        int *a = new int[n];
        int *b = new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        std::sort(a,a+n);
        std::sort(b,b+n,greater<int>());
        for(int i=0;i<n;i++)
            sum+=a[i]*b[i];
        if(sum<=k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}