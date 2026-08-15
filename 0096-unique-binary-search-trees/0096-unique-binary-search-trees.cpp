class Solution {
public:
    //Method-3 : Catalan Number

    //Time Complexity = O(n)
    //Space Complexity = O(1)
     
    int catalan(int n) {

        long long ans = 1;

        for(int i = 0; i < n; i++) {
            ans = ans * (2 * i + 1) * 2 / (i + 2);
        }

        return ans;

    }
    int numTrees(int n) {
        
        //func. call to find nth catalan
        return catalan(n) ;
    }
};