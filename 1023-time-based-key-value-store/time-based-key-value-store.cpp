class TimeMap {
public:
   unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }

    // Simply push_back since timestamps are strictly increasing
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // If key doesn't exist
        if (!mp.count(key)) return "";

        auto &arr = mp[key];
        int left = 0, right = arr.size() - 1;
        string ans = "";

        // Binary search for largest timestamp <= given timestamp
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;  // possible candidate
                left = mid + 1;         // try to find a larger timestamp
            } else {
                right = mid - 1;
            }
        }

        return ans;  // empty string if no valid timestamp found
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */