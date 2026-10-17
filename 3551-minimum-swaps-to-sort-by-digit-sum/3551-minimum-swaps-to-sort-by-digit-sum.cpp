class Solution {
public:
    int findSumOfDigits(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end(), [this](const int& a, const int& b) {
            int digA = findSumOfDigits(a);
            int digB = findSumOfDigits(b);
            if (digA == digB) {
                return a < b;
            }
            return digA < digB;
        });
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i])
                continue;
            int idxOfNums_i = mp[sorted[i]];
            int x = nums[i];
            swap(nums[i], nums[idxOfNums_i]);
            mp[nums[i]] = i;
            mp[x] = idxOfNums_i;
            swaps++;
        }
        return swaps;
    }
};