class Solution {
public:
    //Time Complexity = O(n*m*logK) 
    //Space Complexity = O(k) => only storing k elements in the priority queue
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq ; //max Heap

        int n = matrix.size() ; //row size
        int m = matrix[0].size() ; //col size

        //traverse the 2d matrix and push
        //when size > k then pop
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                pq.push(matrix[i][j]) ;
                
                if(pq.size() > k)
                      pq.pop() ;
            }
        }

      //very important to return the ans that is pq.top()
      return pq.top() ;
    }
};