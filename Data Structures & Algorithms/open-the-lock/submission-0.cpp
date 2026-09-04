class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         unordered_set<string> vis;


        for(auto x : deadends)
            vis.insert(x);


        if(vis.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");
        vis.insert("0000");

        int moves = 0;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--) {

                string cur = q.front();
                q.pop();

                if(cur == target)
                    return moves;

                for(int i=0;i<4;i++)
                {
                    string next = cur;
                    next[i] = (cur[i]-'0'+1)%10 + '0';

                    if(!vis.count(next))
                    {
                        vis.insert(next);
                        q.push(next);
                    }
                    next[i] = (cur[i] - '0' + 9) % 10  + '0';
                    if(!vis.count(next))
                    {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }

            moves++;
        }
        return -1;
    }
};