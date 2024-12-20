#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > vis;
void spiral(vector<vector<int> > v,int r,int c,int i, int j)
{
    int i1=0,j1=0,in=0,jn=0;
    int totalElements=r*c;
    while(totalElements)
    {
        i=in,j=jn;
         while(j<c && totalElements>0)
        {
            cout<<v[i][j]<<" ";
            totalElements--;
            j++;
        }
        j--;
        i++;
        while(i<r && totalElements>0)
        {
            cout<<v[i][j]<<" ";
            totalElements--;
            i++;
        }
        i--;
        j--;
        while(j>=j1 && totalElements>0)
        {
            cout<<v[i][j]<<" ";
            totalElements--;
            j--;
        }
        j++;
        i--;
        while(i>i1 && totalElements>0)
        {
            cout<<v[i][j]<<" ";
            totalElements--;
            i--;
        }
        in++;
        jn++;
        i1++;
        j1++;
        r--;
        c--;
        //break;
    }
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int> > v;
    for(int i=0;i<r;i++)
    {
        vector<int> in;
        for(int j=0;j<c;j++)
        {
            int t;
            cin>>t;
            in.push_back(t);
            //vis[i][j]=0;
        }
        v.push_back(in);
    }
    spiral(v,r,c,0,0);
}