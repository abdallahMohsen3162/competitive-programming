// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/?envType=problem-list-v2&envId=sorting&difficulty=MEDIUM
class Solution {
public:
    int solve(int value, vector<int> & arr, int target){
      int ret = 0;
      for(int i = 0; i < arr.size(); i++){
        ret += min(value, arr[i]);
      }
      return abs(ret - target);
    }

    int findBestValue(vector<int>& arr, int target) {

      int ans = 0;
      int l = 0, r = *max_element(arr.begin(), arr.end());
      while(l <= r){
        int mid = (l + r) / 2;
        if(solve(mid + 1,arr, target) < solve(mid,arr, target)){
          ans = mid + 1;
          l = mid + 1;
        }else{
          ans = mid ;
          r = mid - 1;
        }
      }
      return ans;
    }
};
