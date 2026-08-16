class Solution {
public:
    //This is the hardest problem to me till now
    //Don't jump directly to this problem
    //Strengthen your basics first

    //Method : MITM(Meet in the Middle) Approach

    //Time Complexity = O(n * 2^n)
    //Space Complexity = O(2^n)
    int minimumDifference(vector<int>& nums) {
        
        int N = nums.size() ;

        int Sum = accumulate(begin(nums), end(nums), 0) ; //Sum of nums array

        int n = N/2 ; 

        int n1 = n ; //leftSide
        int n2 = n ; //rightSide

        //1.) make sumsLeft map : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsLeft ;

        for(int mask=0 ; mask < (1 << n1) ; mask++){ // 1<<n1 = 2^n1
            int s = 0 ; //subset sum
            int count = 0 ; 
            
            for(int i=0 ; i<n1 ; i++){
                if(mask & (1 << i) ){
                    s += nums[i] ;
                    count++ ;
                }
            }

            sumsLeft[count].push_back(s) ;
        }

        //2.) make sumsRight map : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsRight ;
        
        for(int mask=0 ; mask < (1 << n1) ; mask++){ // 1<<n1 = 2^n1
            int s = 0 ; //subset sum
            int count = 0 ; 
            
            for(int i=0 ; i<n1 ; i++){
                if(mask & (1 << i) ){
                    s += nums[n1 + i] ;
                    count++ ;
                }
            }

            sumsRight[count].push_back(s) ;
        }

        //3.) Sort the right subset also
        for(int count = 0 ; count <= n2 ; count++){
            //sumsRight[count] => vector of subset sum having subset of size count
            sort(begin(sumsRight[count]), end(sumsRight[count]) ) ;
        }

        //4.) find abs(2 *sum1 - Sum) = minValue
        int minValue = INT_MAX ;

        //check for every k size in leftside then in rightSide n-k size
        for(int k=0 ; k<n1 ; k++){
            int m = n-k ;

            //check in map sumsLeft
            for(int leftSubSum : sumsLeft[k] ){
                int needRight = (Sum - 2*leftSubSum) / 2 ;
                
                //with formula value of needRight check in map using lower_bound
                int low = lower_bound(begin(sumsRight[m]), end(sumsRight[m]), needRight) - begin(sumsRight[m]) ; //index value 

                //check if low is out of bound
                if(low < sumsRight[m].size() ){
                    int rightSubSum = sumsRight[m][low] ;

                    minValue = min(minValue, abs(2*(leftSubSum + rightSubSum) - Sum) ) ;
                }

                if(low-1 < sumsRight[m].size()){
                    int rightSubSum = sumsRight[m][low-1] ;

                    minValue = min(minValue, abs(2*(leftSubSum + rightSubSum) - Sum) ) ;
                }
            }
        }


        //finally return the minimum value
        return minValue ;
        
    }
};