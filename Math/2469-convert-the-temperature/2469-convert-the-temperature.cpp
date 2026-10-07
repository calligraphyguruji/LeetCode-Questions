class Solution {
public:
    //Approach : Direct Calculation

    //Time Complexity = O(1) =>
    /* No loops are being used.
    */

    //Space Complexity = O(1) =>
    /* ans array is of constant size
    * no matter what the input size is.
    */
     
    vector<double> convertTemperature(double celsius) {
        
        vector<double> ans(2); //to store the output array => size = 2
    
        double kelvin, fahrenheit;

        kelvin = celsius + 273.15;

        fahrenheit = celsius * 1.80 + 32.00;
        
        ans[0] = kelvin; //0th index is kelvin
        ans[1] = fahrenheit; //1st index is fahrenheit
       
        //finally return the output
        return ans;

    }
};