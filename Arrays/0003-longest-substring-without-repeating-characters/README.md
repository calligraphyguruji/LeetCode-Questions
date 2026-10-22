<h2><a href="https://leetcode.com/problems/longest-substring-without-repeating-characters">3. Longest Substring Without Repeating Characters</a></h2><h3>Medium</h3><hr><p>Given a string <code>s</code>, find the length of the <strong>longest</strong> <span data-keyword="substring-nonempty"><strong>substring</strong></span> without duplicate characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcabcbb&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The answer is &quot;abc&quot;, with the length of 3. Note that <code>&quot;bca&quot;</code> and <code>&quot;cab&quot;</code> are also correct answers.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bbbbb&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The answer is &quot;b&quot;, with the length of 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pwwkew&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> The answer is &quot;wke&quot;, with the length of 3.
Notice that the answer must be a substring, &quot;pwke&quot; is a subsequence and not a substring.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of English letters, digits, symbols and spaces.</li>
</ul>


<!-- AUTO-GENERATED-SOLUTION-START -->
---

## 🧠 Visual Solution & Intuition

![Longest Substring Without Repeating Characters — Visual Solution](./images/solution.jpg)

---

## ⏱️ Complexity Analysis

```text
Time Complexity = O(n) => cause traversing whole string on n elements once
Space Complexity = O(1) => cause charSet(HashSet) is of only 256 chars (constant space) .
```

---

## 💻 Java Solution

[View Original Java File](./0003-longest-substring-without-repeating-characters.java)

```java
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
```

<!-- AUTO-GENERATED-SOLUTION-END -->
