class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
      
    int idx = m+n-1 , i = m-1 , j = n-1 ;
    //Time Complexity = O(n+m)
    //backward loop
    while(i >= 0 && j >= 0){

        if(A[i] > B[j]){ //if A[i] is greater then
            A[idx--] = A[i--] ;// move A[i] to correct position
        }
        else{ //if B[j] is greater then
            A[idx--] = B[j--] ;//Replace and merge B[j] in A[idx]
        }

     }

    while(j >= 0){ //edge case when i < 0 but j >= 0

        A[idx--] = B[j--] ;
     }


    }
};