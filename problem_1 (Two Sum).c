//
// Created by Germain Jones on 25/08/2023.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_INPUT_LENGTH 10000;

struct TargetPair {
    int integer_from_list;
    int addition_for_target;
};

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    struct TargetPair TargetPairs[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        TargetPairs[i]nums[i]
    }
    TargetPairs[]
};

int main() {
    int *nums[4] = {2, 7, 11, 15};
    int *returnSize[2] = {0, 1};
    twoSum(*nums, 4, 9, *returnSize);
    return 0;
};