#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        using P = pair<int, string>;
        unordered_map<string, int> map;
        for(int i = 0; i < words.size(); i++){
            map[words[i]]++;
        }

        vector<P> counted_words;
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            auto found = map.find(word);
            if (found != map.end() && found->second > 0){
                counted_words.push_back({map[word], word});
                map[word] = 0;
            }
        }

        auto cmp = [](const P &a, const P &b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };

        nth_element(counted_words.begin(), counted_words.begin() + (k - 1), counted_words.end(), cmp);
        counted_words.resize(k);

        sort(counted_words.begin(), counted_words.end(), cmp);

        vector<string> answer;
        answer.reserve(k);
        for(int i = 0; i < k; i++){
            answer.push_back(counted_words[i].second);
        }

        return answer;
    }
};