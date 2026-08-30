class Solution {
public:
    //Method-2 : min-Heap 
    int findKthLargest(vector<int>& nums, int k) {
        //1.)Take min-Heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        //2.) push elements in minHeap
        for(int &n : nums){
            
            minHeap.push(n);

            //3.)if size > k => pop()
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }


        //4.) finally return the top most element
        return minHeap.top();
    }
};