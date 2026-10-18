class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();

        vector<vector<string>> ans; //to store the output
        
        
        unordered_map<string, vector<string>> mp;//(key, value)
        //here key = string type, value = vector<string> (multiple strings)

        for(int i = 0; i < n; i++){
            //make a freq. array to store the freq. of elem in strings.
            vector<int> freq(26);//26 chars. size


            for(int j = 0; j < strs[i].size(); j++){
                
                freq[strs[i][j] - 'a']++;                
            }

            //Convert freq array into unique key
            string key = "";

            for(int j = 0; j < 26; j++){
                key += "$" + to_string(freq[j]);
            }

            // Group strings with the same key
            mp[key].push_back(strs[i]);
        }
        
        //Store all groups values in ans
        for(auto& it : mp){
            ans.push_back(it.second); //in map second column is values of strings
        }

        //finally return the output
        return ans;

    }
};