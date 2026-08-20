class Solution {
public:
    //Method : Dp + 3 Pointers Approach

    //Time Complexity = O(n)
    //Space Complexity = O(n)
    int nthUglyNumber(int n) {
        //make ugly no.s array call t
        vector<int> t(n+1) ; //size = n+1
        //t[i] = ith ugly no.

        int i2, i3, i5 ; 

        i2 = i3 = i5 = 1 ; //initial state pointing to 1

        t[1] = 1; //first element is 1

        for(int i=2 ; i<= n ; i++){
           int i2Ugly = t[i2]* 2; 

           int i3Ugly = t[i3]* 3;

           int i5Ugly = t[i5]* 5 ;

           int minUgly = min({i2Ugly, i3Ugly, i5Ugly}) ;

           t[i] = minUgly ;

           //i2, i3, i5 jis se minUgly select hoga woh increment by 1
            if(minUgly == i2Ugly){
              i2++;
            }

            if(minUgly == i3Ugly){
               i3++;
            }

            if(minUgly == i5Ugly){
                i5++;
            }

        }

        

        return t[n] ; //nth ugly no.
    }
};