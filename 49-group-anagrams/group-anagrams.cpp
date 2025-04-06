class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for(auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramGroups[key].emplace_back(str);
        }
        vector<vector<string>> groupedAnagrams;
        for(auto& pair : anagramGroups) {
            groupedAnagrams.emplace_back(pair.second);
        }
        return groupedAnagrams;
    }
};