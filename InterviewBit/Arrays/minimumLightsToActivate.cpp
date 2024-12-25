#include<iostream>
#include<vector>
using namespace std;
int main()
{
    a=[0,1,1,1,0,0,1] b=3
    int n,b;
    cin>>n>>b;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int start=-1,end=-1,extend=-1;
    int ans=0;
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
            if(start <= 0 && end>=n-1)
            break;
            if(start==-1 && end==-1 && extend==-1)
            {
                start=left;
                end=right;
                extend=right;
                ans++;
            }
            else if(end-left == 0  && right>end)
            {
                end=right;
                extend=end;
                if(ans>1)
                ans--;
                ans++;
            }
            else if(end-(left)>=0 && extend>end)
            {
                extend=right;
                ans++;
            }
            else if(end-(left) == -1)
            {
                end=right;
                extend=end;
                if(ans>1)
                ans--;
                ans++;
            }
            else if(end-(left) < -1 && (extend-(left) == 0 || extend-(left) == -1))
            {
                end=right;
                extend=end;
                ans++;
            }
            cout<<"start:"<<start<<"\n"<<"end:"<<end<<"\n"<<"extent:"<<extend<<"\n"<<"ans:"<<ans<<"\n";
        }
    }
    cout<<start<< " "<<extend<<"\n";
    if(start <=0 && extend >=n-1)
    cout<<ans;
    else
    cout<<"-1";
}

arr = [1,] n=20
son=(n*(n+1))/2
sum=0
for(i in arr) sum+=if
if(sum == son)return false else return true