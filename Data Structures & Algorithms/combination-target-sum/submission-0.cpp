class Solution {
public:
    void helper(vector<int>&temp,vector<vector<int>>&ans, vector<int>&nums, int idx,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx == nums.size() || target<0) return;

        temp.push_back(nums[idx]);
        helper(temp,ans,nums,idx,target-nums[idx]);
        temp.pop_back();

        helper(temp,ans,nums,idx+1,target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(temp,ans,nums,0,target);
        return ans;
    }
};
