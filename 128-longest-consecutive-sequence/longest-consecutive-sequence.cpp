#include<bits/stdc++.h>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numberSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for(int num : numberSet) {
            if(!numberSet.count(num-1)) { // check if the current number is the beggining of the new sequence
                int currentNum = num + 1; // if num is start of a sequence, look for all consecutive number starting form num+1

                while(numberSet.count(currentNum)) { // checking next consecutive number in sequence
                    currentNum++;
                }
                longestStreak = max(longestStreak, currentNum - num);
            }
        }
        return longestStreak;
    }
};