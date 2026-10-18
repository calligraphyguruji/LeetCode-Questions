class Solution {
public:
    bool isAnagram(string s, string t) {
         
        int n = s.length();

        //edge-case
        if(s.length() != t.length()){
            return false;
        }

        //make a freq. Map array to store freq. of each char of s & t
        vector<int> freq(26); //26 chars. size (a to z)
        
        for(int i = 0; i < n; i++){
            
            //increment freq of char in s
            freq[s[i] - 'a']++;
            
            //decrement freq of same char in t
            freq[t[i] - 'a']--;
        }

        //After decrement freq. of same chars. from t 
        //if any element is non-zero in freq 
        //it means not an anagram
        for(int i = 0; i < 26; i++){

            if(freq[i] != 0){
                return false;
            }
        }
        

        //if in above check no false found      
        return true;

    }
};