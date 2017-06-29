class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int max_current,min_current;
    max_current = min_current = nums[0];
    int max_result = nums[0];
    for(int i=1;i< nums.size();i++){
      int temp1 = max_current*nums[i];
      int temp2 = min_current*nums[i];
      max_current = max(nums[i],max(temp1,temp2));
      min_current = min(nums[i],min(temp1,temp2));
      max_result = max(max_result,max_current);
    }
    return max_result;
  }
};
