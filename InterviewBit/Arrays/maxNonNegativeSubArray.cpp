#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    //int t=A[0];
    long sum=0,large=-1,index=-1,c=0,c1=-1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] >= 0)
        {
            sum+=A[i];
            c++;
        }
        else{
            sum=0;
            c=0;
        }
        if(sum>large)
        {
            large=sum;
            index=i;
            c1=c;
        }
        else if(sum==large && c>c1)
        {
            large=sum;
            index=i;
            c1=c;
        }
    }
    cout<<index<<"\n";
    vector<int> ans;
    for(int i=index;i>=0;i--)
    {
        if(A[i]<0)
        break;
    ans.push_back(A[i]);
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}