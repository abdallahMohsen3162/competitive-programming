// https://leetcode.com/problems/repeated-substring-pattern/description/
// kmp failure function application
class Solution {
private:
vector<int> compute_prefix(string&s){
  int n = s.size();
  vector<int> ff(n, 0);
  int j = 0;
  for(int i = 1; i < n; i++){
    while(j > 0 && s[i] != s[j]){
      j = ff[j - 1];
    }
    if(s[i] == s[j]){
      j++;
      ff[i] = j;
    }else{
      ff[i] = 0;
    }

  }
  return ff;
}

public:

    bool repeatedSubstringPattern(string s) {
      vector<int> ff = compute_prefix(s);
      int lst = ff.back();
      int n = s.size();

      if(lst && n % (n - lst) == 0){
        return true;
      }
      return false;
    }
};
