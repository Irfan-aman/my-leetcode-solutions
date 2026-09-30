class Solution {
public:
    int maxDepth(string& seq) {
        int maxi = 0, curr = 0;
        for (char& ch : seq) {
            if (ch == '(')
                curr++;
            else
                curr--;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int maxDep = maxDepth(seq);
        int half = maxDep / 2;
        vector<int> res;
        int depOfa = 0, depOfb = 0;
        int currA = 0, currB = 0;
        for (char& ch : seq) {
            if (ch == '(') {
                if (currA < half) {
                    res.push_back(0);
                    currA++;
                    depOfa = max(depOfa, currA);
                } else {
                    res.push_back(1);
                    currB++;
                    depOfb = max(depOfb, currB);
                }
            } else {
                if (currB > 0) {
                    res.push_back(1);
                    currB--;
                } else {
                    res.push_back(0);
                    currA--;
                }
            }
        }
        return res;
    }
};