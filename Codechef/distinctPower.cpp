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
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    vector<pair<int,int>> v1;
	    for(int i=0;i<n;i++)
	    {
	        v1.push_back({v[i],i+1});
	    }
	    sort(v1.rbegin(),v1.rend());
	    int ans=0;
	    for(int i=0;i<v1.size()-1;i++)
	    {
	        if(abs(v1[i].second-v1[i+1].second) == 1)
	        ans++;
	    }
	    cout<<n-ans<<"\n";
	}

}