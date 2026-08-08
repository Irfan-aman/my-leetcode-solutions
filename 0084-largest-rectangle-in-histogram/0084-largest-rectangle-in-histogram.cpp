class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> nsr(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            nsr[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        vector<int> nsl(n, 0);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            nsl[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (nsr[i] - nsl[i] - 1));
        }
        return maxArea;
    }
};