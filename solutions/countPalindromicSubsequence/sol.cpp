class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26] , last[26];
        for(int i=0;i<26;i++){
            first[i] = INT_MAX;
            last[i] = -1;
        }

        for(int i=0;i<s.size();i++){
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        int ret = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(first[i] < last[i]){
                ret += set<char>(s.begin() + first[i] + 1,s.begin() + last[i]).size();
            }
        }
        return ret;
    }
};
//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
