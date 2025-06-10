class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int dip = 0;
        for(int i = 0; i <= n-1; i++) {
            if(nums[i] > nums[(i+1) % n]){ // for circular/rotated array one crucial point, we need to compare the last with first elements, b'coz it's a rotated or circular array. In a normal array we can comapre till n-2 and n-1.
                dip++;
            }
        }
        return dip <= 1;

    //  1. 1st for loop - find the maximum in the array, so if there are any duplicates
    //  2. 2nd for loop - from i = 0 to arr[max-1] && arr[max+1] to arr[n-1] 
    //  3. if(arr[i] <= arr[i+1]) return true; 
    //             else return false
    // this idea is not helpful in case of duplicate elenments.
    }
};