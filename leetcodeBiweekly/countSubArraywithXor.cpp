class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int c=0;
        int i=0,j=2;
        //int c=0;
        while(j<nums.size())
            {
                int first=nums[i]+nums[j];
                int second=nums[i+1];
                //cout<<first<<" "<<second<<"\n";
                if(abs(second)%2==0 && first == second/2)
                    c++;
                i++;j++;
            }
        return c;
    }
};©leetcode