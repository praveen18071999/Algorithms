/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int mini=min(newInterval.start,newInterval.end);
    int maxi=max(newInterval.start,newInterval.end);
    newInterval.start=mini;
    newInterval.end=maxi;
    vector<Interval> ans;
    int f=0;
    if(intervals.size()==0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    else if(newInterval.start<intervals[0].start && newInterval.end<intervals[0].end)
    {
        ans.push_back(newInterval);
        for(int i=0;i<intervals.size();i++)
        ans.push_back(intervals[i]);
        return ans;
    }
    else if(newInterval.start>intervals[intervals.size()-1].end)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    else if(newInterval.start<=intervals[0].start && intervals[intervals.size()-1].end<=newInterval.end)
    {
        ans.push_back(newInterval);
    }
    else
    {
        for(int i=0;i<intervals.size();i++)
        {
            if(newInterval.start>intervals[i].end)
            {
                ans.push_back(intervals[i]);
            }
            else if(newInterval.end<intervals[i].start)
            {
                ans.push_back(newInterval);
                for(int j=i;j<intervals.size();j++)
                ans.push_back(intervals[j]);
                return ans;
            }
            else
            {
                //ans.push_back(intervals[i]);
                //newInterval.start=intervals[i].start;
                //cout<<intervals[i].start<<" "<<intervals[i].end<<"\n";
                //break;
                int k=-1;
                for(int j=i;j<intervals.size();j++)
                {
                    if(newInterval.end >= intervals[j].start && newInterval.end <= intervals[j].end)
                    {
                        newInterval.end=intervals[j].end;
                        k=j+1;
                        break;
                    }
                    else if(intervals[j].start>newInterval.end)
                    {
                        k=j;
                        break;
                    }
                    newInterval.end=max(newInterval.end,intervals[j].end);
                }
                    newInterval.start=min(intervals[i].start,newInterval.start);
                    ans.push_back(newInterval);
                    for(int j=k;j<intervals.size();j++)
                    {
                        ans.push_back(intervals[j]);
                    }
                    return ans;
            }
        }
    }
    
    return ans;
}
