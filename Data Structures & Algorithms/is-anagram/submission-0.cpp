class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1;
        map<char,int>mp2;
        for(char x : s)
        {
            mp1[x]++;
        }
        for(char y : t)
        {
            mp2[y]++;
        }

        return mp1==mp2;
    }
};
