class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    int maxArea(vector<int>& height) {
       int n = height.size() ;
    
    int maxWater = 0 ;
    int left = 0, right = n-1 ;
    
    while(left < right){
        
      int  width = right-left ;
        
      int ht = min(height[left], height[right]) ;
        
      int  currWater = width*ht ;
        
        maxWater = max(maxWater,currWater) ;
       
       height[left] < height[right] ? left++ : right-- ;
       //ternary operator to check cases in single line
       //favorite replacement of if else sometimes
        
    }
    
    return maxWater ; 
    }
};