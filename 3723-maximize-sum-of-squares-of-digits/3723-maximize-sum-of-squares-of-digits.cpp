class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        int total_9 = sum / 9;
        int rem = sum % 9;
        res.append(total_9, '9');
        if (rem > 0)
            res.push_back(rem + '0');
        if (res.size() > num)
            return "";
        if (res.size() != num) {
            res.append(num - res.size(), '0');
        }
        return res;
    }
};