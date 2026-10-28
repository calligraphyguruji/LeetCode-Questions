class Solution {
public:
    string minWindow(string s, string t) {
        
        //Step-1: Initialize variables and array
        vector<int> freq(128, 0);

        //store  freq of chars. of t into freq array
        for(char ch : t){
            freq[ch]++;
        }

        int left = 0;
        int minLength = INT_MAX;
        int startIdx = 0;

        int required = t.length(); 

        //Step-2: Expand the window using right pointer
        for(int right = 0; right < s.length(); right++){

            if(freq[s[right]] > 0){ //check if current char is required
                required--;
            }

            freq[s[right]]--;

            //Step-3: Check window validity
            while(required == 0){

                //Step-4: Shrink the window
                int windowLen = right - left + 1;

                //update minLength & startIdx
                if(windowLen < minLength){
                    minLength = windowLen;
                    startIdx = left;
                }

                //Remove leftmost char to reduce the size of currWindow
                freq[s[left]]++; //because it's leaving the window

                if(freq[s[left]] > 0){
                    required++;
                }

                //move left pointer
                left++; //now it's out of window
            }
        }


        //Step-5: Return the answer
        return minLength == INT_MAX ? "" : s.substr(startIdx, minLength);


    }
};