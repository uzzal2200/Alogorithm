class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l=0;
      int r=nums.size()-1;
     // int mid=0;
     //int mid;
      while(l <= r)
      {
         int mid=(l+r)/2;
          if(nums[mid] == target) return mid;
          else if(target > nums[mid])    l=mid+1;
          
          else    r=mid-1;
      }
      return -1;
    }
};