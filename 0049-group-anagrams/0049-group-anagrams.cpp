class Solution {
public:
    //Time Complexity = O(n*k) where n = no. of strings, k = length of a string.
    //Space Complexity = O(n) => used unordered_map

    //function to calc. freq of chars. in each string
    string getFrequencyString(const string& str) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : str) {
            freq[c - 'a']++;
        }

        // Build unique key : creates a key (after counting the chars. in above)
        string key = "";
        for (int i = 0; i < 26; i++) {
            key += "#" + to_string(freq[i]);
        }

        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Edge case : check for empty strings
        if (strs.empty()) return {};

        //create a map to store freq.String, Strings
        unordered_map<string, vector<string>> mp;

        for (string& str : strs) {
            string key = getFrequencyString(str); //call function to calc. string freq. 
            mp[key].push_back(str);//and store in map key
        }
        
        vector<vector<string>> result; //result vector to store all the ans.
        for (auto& it : mp) {
            result.push_back(it.second); //push all the values(of map) in result vector.
        }

        return result; //very important to return all the ans
    }
};