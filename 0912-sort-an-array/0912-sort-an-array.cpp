class Solution {
public:
    void heapify(vector<int>& arr, int n, int i){
        //largest as root
        int largest = i ;

        int left = 2*i + 1 ; //left index
        int right = 2*i + 2 ; //right index

        //Case-1 : if left child is larger than root
        if(left < n && arr[left] > arr[largest]){
            largest = left ;
        }

        //Case-2 : if right chil is larger than root
        if(right < n && arr[right] > arr[largest]){
            largest = right ;
        }

        //Case-3 : if largest is not root
        if(largest != i){
            swap(arr[i],arr[largest]) ;

            heapify(arr, n, largest) ;
        }

    }
    void heapSort(vector<int>& arr){
        int n = arr.size() ;

        //Build the heap
        for(int i = n/2 - 1 ; i >= 0 ; i--){
            heapify(arr,n,i) ;
        }

        //one by one extraction of element from the heap
        for(int i = n-1 ; i > 0 ; i--){
            
            //move curr to end
            swap(arr[0], arr[i]) ;

            //heapify on rest
            heapify(arr, i, 0) ;
        }
    }
    vector<int> sortArray(vector<int>& arr) {
        
        heapSort(arr) ;

        return arr ;//return the ans array
    }
};