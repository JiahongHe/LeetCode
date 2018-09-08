class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        if (N == 0) return 0;
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= N; i++) {
            int curHeight = i == N ? 0 : heights[i];
            while (!s.empty() && curHeight < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int start = s.empty() ? -1 : s.top();
                int area = (i - start - 1) * height;
                maxArea = max(maxArea, area);
            }
            s.push(i);
        }
        return maxArea;
    }
};