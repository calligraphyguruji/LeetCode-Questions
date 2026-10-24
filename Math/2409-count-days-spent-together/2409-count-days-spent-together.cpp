class Solution {
public:
    //Approach : Date Conversion + Interval Intersection

    //Time Complexity = O(1) =>
    /* 1. Month Days Array: Initializing an array of 12 elements takes O(1) time.
    2. String Parsing: substr() and stoi() process fixed-length date strings ("MM-DD"), taking O(1) time.
    3. Date Conversion: The getDay() function loops through at most 11 months, taking O(1) time.
    4. Four Date Conversions: Calling getDay() four times takes 4 × O(1) = O(1).
    5. Interval Intersection: Finding max() and min() and calculating overlapping days takes O(1) time.
    */
 
    //Space Complexity = O(1) =>
    /* 1. Month Days Array: Stores exactly 12 integers → O(1).
    2. Date Variables: month, day, and totalDays use constant space → O(1).
    3. Converted Dates: Four integer variables store the converted dates → O(1).
    4. Overlap Variables: overlapStart, overlapEnd, and ans use constant space → O(1).
    5. No Extra Data Structures: No dynamically growing arrays, sets, or maps are used.
    */


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