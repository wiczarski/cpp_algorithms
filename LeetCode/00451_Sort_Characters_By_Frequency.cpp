#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // ASCII 48 - 122 (range: 75)
        const int eps = 48;
        int signs[75] = {};
        for(int i = 0; i < s.size(); i++) {
            signs[(char)s[i] - eps]++;
        }
        // letters number, index
        pair<int, int> signs_counted[75];
        for(int i = 0; i < 75; i++) {
            signs_counted[i] = {signs[i], i};
        }
        sort(signs_counted, signs_counted + 75, greater<pair<int,int>>());
        string result = "";
        for(int i = 0; i < 75; i++){
            char sign = (char)(signs_counted[i].second + eps);
            for(int j = 0; j < signs_counted[i].first; j++){
                result += sign;
            }
        }
        return result;
    }
};