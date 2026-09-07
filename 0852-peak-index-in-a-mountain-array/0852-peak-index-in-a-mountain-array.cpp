class Solution {
public:
    //Time Complexity = O(logn)
    //Space Complexity = O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() ; //size operator
        int st = 1 , end = n-2 ; //handle edgecases when mid = 0 or n 

        while ( st <= end ){
             int mid = st + (end-st)/2 ;

          if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
               return mid ;
          }
          else if (arr[mid-1] < arr[mid]){ //inc order (peak in right)
               st = mid + 1 ;
          }
          else { //dec order after the peak(peak in left)
               end = mid - 1 ;
               
          }

      } 
      return -1 ; /*bekar si line if not found (that will never execute because there always exist a mountain array and a peak index) */           
    }
};