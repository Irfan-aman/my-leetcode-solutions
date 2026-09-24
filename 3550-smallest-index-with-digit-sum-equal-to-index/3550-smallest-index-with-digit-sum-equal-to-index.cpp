class Solution {
public:
    int sumofDigits(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int res = 102;
        for (int i = 0; i < nums.size(); i++) {
            int sumofDig = sumofDigits(nums[i]);
            if (sumofDig == i) {
                res = min(res, i);
            }
        }
        return res == 102 ? -1 : res;
    }
};