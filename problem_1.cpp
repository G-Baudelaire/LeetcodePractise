#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> match = {};
        for (int i = 0; i < nums.size(); i++) {
            auto it = match.find(target - nums[i]);
            if (it != match.end()) {
                return {it->second, i};
            }

            it = match.find(nums[i]);
            if (it == match.end()) {
                match.insert({nums[i], i});
            }
        }
        return {0, 0};
    }
};
