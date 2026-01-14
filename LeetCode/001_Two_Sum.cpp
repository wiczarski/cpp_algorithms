#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < (int)nums.size(); i++) {
            int curValue = nums[i];
            int complement = target - curValue;

            auto found = seen.find(complement);
            if (found != seen.end()) {
                return {found->second, i};
            }

            seen[curValue] = i;
        }

        return {};
    }
};