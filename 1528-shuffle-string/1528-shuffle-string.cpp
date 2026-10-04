class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        int n = s.length();

        string ans(n, ' ');//n sized string filled with spaces to store the output string

        for(int i = 0; i < n; i++){

            ans[indices[i]] = s[i];
        }

        return ans;
    }
};