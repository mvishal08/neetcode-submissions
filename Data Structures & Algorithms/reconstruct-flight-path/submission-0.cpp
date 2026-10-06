class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> ans;
    void dfs(string s)
    {
        while(!adj[s].empty())
        {
            string next = adj[s].back();
            adj[s].pop_back();

            dfs(next);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        for (vector<string> ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [from, destinations] : adj)
        {
            sort(destinations.rbegin(), destinations.rend());
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
