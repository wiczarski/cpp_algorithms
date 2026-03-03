#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        rows.reserve(mat.size());
        for(int i = 0; i < mat.size(); i++) {
            // faster alternative to accumulate()
            int row_sum = lower_bound(mat[i].begin(), mat[i].end(), 0, greater<int>()) - mat[i].begin();
            rows.push_back({row_sum, i});
        }
        nth_element(rows.begin(), rows.begin() + (k - 1), rows.end());
        rows.reserve(k);
        sort(rows.begin(), rows.end());
        vector<int> answer;
        answer.reserve(k);
        for (int i = 0; i < k; i++) answer.push_back(rows[i].second);
        return answer;
    }
};