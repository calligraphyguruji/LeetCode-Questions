class Solution {
public:
    int getDay(string date){

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};

        int month = stoi(date.substr(0, 2)); //substr(start, length)
        int day = stoi(date.substr(3, 2));

        int totalDays = day;//first add the days of current month

        for(int i = 0; i < month-1; i++){
            totalDays += days[i];//add days of previous months
        }

        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        //Step-1: Convert days into numbers
        int startAlice = getDay(arriveAlice);
        int endAlice = getDay(leaveAlice);

        int startBob = getDay(arriveBob);
        int endBob = getDay(leaveBob);

        //Step-2: Find overlapping start
        int overlapStart = max(startAlice, startBob);

        //Step-3: Find overlapping end
        int overlapEnd = min(endAlice, endBob);

        //Step-4 : Calc. ans
        int ans = max(0, overlapEnd - overlapStart + 1);

        //Step-5 : finally return the answer
        return ans;
    }
};