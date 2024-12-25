int Solution::maxSubArray(const vector<int> &A) {
    int res=INT_MIN,maxi=A[0];
    res=max(maxi,res);
    for(int i=1;i<A.size();i++)
    {
        maxi=max(maxi+A[i],A[i]);
        res=max(maxi,res);
    }
    return res;
}
