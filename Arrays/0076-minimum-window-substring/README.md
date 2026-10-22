<h2><a href="https://leetcode.com/problems/minimum-window-substring">76. Minimum Window Substring</a></h2><h3>Hard</h3><hr><p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window</strong></em> <span data-keyword="substring-nonempty"><strong><em>substring</em></strong></span><em> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window</em>. If there is no such substring, return <em>the empty string </em><code>&quot;&quot;</code>.</p>

<p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ADOBECODEBANC&quot;, t = &quot;ABC&quot;
<strong>Output:</strong> &quot;BANC&quot;
<strong>Explanation:</strong> The minimum window substring &quot;BANC&quot; includes &#39;A&#39;, &#39;B&#39;, and &#39;C&#39; from string t.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;, t = &quot;a&quot;
<strong>Output:</strong> &quot;a&quot;
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;, t = &quot;aa&quot;
<strong>Output:</strong> &quot;&quot;
<strong>Explanation:</strong> Both &#39;a&#39;s from t must be included in the window.
Since the largest window of s only has one &#39;a&#39;, return empty string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>n == t.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?</p>


<!-- AUTO-GENERATED-SOLUTION-START -->
---

## 🧠 Visual Solution & Intuition

### Part 1

![Minimum Window Substring — Part 1](./images/solution-part-1.jpg)

### Part 2

![Minimum Window Substring — Part 2](./images/solution-part-2.jpg)

### Part 3

![Minimum Window Substring — Part 3](./images/solution-part-3.jpg)

---

## ⏱️ Complexity Analysis

```text
Time Complexity = O(N) => cause traversing each char single time in s (n chars)
Space Complexity = O(1) => cause both mapT & mapS freq. vectors take constant space.
```

---

## 💻 C++ Solution

[View Original C++ File](./0076-minimum-window-substring.cpp)

```cpp
class Solution {
public:
    //Time Complexity = O(N) => cause traversing each char single time in s (n chars)
    //Space Complexity = O(1) => cause both mapT & mapS freq. vectors take constant space.
    bool contains(vector<int> &mapS, vector<int> &mapT){
        for(int i=0 ; i<256 ; i++){
            if(mapT[i] > mapS[i]){ //freq of mapT is greater then
                return false ; //freq not matched
            }
        }
        //if doesn't return false in above loop then
        return true ; 
    }
    string minWindow(string s, string t) {
        //two freq maps(vector)
        vector<int> mapT(256,0) ;
        vector<int> mapS(256,0) ;
       
       //fill mapT with all the chars. present in t
       for(char ch : t) mapT[ch]++ ;

       int left = 0 , right = 0 , minLength = INT_MAX , minStart = 0 ;

       //start making window and push that char in mapS
       for( ; right < s.length() ; right++){
          mapS[s[right]]++ ;

           //now compare mapT and mapS 
           while(contains(mapS,mapT)){
             if(right-left+1 < minLength){
                minLength = right-left+1 ;
                minStart = left ; //update minStart to reduce the size of window
             }
             mapS[s[left++]]-- ; //reduce the size from left
           }
       }
       
       //if minLength is still INT_MAX means no minLength found then return "" (empty substr)
       //else return substr of minlength
       return minLength == INT_MAX ? "" : s.substr(minStart,minLength) ;



    }
};
```

<!-- AUTO-GENERATED-SOLUTION-END -->
