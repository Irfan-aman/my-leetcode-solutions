class Solution {
public:
    int prodOfDig(int n) {
        int pod = 1;
        while (n) {
            if (n % 10 == 0)
                return 0;
            pod *= n % 10;
            n /= 10;
        }
        return pod;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while (ans <= 100) {
            int pod = prodOfDig(ans);
            if (pod == 0 || pod % t == 0)
                return ans;
            ans++;
        }
        return ans;
    }
};