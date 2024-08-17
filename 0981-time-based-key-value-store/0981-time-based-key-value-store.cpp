#include <string>
#include <unordered_map>
#include <vector>


using namespace std;
class TimeMap {
public:


    string searchValue(vector<pair<int, string>>& values, int timestamp) {

        int l = 0, r = values.size() - 1;

        string res = "";

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (values[mid].first == timestamp) return values[mid].second;

            else if (values[mid].first < timestamp) {
                res = values[mid].second;
                l = mid + 1;
            }

            else r = mid - 1;

        }

        return res;

    }

    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return searchValue(map[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */