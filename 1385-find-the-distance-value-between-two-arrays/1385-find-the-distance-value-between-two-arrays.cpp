class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distVal = 0;
        int n = arr2.size();
        for (int i = 0; i < arr1.size(); i++) {
            int j =
                lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            if (j == 0) {
                distVal += arr2[0] - arr1[i] > d;
            } else if (j >= n) {
                distVal += arr1[i] - arr2[n - 1] > d;
            } else if (arr2[j] - arr1[i] > d && arr1[i] - arr2[j - 1] > d) {
                distVal++;
            }
        }
        return distVal;
    }
};