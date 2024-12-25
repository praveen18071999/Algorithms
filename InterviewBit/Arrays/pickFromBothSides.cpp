#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int B;
    cin>>B;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> prefix;
    vector<int> suffix;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        prefix.push_back(sum);
    }
    sum=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        sum+=v[i];
        suffix.push_back(sum);
    }
    for(int i=0;i<prefix.size();i++)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<suffix.size();i++)
    {
        cout<<suffix[i]<<" ";
    }
    cout<<"\n";
    int i=0,j=1;
    int ans=INT_MIN,t=B;
    while(t--){
        int temp=(B-j-1 >=0)?suffix[B-j-1]:0;
        ans=max(ans,prefix[i]+ temp);
        i++;
        j++;
        if(B-j-1 <0)
        break;
    }
    t=B;
    i=0,j=1;
    while(t--)
    {
        int temp=(B-j-1 >=0)?prefix[B-j-1]:0;
        ans=max(ans,suffix[i]+ temp);
        i++;
        j++;
        if(B-j-1 <0)
        break;
    }
    cout<<ans;
}