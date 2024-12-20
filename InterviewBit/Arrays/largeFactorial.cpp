#include<iostream>
#include<vector>
using namespace std;
vector<int> getInd(int n)
{
    vector<int> v;
    while(n!=0)
    {
        v.push_back(n%10);
        n=n/10;
    }
    reverse(v.begin(),v.end());
    return v;
}
vector<int> calculate(vector<vector<int> > v)
{
    int maxSize=v[v.size()-1].size();
    for(int i=0;i<v.size();i++)
    {
        int t=(maxSize-v[i].size());
        while(t--)
        {
            v[i].push_back(0);
        }
    }
    int c=v[0].size(),r=v.size();
    int c1=0;
    vector<int> ans;
    for(int i=0;i<c;i++)
    {
        int sum=0;
        for(int j=0;j<r;j++)
        {
            sum+=v[j][i];
        }
        sum=sum+c1;
        if(sum<=9)
        {
            ans.push_back(sum);
            c1=0;
        }
        else{
            ans.push_back(sum%10);
            c1=sum/10;
        }
    }
    if(c1)
    ans.push_back(c1);
    reverse(ans.begin(),ans.end());
//     for(int i=0;i<ans.size();i++)
//     cout<<ans[i]<<" ";
// cout<<endl;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v1;
    vector<vector<int> > v;
    vector<int> v2=getInd(n);
    for(int i=n-1;i>=1;i--)
    {
        v1=getInd(i);
        int l=0;
        for(int j=v2.size()-1;j>=0;j--)
        {
            vector<int> temp;
            int c=0;
            int t1=l;
            while(t1--)
            {
                temp.push_back(0);
            }
            for(int k=v1.size()-1;k>=0;k--)
            {
                int t=(v2[j]*v1[k]) + c;
                if(t<=9)
                {
                    temp.push_back(t);
                    c=0;
                }
                else
                {
                    c=t/10;;
                    temp.push_back(t%10);
                }
            }
            if(c)
            {
                temp.push_back(c);
            }
            l++;
            v.push_back(temp);
        }
        v2=calculate(v);
        v.clear();
    }
    for(int i=0;i<v2.size();i++)
    cout<<v2[i]<<" ";
}