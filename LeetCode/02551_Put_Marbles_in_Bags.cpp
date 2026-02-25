#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> neighbours_sums;
        neighbours_sums.reserve(weights.size() - 1);
        for (int i = 0; i < weights.size() - 1; i++){
            neighbours_sums.push_back(weights[i] + weights[i + 1]);
        }
        sort(neighbours_sums.begin(), neighbours_sums.end());
        long long result = 0;
        for (int i = 0; i < k - 1; i++) {
            result += neighbours_sums[neighbours_sums.size() - 1 - i] - neighbours_sums[i];
        }
        return result;
    }
};