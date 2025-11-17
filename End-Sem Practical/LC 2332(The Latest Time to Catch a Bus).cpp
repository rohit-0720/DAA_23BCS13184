class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int p = 0;  
        int m = passengers.size();
        
        for (int b : buses) {
            int cnt = 0;
            while (p < m && passengers[p] <= b && cnt < capacity) {
                p++;
                cnt++;
            }
            if (b == buses.back()) {
                int candidate;
                
                if (cnt < capacity) {
                    candidate = b;
                } else {
                    candidate = passengers[p - 1] - 1;
                }
                
                unordered_set<int> taken(passengers.begin(), passengers.end());
                while (taken.count(candidate)) {
                    candidate--;
                }
                
                return candidate;
            }
        }
        
        return -1;
    }
};
