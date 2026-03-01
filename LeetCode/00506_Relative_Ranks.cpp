#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // tuple<score, index, rank>
        using T = tuple<int, int, string>;
        vector<T> temp_t(score.size());

        for (int i = 0; i < score.size(); i++) {
            temp_t[i] = T(score[i], i, "");
        }

        sort(temp_t.begin(), temp_t.end(), greater<>());

        for(int i = 0; i < temp_t.size(); i++) {
            if (i == 0) get<2>(temp_t[0]) = "Gold Medal";
            else if (i == 1) get<2>(temp_t[1]) = "Silver Medal";
            else if (i == 2) get<2>(temp_t[2]) = "Bronze Medal";
            else get<2>(temp_t[i]) = to_string(i + 1);
        }
        
        sort(temp_t.begin(), temp_t.end(), [](const T &a, const T &b) {
            return get<1>(a) < get<1>(b);
        });

        vector<string> answer(score.size());
        for(int i = 0; i < temp_t.size(); i++) {
            answer[i] = get<2>(temp_t[i]);
        }

        return answer;
    }
};