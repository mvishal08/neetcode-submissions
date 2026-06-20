class Solution {
public:

    void helper(vector<int>&v, int &n, vector<int>temp, vector<vector<int>>&ans, int i)
    {   if(i>=n) {
            ans.push_back(temp);
            return;
        }
        helper(v,n,temp,ans,i+1);

        temp.push_back(v[i]);
        helper(v,n,temp,ans,i+1);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int> temp;
        helper(nums, n, temp, ans, 0);
        return ans;
    }
};