class Solution {
public:
    int largestPrime(int n) {
        if(n==1)return 0;
        if (n == 2)
            return 2;
        vector<bool> prime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        int sum = 0, ans = 0;
        ;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                sum += i;
                if (sum > n) {
                    break;
                }
                if (prime[sum]) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};