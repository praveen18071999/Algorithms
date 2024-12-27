vector<int> Solution::solve(vector<int> &A) {
    int i=0,j=i+1;
    while(i<A.size() && j<A.size())
    {
        if(A[i]==0)
        {
            i++;
            j=i+1;
        }
        else if(A[i]>0)
        {
            while(j<A.size() && A[j]>0)
            {
                j++;
            }
            if(i<A.size() && j<A.size())
            swap(A[i],A[j]);
            i++;
        }
        if(j<i)
        j=i+1;
    }
    return A;
}
