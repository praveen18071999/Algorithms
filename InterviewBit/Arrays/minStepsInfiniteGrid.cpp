#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        int x1=a[i],x2=b[i],y1=a[i+1],y2=b[i+1];
        int X=abs(x1-y1),Y=abs(x2-y2);
        ans+=max(X,Y);
    }
    cout<<ans;
}