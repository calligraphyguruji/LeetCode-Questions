class Solution {
public:
    //Approach : Sliding Window + HashSet

    
    int lengthOfLongestSubstring(string s) {
        
        //Step-1: Initialize variables
        int n = s.length();

        int left = 0;
        int right = 0;

        int maxLength = 0;

        unordered_set<char> currWindow;
        
        //Step-2: Expand the sliding window
        while(right < n){
            
            //Step-3: Remove Duplicates
            while(currWindow.count(s[right])){

                currWindow.erase(s[left]);//Remove the left char. from set
                left++;//move left pointer to shrink the size of currWindow
            }

            //Step-4: Insert next element into sliding window
            currWindow.insert(s[right]);

            //Step-5: Update maxLength 
            maxLength = max(maxLength, right - left + 1);

            //Move right pointer to expand the window
            right++;
        }

        //Step-6 : Return the answer
        return maxLength;
    }
};