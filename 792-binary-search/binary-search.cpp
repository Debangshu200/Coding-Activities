class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0; 
       int right = nums.size()-1;

       while(left < right) {
        int mid = left + (right-left) / 2;

        // If the middle element is greater or equal to the target,
            // we need to move the right boundary to the middle
        if(nums[mid] >= target) {
            right = mid;
        } else {
            // Else we move left boundary one step to the right of mid
            left = mid + 1;
        }
       } 
       // After the loop ends, left should point to smallest
       return (nums[left] == target) ? left : -1;
    }
};