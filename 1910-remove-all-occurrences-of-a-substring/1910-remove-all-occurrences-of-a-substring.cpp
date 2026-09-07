class Solution {
public:
    //Time Complexity = O([n/m] * [n x m]) =>  One iteration: O(n × m)
    // => total iterations = n/m
    //Space Complexity = O(1) => no extra data structures are used.
    string removeOccurrences(string s, string part) {
      /*Step-1 : str.find(part) < str.length() => 
       returns a valid index if found .

       Step-2 : str.erase(st,end) => removes find part
       here st = s.find(part) and end = part.length()

        */  
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase( s.find(part), part.length() ) ;
        }
        return s ; //because we made all changes in original string 
    }
};