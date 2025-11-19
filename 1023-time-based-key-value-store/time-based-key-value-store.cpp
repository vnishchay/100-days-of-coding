class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp; 
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        // Check if key exists
        if (mp.find(key) == mp.end()) {
            return "";
        }
        
        auto& values = mp[key];
        
        // Binary search for the largest timestamp <= given timestamp
        int left = 0, right = values.size() - 1;
        string result = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                result = values[mid].second;  // Update result
                left = mid + 1;  // Try to find a larger timestamp
            } else {
                right = mid - 1;  // Look in the left half
            }
        }
        
        return result;
    }
};