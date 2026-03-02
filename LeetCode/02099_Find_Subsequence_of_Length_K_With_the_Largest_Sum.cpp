#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // pair {value, index}
        using P = pair<int, int>;
        vector<P> paired_nums;
        paired_nums.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            paired_nums.emplace_back(nums[i], i);
        }

        sort(paired_nums.begin(), paired_nums.end(), greater<P>());

        paired_nums.resize(k);

        sort(paired_nums.begin(), paired_nums.end(), [](const P &a, const P &b){
            return a.second < b.second;
        });

        vector<int> answer;
        answer.reserve(k);
        for(int i = 0; i < k; i++) {
            answer.push_back(paired_nums[i].first);
        }

        return answer;
    }
};