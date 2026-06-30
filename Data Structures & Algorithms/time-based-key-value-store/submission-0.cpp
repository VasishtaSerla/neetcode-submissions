class TimeMap {
            unordered_map<string,vector<pair<int,string>>>m;
            string last;

public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
     m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        last = "";
        int left = 0, right = m[key].size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(m[key][mid].first <= timestamp){
                last = m[key][mid].second;
                left = mid+1;
            }
            else right = mid-1;
        }
        return last;
    }
};