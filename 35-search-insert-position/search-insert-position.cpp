
// in two passes -
// 1. Traverse the array
// 2. for first iteration, if we find the target we will return
// 3. If not found, we will iterate again and check - 'if(target > arr[i-1] && target < arr[i])' the print i. We can get answer by only cheking target < arr[i] - as the array is already sorted.
// TC - O(2n)
// edge case - 1. empty array 2. Target lesser than first element 3. Target greater than last element

// In one pass -
// 1. Traverse the array
// 2. if (arr[i] == target) return i;
// 3. Else if ( target < arr[i]) return i;
// TC - O(n)

// Binary Search
// 1. We will calculate the mid and take left and right pointer, 
// 2. if target == mid, then return the index,
// 3. else if(target > mid) so, left = mid+1; -> after that we will check if(left > target || left < target)
// 4. else if(target < mid) right = mid-1; -> after that we will check if(right > target || right < target)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
        
        int mid = l + (r-l)/2;
        
        if(target == nums[mid]) {
            return mid;
        }
        else if(nums[mid] > target){
            r = mid - 1;
            // if()
        }
        else
            l = mid + 1;
        }
        return l;
    }   
};
 