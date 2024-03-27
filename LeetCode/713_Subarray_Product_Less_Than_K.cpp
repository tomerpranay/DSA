class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0;
        int j=0;
        int p=1;
        int ans=0;
        while(j<nums.size()){
          p=p*nums[j];
          while(p>=k){
            p=p/nums[i];
            i++;
          }
          ans=ans+j-i+1;
          j++;
        }
        return ans;
    }
};