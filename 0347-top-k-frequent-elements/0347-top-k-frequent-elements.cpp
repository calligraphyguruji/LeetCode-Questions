class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> ans; //to store the output

        unordered_map<int,int> freqMap; //store the (value -> freq)

        //Step-1: Count frequency of each element
        for(int i = 0; i < n; i++){

            //store the freq. of each in map
            freqMap[nums[i]]++;
        }

        //Step-2: minHeap priority queue to 
        priority_queue<P, vector<P>, greater<P>> pq;

        //Step-3: traverse the map and push only top k elements in priority queue
        for(auto& it : freqMap){
            
            int num = it.first;//first column is number
            int freq = it.second;//second column is frequency

            pq.push({freq, num});//push in minHeap

            if(pq.size() > k){ //when pq is full
                pq.pop();//pop the topmost element that is minimum
            }
        }

        //Step-4: Extract top k freq elements
        while(!pq.empty()){
            ans.push_back(pq.top().second);//top element is most freq element

            pq.pop(); //after inserting in ans pop from pq
        }

        //finally return the output
        return ans;
    }
};