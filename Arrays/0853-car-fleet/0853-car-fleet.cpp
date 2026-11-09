class Solution {
public:
    //Approach : Sorting + Greedy (Right-to-Left Scan)

    //Time Complexity = O(n * logn) =>
    /* Building cars with push_back() takes O(n)
    * sorting takes O(n * logn)
    * the greedy scan takes O(n)
    */
 
    //Space Complexity = O(n) =>
    /* Cars vector stores upto n elements : O(n)
    * Variables = O(1)
    */


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        //1.) Sort (position, speed) by decreasing order
        vector<pair<int, int>> cars;

        for(size_t i = 0; i < speed.size(); i++){
            
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());//decreasing order

        //2.) Initialize fleet count and arrival time
        int fleets = 0;
        double fleetTime = 0.0;

        for(const auto& [start, mph] : cars){

            //3.) Calculate soloTime when car won't join any fleet
            double soloTime = static_cast<double>(target - start)/mph;

            // Step 4. A later arrival creates a fleet. An equal or earlier
            // arrival means the car joins the fleet ahead.
            if(soloTime > fleetTime){
                fleets++;
                fleetTime = soloTime;
            }

        }

        //5.) Return the total fleet counts
        return fleets;

    }
};