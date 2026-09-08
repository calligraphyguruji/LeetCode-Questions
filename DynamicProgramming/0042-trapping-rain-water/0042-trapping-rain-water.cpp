class Solution {
public:
     //Time Complexity = O(n) => single 2 pointer loop
     //Space Complexity = O(1) => no extra data structure used.
    int trap(vector<int>& ht) {
        int n = ht.size() ;
        int ans = 0 ;
        //2 pointer approach : left , right
        int l = 0 , r = n-1 ;
        int lmax = 0 , rmax = 0 ;

        while(l < r){
            lmax = max(lmax, ht[l]) ;
            rmax = max(rmax, ht[r]) ;

            //check min of rmax, lmax
            if(lmax < rmax){
                ans += (lmax - ht[l]) ;
                l++ ; //update by +1
            }
            else{
                ans += (rmax - ht[r]) ;
                r-- ; //update by -1
            }
        }

        return ans ; //very important to return the ans

    }
};