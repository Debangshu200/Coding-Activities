#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> counts(26, 0);

        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            counts[t[i] - 'a']--; 
        }

        for (int count : counts) { 
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};