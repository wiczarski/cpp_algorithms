#include <string>

using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        string perm(s.size(), '0');
        int once_count = 0;
        for(int i = 0; i < t.size(); i++){
            once_count += (t[i] == '1');
        }
        for(int i = 0; i < s.size(); i++) {
            if (once_count > 0) {
                if (s[i] == '0'){
                    perm[i] = '1';
                    once_count--;
                }
            }
        }
        int b_index = s.size() - 1;
        while(once_count > 0){
            if (s[b_index] == '1'){
                perm[b_index] = '1';
                once_count--;
            }
            b_index--;
        }
        for(int i = 0; i < s.size(); i++) {
            if (((s[i] - '0') + (perm[i] - '0')) == 1) perm[i] = '1';
            else perm[i] = '0';
        }
        return perm;
    }
};