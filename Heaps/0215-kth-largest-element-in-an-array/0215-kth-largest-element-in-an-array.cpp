class Solution {
public:
    //Method-2 : min-Heap =>
    //Time Complexity = O(n * logK) =>
    /* There are n elements in nums, so the loop runs n times.
        minHeap.push(n)
        A heap insertion takes:
        O(log k)
        Why log k and not log n?
        Because we never allow the heap to contain more than k elements.
        if(minHeap.size() > k)
            minHeap.pop();

    */

    //Space Complexity = O(k) => cause storing k elements in the Heap

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