class Solution {
public:
    //Approach : BFS + 6 water jug cases

    //Time Complexity = O(x * y) =>
    /* Maximum possible states = (x + 1) × (y + 1).
    * Each state represents the amount of water (a, b) in the two jugs.
    * BFS visits each state at most once using visited.
    * For every state, we generate only 6 possible transitions → constant work.
    * Therefore, TC = O(x × y).
    */

    //Space Complexity = O(x * y) => 
    /* visited stores information for all possible (a, b) states → O(x × y).
    * BFS queue can also contain up to O(x × y) states.
    * Therefore, SC = O(x × y).
    */

    bool canMeasureWater(int x, int y, int target) {
        //1.)base-case or edge-case
        if(x + y < target){
            return false;
        }

        //2.) Start BFS from (0, 0) = (x = 0, y = 0)
        vector<vector<bool>> visited(x+1, vector<bool>(y+1, false));//initialize all with false
        queue<pair<int, int>> q;

        q.push({0, 0}); //initial state        
        visited[0][0] = true;

        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            
            //check if target reached
            if(a + b == target){
                return true;
            }

            vector<pair<int, int>> nextStates;

            //1.) Fill x jug
            nextStates.push_back({x, b});

            //2.) Fill y jug
            nextStates.push_back({a, y});

            //3.) Empty x jug
            nextStates.push_back({0, b});

            //4.) Empty y jug
            nextStates.push_back({a, 0});

            //5.) Pour x -> y jug
            int d = min(a, y-b);

            nextStates.push_back({a-d, b+d});

            //6.) Pour y -> x jug
            d = min(b, x-a);

            nextStates.push_back({a+d, b-d});

            //add unvisited states
            for(auto& state : nextStates){
                int newA = state.first;
                int newB = state.second;

                if(!visited[newA][newB]){

                    visited[newA][newB] = true;
                    q.push({newA, newB});
                }
            }

        }

        //if in above steps no true found
        return false;        

    }
};