class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    int compress(vector<char>& chars) {
        int n = chars.size() ;
        int idx = 0 ; //new index to store 

        for(int i=0 ; i<n ; i++){
            char ch = chars[i] ; //assign ch to current chars[i]
            int count = 0 ;
            //Step 1 : identify continuous chars
            while(i < n && chars[i] == ch){
                count++ ; i++ ;
            }

            //Step 2 : check count to replace in chars[]
            if(count == 1){ //if count == 1
                chars[idx++] = ch ; //then nothing change just replace
            }
            else{ // if count > 1
                chars[idx++] = ch ; //replace ch
                string str = to_string(count) ; //make count to string

                for(char dig : str){
                    chars[idx++] = dig ; //replace count string
                }
            }

            i-- ; //to encounter i++
        }
        //resize the chars acc to current idx
        chars.resize(idx) ;
        return idx ;

    }
};