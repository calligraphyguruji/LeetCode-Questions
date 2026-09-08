class Solution {
public:
    //Recursive Method 
    int binarySearch(vector<int> &arr, int tar, int st , int end){
        int mid = st + (end-st)/2 ;

        if(st <= end){
            if(arr[mid] < tar){
                return binarySearch(arr,tar,mid+1,end) ;
                //st = mid+1 => move right
            }
            else if(arr[mid] > tar){
                return binarySearch(arr,tar,st,mid-1) ;
                //end = mid-1 => move left
            }
            else{ //arr[mid] == tar
                return mid ;
            }
        }
        
        return -1 ; //if not found 
    }
    int search(vector<int>& arr, int tar) {
        int n = arr.size() ;
        return binarySearch(arr,tar,0,n-1) ; 
        //here return is required to call because int type
        //st = 0 , end = n-1 ;
        
    }
    
};