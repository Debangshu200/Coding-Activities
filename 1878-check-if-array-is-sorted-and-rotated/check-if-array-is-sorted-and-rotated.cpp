class Solution {
public:
    bool check(vector<int>& nums) {
        int i,n=nums.size(),sorted=1;
        
        for(i=0;i<n-1;i++){ // this loop will check if the array is already sorted or not
            if(nums[i]>nums[i+1]){
                sorted=0;
                break;
            }
        }
        if(sorted) return true; // if the array is sorted then it is rotated for n or 0 times
                                // so array is both sorted and rotated (including zero) so return
                                // true
        int rotVal=0;
        for(i=0;i<n-1;i++){// now if the array is not rotated then with this loop finding the
                           // rotating value
            if(nums[i]<=nums[i+1]){
                rotVal++;
            }
            else{
                rotVal++;
                break;
            }
        }
        // Now taking an array to store the element after rotating the nums array so that we can 
        // get the nums array when it was not rotated for rotVal times
        vector<int>tmp(n);
        for(i=0;i<rotVal;i++){
            tmp[n-rotVal+i]=nums[i];
        }
        for(i=rotVal;i<n;i++){
            tmp[i-rotVal]=nums[i];
        }

        // Now checking the non raoted array is sorted or not
        for(i=0;i<n-1;i++){
            if(tmp[i]>tmp[i+1]) return false;
        }
        return true;
    }
};