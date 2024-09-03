//https://leetcode.com/problems/house-robber-ii/description/
class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() == 1){
        return nums[0];
      }
      if(nums.size() == 2){
        return max(nums[0], nums[1]);
      }
      vector<int> v = nums, u = nums;
      u.pop_back();
      v.erase(v.begin());
      int n = nums.size() - 1;
      int ret = 0;
      vector<int> dp(n + 1, 0);
      dp[0] = 0;
      dp[1] = v[0];
      for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 2] + v[i - 1], dp[i - 1]);
      }
      ret = dp[n];
      dp.resize(n + 1, 0);
      dp[0] = 0;
      dp[1] = u[0];
      for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 2] + u[i - 1], dp[i - 1]);
      }
      ret = max(ret, dp[n]);
      return ret;

    }
};
