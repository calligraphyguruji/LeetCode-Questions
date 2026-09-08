class Solution {
public:
    void nextPermutation(vector<int>& A) {
        //Laziness approach to get 2.5 LPA job 
        //after learning C++ STL 
        next_permutation(A.begin(), A.end()) ;
    }    
};