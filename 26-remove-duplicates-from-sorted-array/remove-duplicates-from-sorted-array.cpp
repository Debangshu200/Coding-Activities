class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Striver's Solution
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
        
        //My wrong Solution
        // int n = nums.size();
        // int i = 0, j = i+1;
        // for(;i < n; i++) {
        //     if(nums[j] > nums[i-1])
        //         nums[i] = nums[j];
        //     else
        //         j++;
        //         continue;
        // }
    }
};