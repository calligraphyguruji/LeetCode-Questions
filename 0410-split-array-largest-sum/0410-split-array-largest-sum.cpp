class Solution {
public:
    
    bool isValid(vector<int>& arr, int m, int maxAllowed) {
        int students = 1;
        int pages = 0;
        //Time Complexity = O(n)
        for(int i = 0; i < arr.size(); i++) {
            
            // If a single element is greater than maxAllowed
            if(arr[i] > maxAllowed) 
                return false;

            if(pages + arr[i] <= maxAllowed) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }

        return students > m ? false : true ;
    }

    int splitArray(vector<int>& arr, int m) { 
        //Time Complexity = O(logN * n)

        int n = arr.size();
        if(m > n) return -1;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }

        int st = 0, end = sum;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(isValid(arr, m, mid)) { //move to left 
                ans = mid;
                end = mid - 1;  // try smaller maximum
            } else { //move to right (if invalid)
                st = mid + 1;   // increase allowed sum
            }
        }

        return ans;
    }
};