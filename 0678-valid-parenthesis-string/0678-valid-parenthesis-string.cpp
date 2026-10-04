class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> openIdx, lastStarIdx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                openIdx.push(i);
            else if (s[i] == ')') {
                if (!openIdx.empty())
                    openIdx.pop();
                else if (!lastStarIdx.empty()) {
                    lastStarIdx.pop();
                } else
                    return false;
            } else {
                lastStarIdx.push(i);
            }
        }
        while (!openIdx.empty() && !lastStarIdx.empty() &&
               openIdx.top() < lastStarIdx.top()) {
            lastStarIdx.pop();
            openIdx.pop();
        }
        return openIdx.empty();
    }
};