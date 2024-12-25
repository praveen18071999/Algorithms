vector<int> Solution::findOccurences(vector<int> &A) {
    map<long,long> m;
    for(int i=0;i<A.size();i++)
    m[A[i]]++;
    vector<int> ans;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        if(m[A[i]]!=0)
        {
            
            ans.push_back(m[A[i]]);
            m[A[i]]=0;
        }
        
    }
    return ans;
}
