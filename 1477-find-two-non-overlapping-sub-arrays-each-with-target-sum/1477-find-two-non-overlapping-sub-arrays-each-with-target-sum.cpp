class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLenTillIdx(n, INT_MAX);
        int i = 0, j = 0;
        int currSum = 0, bestMin = INT_MAX;
        int res = INT_MAX;
        while (j < n) {
            currSum += arr[j];
            while (currSum > target) {
                currSum -= arr[i++];
            }
            if (currSum == target) {
                int len = j - i + 1;
                if (i > 0 && minLenTillIdx[i - 1] != INT_MAX) {
                    res = min(res, len + minLenTillIdx[i - 1]);
                }
                bestMin = min(bestMin, len);
            }
            minLenTillIdx[j] = bestMin;
            j++;
        }
        return res == INT_MAX ? -1 : res;
    }
};