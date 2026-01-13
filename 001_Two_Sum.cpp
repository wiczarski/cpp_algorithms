#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < (int)nums.size(); i++) {
            int value = nums[i];
            int need = target - value;

            auto found = seen.find(need);
            if (found != seen.end()) {
                return {found->second, i};
            }

            seen[value] = i;
        }

        return {};
            
    }
};