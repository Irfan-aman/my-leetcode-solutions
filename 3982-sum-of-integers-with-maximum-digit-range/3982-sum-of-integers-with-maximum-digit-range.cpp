class Solution {
public:
    int digRange(int m) {
    if (m == 0) return 0;
    int minDig = 9, maxDig = 0;
        while (m) {
            int dig = m % 10;
            minDig = min(minDig, dig);
            maxDig = max(maxDig, dig);
            m /= 10;
        }
        return maxDig-minDig;
    }
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int ans=0;
        for (int& x : nums) {
            int diff=digRange(x);
            if(diff > maxDiff){
                maxDiff=diff;
                ans=x;
            }else if(diff==maxDiff){
                ans += x;
            }
        }
        return ans;
    }
};