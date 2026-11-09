class Solution {
public:
    //Approach : Min-Heap + Ordered Set Simulation

    //Time Complexity = O((n+k) * log(k+1)) =>
    /* Initialization — Insert k server IDs into the ordered set one at a time. This takes \(O(k\log(k+1))\).
    * Process requests — Each accepted request adds one heap entry, and that entry is popped at most once. So the while loop performs at most n pops across all requests. * Heap and ordered-set operations give \(O(n\log(k+1))\) total.
    * Collect the answer — Find the maximum count and collect the tied IDs in \(O(k)\).
    */

    //Space Complexity = O(k) =>
    /* Each server is tracked either in the free set or in the busy heap, so together they hold at most k entries.
    * The counts array stores k integers. The output list can also hold up to k IDs if all servers tie.
    */


    typedef pair<int, int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    
        //1.) Initialize required set, min-heap, array
        set<int> free;

        priority_queue<P, vector<P>, greater<P>> busy; //{finish_time, server_id}

        vector<int> counts(k, 0);//filled with k zeros

        //2.) Put all server IDs from 0 to k-1 in free
        for(int server = 0; server < k; server++){
            free.insert(server);
        }

        //3.) Process arrivals in order
        int n = static_cast<int>(arrival.size());

        for(int i = 0; i < n; i++){

            int time = arrival[i];

            //pop every (finishTime, serverID) with finishTime <= t from busy
            while(!busy.empty() && busy.top().first <= time){
                free.insert(busy.top().second);//insert its ID into free
                busy.pop();
            }

            //4.)Choose or drop:

            //if free is emtpy
            if(free.empty()){
                continue;//drop this request
            }

            //otherwise
            //use lower_bound(i % k) to find the smallest free ID at or above the starting ID
            auto it = free.lower_bound(i % k);

            if(it == free.end()){
                it = free.begin();// Wrap to the smallest free ID.
            }
             
            //5.) Record the assignment
            // Remove the chosen ID from free, increment its count, and push (t + load[i], serverID) into busy
            int server = *it;
            free.erase(it);

            counts[server]++;
            busy.emplace(time + load[i], server); //{finish time, server_d}
        }

        //6.) Return the busiest IDs
        // Find the maximum count and collect every server with that count.

        int maxCount = *max_element(counts.begin(), counts.end());

        vector<int> ans;//to store the output

        for(int server = 0; server < k; server++){

            if(counts[server] == maxCount){
                
                ans.push_back(server);
            }
        }
        
        return ans;

    }
};