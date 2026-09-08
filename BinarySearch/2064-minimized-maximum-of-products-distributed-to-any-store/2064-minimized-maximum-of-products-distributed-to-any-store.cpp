class Solution {
public:
   //Time Complexity = O(n * log(MaxValue)) => O(log(MaxValue)) for binary search , O(n) for isPossibleAns function .
   //Space Complexity = O(1)
    bool isPossibleAns(int mid, vector<int>& quantities, int stores){ //Time Complexity = O(n)
        //Note x = mid => written mid for no confusion

        //iterate on quantities to check possible ans
        for(int &products : quantities){

            stores -= (products + mid -1)/mid ; //to calculate products on each store 

            if(stores < 0){
                return false ;
            }
        }

        //if passed all the checks in above loop then mark true
        return true ;
    }
    int minimizedMaximum(int n, vector<int>& quantities) { //O(n * log(MaxValue))
        int m = quantities.size() ; 

        int st = 1 ; 
        int hi = *max_element(begin(quantities), end(quantities)) ;//end = max(quantities)
       //beware you can't name variable end in above
       //int end = *max_element(begin(quantities), end(quantities)) ;
        int ans = 0 ; 

        while(st <= hi){ //Time Complexity = O(log(MaxValue))
            int mid = st + (hi-st)/2 ;

            if(isPossibleAns(mid,quantities,n)){
                ans = mid ; //if ans found then store and check for more min.
                hi = mid-1 ; //move in left to check more min. ans
            }
            else{  //if not possible ans
                st = mid+1 ; //then move to right to max. the value
            }
        }

        return ans ;
    }
};