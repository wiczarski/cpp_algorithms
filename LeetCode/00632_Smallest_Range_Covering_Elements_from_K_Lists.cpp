#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // heap element: (value, listId, indexInLIst)
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int current_max = INT_MIN;
        int current_min;

        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i][0], i, 0);
            current_max = max(current_max, nums[i][0]);
        }

        int bestLeft = get<0>(pq.top());
        int bestRight = current_max;

        while(true) {
            auto [val, listId, indexInList] = pq.top();
            pq.pop();
            current_min = val;

            if (current_max - current_min < bestRight - bestLeft) {
                bestLeft = current_min;
                bestRight = current_max;
            }

            bool endOfList = indexInList + 1 >= nums[listId].size();
            if (endOfList) break;

            pq.emplace(nums[listId][indexInList + 1], listId, indexInList + 1);
            current_max = max(current_max, nums[listId][indexInList + 1]);

        }

        return {bestLeft, bestRight};
    }
};