class Solution {
public:
       
    int totalMoney(int n) {
        
        int money = 0;
        int monday = 1;//on first monday he adds $1

        for(int i = 1; i <= n; i++){
            
            money += monday + (i - 1) % 7; //deposit increases $1 each day, from monday to sunday (monday = $1, tuesday = $2, wed = $3, ...and so on)
            
            if(i % 7 == 0){
                monday++; //after first monday he increases deposit by +$1 on every next monday
            }
            
        }
        
        //finally return the output
        return money;
    }
};