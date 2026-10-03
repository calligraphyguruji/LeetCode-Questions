class Solution {
public:
    //Approach : Distance Tracking/ Graph Traversal

    //Time Complexity = O(n) =>
    /* There are 3 main traversals:
    1. Traverse from node1: O(n)
    2. Traverse from node2: O(n)
    3. Traverse all nodes to find the answer: O(n)   
    */

    //Space Complexity = O(n) =>
    /* We use two distance arrays:
    * Each contains n elements:
    * dist1 → O(n)
    * dist2 → O(n)
    */

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();

        //1.) Distance arrays
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);

        //2.)Find distances from node1
        int curr = node1;
        int distance = 0;
        
        while(curr != -1 && dist1[curr] == -1){
            dist1[curr] = distance;
            distance++;

            curr = edges[curr];//move to edges current
        }

        //3.)Find distances from node2
        curr = node2;
        distance = 0;
        
        while(curr != -1 && dist2[curr] == -1){
            dist2[curr] = distance;
            distance++;

            curr = edges[curr];//move to edges current
        }

        //4.)Find the best common node
        int ans = -1;
        int minMaxDist = INT_MAX;

        for(int i = 0; i < n; i++){
            //5.) Both nodes must be able to reach i
            if(dist1[i] != -1 && dist2[i] != -1){
                
                //6.) Take the larger of the two distances
                int maxDist = max(dist1[i], dist2[i]);

                //7.) Keep the node having min.
                if(maxDist < minMaxDist){
                    minMaxDist = maxDist;
                    ans = i;
                }
            }
        }

        //finally return the output
        return ans;

    }
};