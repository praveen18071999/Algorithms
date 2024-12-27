#include<iostream>
#include<vector>
using namespace std;
int foo(vector<int> v,int i,int n,int l){
    vector<int> suffix;
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=v[i];
        v.push_back(sum);
    }
    reverse(v.begin(),v.end());
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<foo(v,0,n,3);
}