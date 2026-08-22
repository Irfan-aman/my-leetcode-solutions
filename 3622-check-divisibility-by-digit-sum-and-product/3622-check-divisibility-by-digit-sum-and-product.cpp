class Solution {
public:
    bool checkDivisibility(int n) {
        int digSum = 0;
        int digProd = 1;
        int x = n;
        while (x) {
            int lastDig = x % 10;
            digSum += lastDig;
            digProd *= lastDig;
            x /= 10;
        }
        return (n % (digSum + digProd)) == 0;
    }
};