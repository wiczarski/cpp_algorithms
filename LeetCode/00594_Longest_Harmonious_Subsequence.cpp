#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counts;
        // counts.reserve(nums.size() * 2); // saves CPU but uses more Memory

        for (int n : nums) counts[n]++;

        int best = 0;
        for (auto &p : counts) {
            if (counts.count(p.first + 1)) {
                best = max(best, p.second + counts[p.first + 1]);
            }
        }

        return best;
    }
};