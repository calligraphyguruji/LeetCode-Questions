class Solution {
public:
    typedef long long ll;

    ll M = 1e9 + 7; //10^9 + 7

    vector<vector<ll>> PT;//Pascal's triangle

    int solve(vector<int>& nums){

        int n = nums.size();

        //edge-case
        if(n <= 2){
            return 1;
        }

        int root = nums[0]; //first element is always root

        vector<int> leftSub, rightSub;

        for(int i = 1; i < n; i++){

            if(nums[i] < root){
                leftSub.push_back(nums[i]);
            }

            else{
                rightSub.push_back(nums[i]);
            }
        }

        ll x = solve(leftSub) % M;
        ll y = solve(rightSub) % M;

        ll z = PT[n-1][leftSub.size()] % M; //n-1C(left.size())

        return (x * y % M) * z % M;
    }
    int numOfWays(vector<int>& nums) {
        
        int n = nums.size();

        PT.resize(n+1);
        
        //Filling Pascal's triangle 
        for(int i = 0; i < n; i++){

            PT[i] = vector<ll>(i+1, 1);//size of row = i+1, filled with 1

            for(int j = 1; j < i; j++){

                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]) % M; //up + diagonal left
            }
        }

        //finally return the output = x*y*z - 1
       return (solve(nums) - 1 + M) % M;
    }
};