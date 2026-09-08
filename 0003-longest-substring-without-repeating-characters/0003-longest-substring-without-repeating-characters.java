class Solution {
    //Time Complexity = O(n) => cause traversing whole string on n elements once
    //Space Complexity = O(1) => cause charSet(HashSet) is of only 256 chars (constant space) .


    //Method : 2 Pointer Approach (left, right)
    public int lengthOfLongestSubstring(String s) {
        //create a Hashset of chars.
        Set<Character> charSet = new HashSet<>() ;

        int maxLength = 0 ;
        int left = 0 ; //initialize left with 0 idx
        //make a moving right pointer with loop
        for(int right = 0 ; right<s.length(); right++){

            //check if repeating element then remove
            while(charSet.contains(s.charAt(right))){
                charSet.remove(s.charAt(left)) ; //removing form Hashset
                left++ ; //update the left 
            }

            charSet.add(s.charAt(right)) ;
            maxLength = Math.max(maxLength, (right-left + 1)) ;
        }

        return maxLength ; //length of longest non repeating substring
    }
}