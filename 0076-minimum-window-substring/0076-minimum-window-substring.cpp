class Solution {
public:
    //Approach : Sliding Window + Frequency Array

    //Time Complexity = O(m + n) => m = length of s, n = length of t
    /* 1. Frequency Array Initialization: O(1)
    * vector<int> freq(128, 0) initializes a fixed-size array of 128 elements.
    2. Frequency Counting: O(n)
    * Traverse string t once to store the frequency of each required character.
    3. Sliding Window Traversal: O(m)
    * The right pointer traverses s at most m times.
    * The left pointer also moves forward at most m times.
    * Although the while loop is nested inside the for loop, both pointers only move forward.
    * Total operations = O(m + m) = O(m).
    4. Extracting the Substring: O(m)
    * s.substr(startIndex, minLength) copies at most m characters.
    */
 
    //Space Complexity = O(1) =>
    /* 1. Frequency Array: O(1)
    2. Variables: O(1)
    3. Output Substring: O(m) => This is output space, which is excluded from auxiliary space complexity.
    */

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
                required--;// Character enters → reduce remaining requirement
            }

            freq[s[right]]--;// Character enters → reduce remaining requirement

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
                freq[s[left]]++; //store its freq because it's leaving the window

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