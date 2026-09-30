class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        int d = 0; // current Depth
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                d++;
                res[i] = ((d & 1) == 1) ? 1 : 0;
            } else {
                res[i] = ((d & 1) == 1) ? 1 : 0;
                d--;
            }
        }
        return res;
    }
};