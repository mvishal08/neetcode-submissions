class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>DP(366, 0);
        for(int i=1;i<=365;i++)
        {
            if(find(days.begin(), days.end(), i) == days.end())
                DP[i] = DP[i-1];
                
            else{
                DP[i] = min({
                    DP[i-1] + costs[0],
                    DP[max(0, i-7)] + costs[1],
                    DP[max(0, i-30)] + costs[2]
                });
            }
        }
        return DP[365];
    }
};