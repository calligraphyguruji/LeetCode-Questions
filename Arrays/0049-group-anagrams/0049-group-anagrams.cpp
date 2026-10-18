class Solution {
public:
    //Approach : Hashing (Hash Map + Frequency Count)

    //Time Complexity = O(n * k) => n = number of strings in strs, k = maximum length of a string.
    /* Outer loop goes upto n for n elements : O(n)
    * Inner loop :Each string takes O(k) to count frequencies and O(26) to generate its key. O(k)
    */

    //Space Complexity = O(n * k) =>
    /* Hash map stores frequency keys and groups of strings. : O(n * k)
    * The frequency array takes O(1) extra space (26 characters).
    * Why O(n × k)? unordered_map<string, vector<string>> mp;
    * Keys: In the worst case, there are n unique frequency keys. Each key has a fixed length of 26 frequency entries, so total key space is O(n).
    * Values: The hashmap stores all n original strings. If each string has at most k characters, the total space for strings is O(n × k).
    */


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