// very poor CPU and Memory performance

class RecentCounter {
public:
    int requests;
    int last_time;
    vector<int> old_times;
    vector<int> cur_times;
    RecentCounter() : last_time(0) {}

    int ping(int t) {
        int diff = t - last_time;
        cur_times.push_back(0);
        for (int i = 0; i < old_times.size(); i++) {
            if (old_times[i] + diff <= 3000) {
                cur_times.push_back(old_times[i] + diff);
            }
        }
        last_time = t;
        int answer = cur_times.size();
        old_times = move(cur_times);
        return answer;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */