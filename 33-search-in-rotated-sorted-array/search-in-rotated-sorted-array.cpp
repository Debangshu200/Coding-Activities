class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int l=0, r = size-1;

        while(l<r) {
        int mid = l+(r-l)/2;

        // Check in Left sorted Portion
            if(nums[0] <= nums[mid]) {
                if(nums[l] <= target && target <= nums[mid])
                    r = mid;
                else
                    l = mid+1;
            }
        // Check in Right sorted Portion 
            else {
                if(nums[mid] < target && target <= nums[r])
                    l = mid+1;
                else
                    r = mid;
            }
        }
    return (l == r && nums[l] == target) ? l : -1;
    }
};