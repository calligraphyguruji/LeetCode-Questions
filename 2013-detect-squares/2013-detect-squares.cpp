class DetectSquares {
public:

    // Coordinates are in [0, 1000], so x * 1001 + y is a unique key.
    unordered_map<int, int> freq;

    // Return a coordinate's frequency without inserting missing points.
    int getFreq(int x, int y){

        auto it = freq.find(x * 1001 + y);
        return it == freq.end() ? 0 : it->second;
    }

    DetectSquares() { //when object will be made constructor will be called and 
        // Step 1: Start with an empty frequency map.
    }
    
    void add(vector<int> point) {
        // Step 2: Store each occurrence, including duplicates.
        int x = point[0];
        int y = point[1];

        freq[x * 1001 + y]++;
    }
    
    int count(vector<int> point) {
        
        int x = point[0];
        int y = point[1];

        long long ans = 0;

        // Step 3: Try each distinct stored coordinate as the
        // corner diagonally opposite the query point.
        for(auto& entry : freq){

            int a = entry.first / 1001;
            int b = entry.first % 1001;

            int diagonalFreq = entry.second;

            // Step 4: A square needs equal, nonzero side lengths.
            if(a == x || abs(a - x) != abs(b - y)){
                continue;
            }

            // Step 5: The diagonal forces the other two corners
            // to be (a, y) and (x, b)
            int corner1Freq = getFreq(a, y);
            int corner2Freq = getFreq(x, b);

            // Step 6: Multiply the independent choices of copies
            // at all three stored corners.
            ans += 1LL * diagonalFreq * corner1Freq * corner2Freq;
        }


        // Step 7: Return the total number of valid selections.
        return static_cast<int>(ans);


    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */