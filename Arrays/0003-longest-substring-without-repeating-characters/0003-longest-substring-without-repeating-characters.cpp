class Solution {
public:
    //Approach : Sliding Window + HashSet

    
    int lengthOfLongestSubstring(string s) {
        
        //Step-1: Initialize variables
        int n = s.length();

        int left = 0;

        int maxLength = 0;

        unordered_set<char> currWindow;

        //Step-2: Expand the sliding window using right
        for(int right = 0; right < n; right++){

            //Step-3: Remove Duplicates
            while(currWindow.count(s[right])){

                currWindow.erase(s[left]);// Remove the leftmost character from the set
                left++;//move the left pointer to shorten the window size

            }

            //Step-4: Add current character to window
            currWindow.insert(s[right]);

            //Step-5: Update maxLength
            maxLength = max(maxLength, right - left + 1);
        }


        //Step-6 : Return the answer
        return maxLength;
    }
};