#include<iostream>
#include<vector>
using namespace std;
int main()
{
   // a=[0,1,1,1,0,0,1] b=3
    int n,b;
    cin>>n>>b;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int start=-1,end=-1,extend=-1;
    int ans=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            int left=i-b+1;
            int right=i+b-1;
            if(right<left)
            {
                if(left<0)
                left=0;
                swap(left,right);
            }
            if(left<0)
            left=0;
            if(start == -1 && end == -1 && extend ==-1)
            {
                start=left;
                end=right;
                extend=end;ans++;
            }
            else if(end-left == 0 || end-left == -1)
            {
                end=left;
                extend=right;
                ans++;
                c=0;
            }
            else if(left == 0)
            {
                end=right;
                extend=right;
                ans=1;
                c=0;
            }
            else if(end-left < -1 || end-left > 0)
            {
                extend=end;
                c++;
            }
            
        }
        if(extend >= n-1 || end >= n-1)
        break;
    }
    cout<<start<<" "<<end<<" "<<extend<<"\n";
    if(start<=0 && extend>=n-1)
    {
        cout<<ans+c;
    }
    else
    cout<<"-1";
    

}