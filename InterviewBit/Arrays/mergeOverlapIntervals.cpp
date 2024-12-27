/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool foo(Interval a,Interval b)
{
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),foo);
    // for(int i=0;i<A.size();i++)
    // {
    //     cout<<"("<<A[i].start<<" "<<A[i].end<<")";
    // }
    int i=1,k=-1;
    vector<Interval> ans;
    ans.push_back(A[0]);
    Interval curr=A[0];
    while(i<A.size())
    {
        if(A[i].start - curr.end < 0)
        {
            int f=0;
            while(i<A.size())
            {
                if(curr.end >= A[i].start && curr.end >= A[i].end)
                {
                    i++;
                }
                else if(A[i].start-curr.end > 0)
                {f=1;break;}
                else
                break;
            }
            if(i<A.size() && f==0)
            {
                ans[ans.size()-1].end=A[i].end;
                curr=ans[ans.size()-1];
                i++;
                //cout<<i<<"\n";
            }
            //cout<<i<<"\n";
        }
        else{
            ans.push_back(A[i]);
            curr=ans[ans.size()-1];
            i++;
        }
    }
    return ans;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// vector<Interval> Solution::merge(vector<Interval> &A) {
//     sort(A.begin(), A.end(), [](Interval l, Interval r){ return l.start<r.start; });
//     vector<Interval> ans;
//     ans.push_back(A[0]);
//     for(int i=1; i<A.size(); i++){
//         if(A[i].start<=ans.back().end) ans.back().end = max(ans.back().end, A[i].end);
//         else ans.push_back(A[i]);
//     }
//     return ans;
// }