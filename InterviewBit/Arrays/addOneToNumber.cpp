#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
int c=1;
vector<int> ans;
for(int i=v.size()-1;i>=0;i--)
{
    int t=v[i]+c;
    if(t<=9){
        ans.push_back(t);
        c=0;
    }
    else{
        ans.push_back(t%10);
        c=t/10;
    }
}
if(c>0)
ans.push_back(c);
for(int i=n-1;i>=0;i--)
{
    if(ans[i] == 0)
    ans.pop_back();
else
break;
}
reverse(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
cout<<ans[i];
}