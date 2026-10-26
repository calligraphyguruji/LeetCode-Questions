class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //Step-1: Initialize variables
        int m = s1.length();
        int n = s2.length();

        if(m > n){//means s1 size is greater
            return false;
        }
        
        //Step-2: Initialize two freq arrays 
        vector<int> freq1(26, 0); //for s1
        vector<int> freq2(26, 0); //for s2

        //Step-3: Count freq of s1 and first window of s2
        for(int i = 0; i < m; i++){

            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        //Step-4: check the first window
        if(freq1 == freq2){
            return true;
        }

        //Step-5: Slide the window through s2 
        for(int right = m; right < n; right++){

            //Add incoming next chars.
            freq2[s2[right] - 'a']++;

            //Remove outgoing previous chars.
            freq2[s2[right - m] - 'a']--;

            //check if freq. matched
            if(freq1 == freq2){
                return true;
            }
        }


        //Finally if no true permutation found in above checks then
        return false;

    }
};