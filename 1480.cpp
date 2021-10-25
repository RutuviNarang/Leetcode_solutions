class Solution {
public:
    int PartialSum(vector<int>& nums, int a, int b)
    {
        int sum=0;
        for(int i=a;i<=b;i++)
            sum+=nums[i];
        return sum;
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int>runningSum;
        for(int i=0;i<nums.size();i++)
            runningSum.push_back(PartialSum(nums,0,i));
        return runningSum;
    }
};
