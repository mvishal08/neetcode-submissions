class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r)
    {
        int n = nums.size();
        int len = r - l + 1;

        if (len == 1)
            return nums[l];

        if (len == 2)
            return max(nums[l], nums[l + 1]);

        vector<int> DP(n, 0);
        DP[l] = nums[l];
        DP[l+1] = nums[l+1];
        DP[l+2] = nums[l+2] + DP[l];

         for(int i=l+3;i<=r;i++)
        {
            DP[i]=nums[i]+max(DP[i-2],DP[i-3]);
        }
        return max(DP[r],DP[r-1]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        return max(
            robLinear(nums, 0, n-2),
            robLinear(nums, 1, n-1)
        );
    }
};
