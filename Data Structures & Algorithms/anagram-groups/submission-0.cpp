class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<map<char, int>, string>> v;
        
        for(string s : strs)
        {
            map<char, int>mp;
            for(char c : s)
            {
                mp[c]++;
            }
            v.push_back({mp, s});
        }
        sort(v.begin(), v.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        vector<vector<string>>ans;
        
        for(int i =0;i<v.size();i++)
        {
            
            if (i == 0 || v[i].first != v[i - 1].first) {
                ans.push_back({});
            }

            ans.back().push_back(v[i].second);
        }
        return ans;
    }
};
