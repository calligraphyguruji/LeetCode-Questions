class ProductOfNumbers {
public:

    vector<int> prod;//to store the product of last k numbers

    ProductOfNumbers() {
        prod = {1}; //Base Multiplier 1
    }

    void add(int num) {
        
        if(num == 0){//if number is zero then
            
            prod = {1};//reset the stream
        }

        else{
            prod.push_back(prod.back() * num);
        }
    }
    
    int getProduct(int k) {
        
        int n = prod.size() - 1;

        // If k covers past reset point, zero was in window
        if(k > n){
            return 0;
        }

        return prod[n] / prod[n-k]; // Product of last k elements in O(1)       
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */