class Solution {
public:
    int prodOfDig(int n) {
        int prod = 1;
        while (n) {
            if (n % 10 == 0)
                return 0;
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while (true) {
            int pod = prodOfDig(ans); // product of digits
            if (pod == 0 || pod % t == 0)
                return ans;
            ans++;
        }
        return ans;
    }
};