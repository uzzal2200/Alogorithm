class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==cnt) cnt++;
        }
        return cnt;
    }
};