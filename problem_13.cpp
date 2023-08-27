#include <string>
#include <unordered_map>

class Solution {
    const std::unordered_map<std::string, int> single_values = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000}
    };

    const std::unordered_map<std::string, int> double_values = {
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900},
    };

public:
    int romanToInt(const std::string& s) {
        return romanToIntWithAccumulator(s, 0);
    }

private:
    int romanToIntWithAccumulator(const std::string& s, int acc) {
        if (s.empty()) {
            return acc;
        }
        else if (s.size() == 1) {
            int value = single_values.at(s);
            return acc + value;
        }
        else {
            auto it = double_values.find(s.substr(0,2));

            if (it != double_values.end()) {
                return romanToIntWithAccumulator(s.substr(2), acc + it->second);
            }
            else {
                return romanToIntWithAccumulator(s.substr(1), acc + single_values.at(s.substr(0, 1)));
            }
        }
    }
};