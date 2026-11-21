class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> vec = {a, b, c};
        sort(vec.begin(), vec.end());
        return min(vec[1], vec[2] - vec[0]);
    }
};