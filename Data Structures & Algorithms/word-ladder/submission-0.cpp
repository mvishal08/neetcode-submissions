class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        bool present1 = false;
        for(int i=0;i<n;i++)
        {
            if(endWord == wordList[i])  present1 = true;
        }
        if(present1 == false) return 0;

        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            string word = it.first;
            int level = it.second;

            if (word == endWord) return level;
            for(int i=0;i<word.size();i++)
            {
                char c = word[i];
                for(char x = 'a';x<='z';x++)
                {   
                    word[i] = x;
                    if(st.find(word) != st.end())
                    {
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = c;
            }

        }
        return 0;

    }
};