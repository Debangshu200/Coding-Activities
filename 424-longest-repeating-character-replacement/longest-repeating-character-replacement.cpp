class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(26,0);
        int l = 0;
        int r = 0;
        int maxCharCount = 0;

        for(r = 0; r < s.size(); r++) {
            charCount[s[r] - 'A']++;
            
            maxCharCount = max(maxCharCount, charCount[s[r] - 'A']);

            if(r - l + 1 - maxCharCount > k) {
                charCount[s[l] - 'A']--;
                l++;
            }
        }
        return r - l;
    }
};