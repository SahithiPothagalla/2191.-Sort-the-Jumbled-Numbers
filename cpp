class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> mapped(nums.size());
        unordered_map<int, list<int>> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            int idx = 1;
            int mapped_number = 0;
            while (number > 0) {
                int remainder = number % 10;
                mapped_number += mapping[remainder] * idx;
                number /= 10;
                idx *= 10;
            }
            if (nums[i] == 0) {
                mapped_number = mapping[0];
            }
            mapped[i] = mapped_number;
            num_map[mapped[i]].push_back(nums[i]);
        }
        vector<int> sorted_mapped = mapped;
        sort(sorted_mapped.begin(), sorted_mapped.end());
        int idx = 0;
        for (int value : sorted_mapped) {
            if (num_map.find(value) != num_map.end()) {
                for (int val : num_map[value]) {
                    nums[idx++] = val;
                }
                num_map.erase(value);
            }
        }
        return nums;
    }
};
