class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        //2.) Optimal Approach(Prefix Sum + unordered_map)
        int n = arr.size() ;
        int count = 0 ; //count var to store ans subarrays
        
        vector<int> prefixSum(n,0) ; //to store prefixSum
        prefixSum[0] = arr[0] ;//initialize with arr[0]
        
        //prefixSum starts from index 1 so, i=1 to n
        for(int i=1; i<n ; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i] ;
        }
        //unordered_map to store (prefixSum, freq)
        unordered_map<int,int> m ;

        for(int j=0 ; j<n ; j++){
            if(prefixSum[j] == k) count ++ ;
            int val = prefixSum[j] - k ; //to find val = PS[i-1]

            //check if found val
            if(m.find(val) != m.end()){
               count += m[val] ; //if found then add
            }

            //check if not found prefixSum
            if(m.find(prefixSum[j]) == m.end()){
                m[prefixSum[j]] = 0 ; //then store in map
            }
            m[prefixSum[j]]++ ; //update by 1
        }

        return count ; //return no. of ans subarrays

    }
};