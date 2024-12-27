int Solution::solve(vector<int> &A, int B) {
    map<int,int> m;
    for(int i=0;i<A.size();i++)
    {
        m[A[i]]++;
    }
    for(int i=0;i<A.size();i++)
    {
        int add=A[i]+B;
        int sub=A[i]-B;
        m[add]++;
        m[sub]++;
        if(m[add]==A.size())
        return 1;
        if(m[sub]==A.size())
        return 1;
        if(m[A[i]]==A.size())
        return 1;
    }
    return 0;
}
