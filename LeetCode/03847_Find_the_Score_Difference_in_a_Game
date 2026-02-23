#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first_player_score = 0;
        int second_player_score = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) cur ^= 1;
            if (i % 6 == 5) cur ^= 1;
            if (cur) second_player_score += nums[i];
            else first_player_score += nums[i];
        }
        return first_player_score - second_player_score;
    }
};