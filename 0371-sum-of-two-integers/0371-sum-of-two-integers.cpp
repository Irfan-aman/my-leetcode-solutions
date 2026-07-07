class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int temp = a;
            a = a ^ b;        //sum= a ^ b;
            b = (temp & b) << 1;// carry = (a & b)<<1 ;
        }
        return a;
    }
};

// int getSum(int a, int b) {
//     int sum = a ^ b;
//     int carry = (a & b) << 1;
//     while (carry) {
//         int temp = sum;
//         sum = sum ^ carry;
//         carry = (temp & carry) << 1;
//     }
//     return sum;
// }