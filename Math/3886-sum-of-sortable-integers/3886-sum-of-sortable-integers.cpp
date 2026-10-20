class Solution {
public:
    // !DISCLAIMER : NOT FOR BEGINNERS
    
    //Approach : Sorting + Divisor Enumeration + KMP-Based Cyclic Rotation Matching

    //Time Complexity = O(n log n + n × d(n)) =>
    /* Sorting the array: O(n log n).
    * Checking possible divisors: O(n).
    * For each valid divisor k:
        * Number of blocks = n/k.
        * KMP matching per block = O(k).
        * Total = (n/k) × O(k) = O(n).
    * Checking all divisors = O(n × d(n)).
    */

    //Space Complexity = O(n) =>
    /* Sorted array: O(n).
    * Temporary blocks: O(k).
    * LPS array: O(k).
    * Maximum k = n.
    */


    //Build LPS array
    vector<int> buildLPS(vector<int>& pattern){
        int m = pattern.size();

        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else if(len != 0){
                len = lps[len -1];
            }

            else{
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }
    bool KMPMatch(vector<int>& vec1, vector<int>& vec2){
        int n = vec1.size();

        if(n != vec2.size()) return false;

        if(n == 0) return true;

        //Step-1: Build Lps for vec2
        vector<int> lps = buildLPS(vec2);

        //Step-2: KMP Search
        int i = 0, j = 0;

        while(i < 2*n - 1){
            
            if(vec1[i % n] == vec2[j]){
                i++;
                j++;

                if(j == n) return true;
            }

            else if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        int result = 0;

        vector<int> sorted = nums;

        //1.) Sort the array
        sort(sorted.begin(), sorted.end());


        //2.) 
        for(int k = 1; k <= n; k++){

            if(n % k != 0) continue;//skip

            //check if k is valid
            bool validK = true;

            for(int st = 0; st < n; st += k){

                //block = st....st+k-1

                //nums block k
                vector<int> vec1(nums.begin() + st, nums.begin() + st + k);
                //sorted block k
                vector<int> vec2(sorted.begin() + st, sorted.begin() + st + k);

                if(!KMPMatch(vec1, vec2)){
                    validK = false;
                    break;
                }
            }

            //check if k is valid
            if(validK){
                result += k;
            }
        }

        //finally return the result
        return result;
        
    }
};