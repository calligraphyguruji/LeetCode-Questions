class Solution {
public: 
    //Time Complexity = O(n) => cause pushing and popping only n elements 
    //Space Complexity = O(n) => cause using map , queue
    int firstUniqChar(string s) {
        unordered_map<char,int> m ; //to store frequency of repeating
        queue <int> q ; //to store unique elements

        for(int i=0 ; i<s.size() ; i++){
            //check char is unique
            if(m.find(s[i]) == m.end()){
                q.push(i) ;
            }
            m[s[i]]++ ; //update for next

            //remove repeating elements from queue
            while(!q.empty() && m[s[q.front()]] > 1){
                q.pop() ; //if freq > 1 then pop
            }
        }

        //if queue is empty then ans = -1
        //else ans = q.front
        return q.empty() ? -1 : q.front() ; //ternary statement for above checks

    }
};