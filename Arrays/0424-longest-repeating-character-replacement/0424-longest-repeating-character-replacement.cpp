class Solution {
public:
    //Approach : Sliding Window + Frequency Map

    //Time Complexity = O(n) =>
    /* Frequency Array : vector<int> freq(26, 0) takes O(26) = O(1).
    * For Loop: The right pointer traverses the string once → O(n).
    * While Loop: The left pointer moves forward at most n times in total → O(n).
    * Frequency Updates: freq[s[right] - 'A']++ takes O(1).
    * Maximum Frequency Update: max() takes O(1).
    * Why Nested loops do not always mean O(n²)?
    * In Sliding Window, when both left and right move only forward and never reset, the total time complexity is typically O(n).
    */

    //Space Complexity = O(n) =>
    /* Frequency Array: Stores frequencies of 26 uppercase English letters → O(26) = O(1).
    * Variables: n, left, right, maxLength, and maxFreq use constant space → O(1).
    * No additional data structures grow with input size.
    */


    int characterReplacement(string s, int k) {
        
        //Step-1: Intialize variables and data structures
        int n = s.length();

        int left = 0;
        
        int maxLength = 0;//to store the output
        int maxFreq = 0;//to store the freq of curr char

        vector<int> freq(26, 0); //frequency array to check how many times occured

        //Step-2: Expand the sliding window
        for(int right = 0; right < n; right++){
            
            //Step-3: Update the freq of current char
            freq[s[right] - 'A']++;

            //Step-4: Update maximum frequency of a character
            maxFreq = max(maxFreq, freq[s[right] - 'A']);


            //Step-5: Shrink the window if replacement exceeds k
            while((right - left + 1) - maxFreq > k){
                
                freq[s[left] - 'A']--; //decrease freq of leftmost char
                left++;//move left pointer to shrink the size of window
            }

            //Step-6: Update maxLength
            maxLength = max(maxLength, right - left + 1);

        }

        //Step-7: Finally return the output
        return maxLength;
    }
};