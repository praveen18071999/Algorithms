#include<iostream>
#include<vector>
using namespace std;

vector<int> addArrays(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int c=0;
    int maxi=max(A.size(),B.size());
    int n1=A.size(),n2=B.size();
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i=n1;i<maxi;i++)
    {
        A.push_back(0);
    }
    for(int i=n2;i<maxi;i++)
    {
        B.push_back(0);
    }
    reverse(A.begin(),A.end());
    //if(f2==1)
    reverse(B.begin(),B.end());
    // for(int i=0;i<A.size();i++)
    // {
    //     cout<<A[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0;i<B.size();i++)
    // {
    //     cout<<B[i]<<" ";
    // }
    // cout<<"\n";
   
    for(int i=maxi-1;i>=0;i--)
    {
        int t=A[i]+B[i]+c;
        if(t>9)
        {
            ans.push_back(t%10);
            c=t/10;
        }
        else
        {ans.push_back(t);c=0;}
    }
    if(c>0)
    ans.push_back(c);
    n1=ans.size();
    for(int i=n1-1;i>=0;i--)
    {
        if(ans[i] == 0)
        ans.pop_back();
        else
        break;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> A(n);
    vector<int> B(m);
    for(int i=0;i<n;i++)
    cin>>A[i];
    for(int j=0;j<m;j++)
    cin>>B[j];
    vector<int> ans=addArrays(A,B);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}
