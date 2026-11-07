class Solution {
public:
    //Approach : Event-Driven Simulation with Two Min-Heaps

    //Time Complexity = O((n + m) log(n + 1)) =>
    /* Initialize: Your code pushes the n servers into free one at a time, costing O(n log(n + 1)).
    Assign and release: Each task causes one pop from free and one push into busy. Each assignment can also cause at most one later release. So even though releaseFinished() contains a while loop, that loop runs at most m times in total across all tasks.
    Heap cost: Each push or pop costs O(log(n + 1)) because a heap holds at most n servers. The approach page’s O(n + m log(n + 1)) bound assumes the initial heap is built in O(n) using heapify.
    */

    //Space Complexity = O(n) =>
    /* Each server is in either free or busy, so the heaps hold at most n entries combined.
    * Including the output array ans, total space is O(n + m).
    */


    typedef pair<int, int> F;
    typedef pair<long long, int>B;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        //1.) Intialize required datastructures (two min-Heaps, ans array)
        priority_queue<F, vector<F>, greater<F> >free; //{weight, index}

        priority_queue<B, vector<B>, greater<B> >busy; //{finish_time, index}

        vector<int> ans(tasks.size());//to store the output

        //2.) Put all servers in free and set t = 0
        for(int i = 0; i < servers.size(); i++){

            free.push({servers[i], i});
        }
        
        long long t = 0;

        //func. to Move every server with finish time <= t to Free
        auto releaseFinished = [&](){

            while(!busy.empty() && busy.top().first <= t){
                
                int index = busy.top().second;
                busy.pop();
                free.push({servers[index], index});
            }
        };

        //3.) For each task j in order, set t = max(t, j)
        for(int j = 0; j < tasks.size(); j++){
            
            t = max(t, static_cast<long long>(j));

            //Move every server with finish time <= t to Free
            releaseFinished();

            //4.) If Free is empty, jump to the earliest finish and repeat step 3.
            if(free.empty()){
                t = busy.top().first;
                releaseFinished();
            }

            //5.) Pop the top of free, record its index, and push it into busy
            int index = free.top().second;
            free.pop();
            ans[j] = index;

            busy.push({t + tasks[j], index});
        }

        //6.) After all tasks, return output
        return ans;

        
    }
};