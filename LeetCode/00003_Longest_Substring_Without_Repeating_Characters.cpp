#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int letters[256];
        fill(letters, letters + 256, -1);
        int start_index = 0;
        int end_index = 0;
        int max_length = 0;
        int letter_code = 0;
        int cur_letter_index = 0;
        for(int i = 0; i < s.size(); i++){
            letter_code = (unsigned char)s[i];
            cur_letter_index = letters[letter_code];
            if (cur_letter_index >= start_index && cur_letter_index <= end_index){
                start_index = cur_letter_index + 1;
            }
            end_index = i;
            max_length = max((end_index - start_index + 1), max_length);
            letters[letter_code] = i;
        }
        return max_length;
    }
};