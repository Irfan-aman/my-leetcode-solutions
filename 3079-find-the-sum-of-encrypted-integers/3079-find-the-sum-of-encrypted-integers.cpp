class Solution {
public:
    int encrypt(int x) {
        int dig = 0;
        int maxi = 1;
        while (x) {
            maxi = max(maxi, x % 10);
            dig++;
            x /= 10;
        }
        int encrypt = 0;
        while (dig--) {
            encrypt = encrypt * 10 + maxi;
        }
        return encrypt;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int& x : nums) {
            sum += encrypt(x);
        }
        return sum;
    }
};