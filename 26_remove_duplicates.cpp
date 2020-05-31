class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int num0 = nums[0];
        int count = 1;
        for (auto it = nums.begin() + 1; it != nums.end();) {
            if ((*it) == num0) {
                it = nums.erase(it);
            } else {
                num0 = *it;
                count += 1;
                ++it;
            }
        }
        return count;
    }
                                                                                                                                                                        };