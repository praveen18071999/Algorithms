#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]=i+1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(m[a[i]])
            {
                ans+=m[a[i]];
                m[a[i]]=0;
            }
        }
        cout<<ans<<"\n";
    }
}