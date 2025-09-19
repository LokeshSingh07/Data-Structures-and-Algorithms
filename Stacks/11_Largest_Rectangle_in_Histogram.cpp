// 84. Largest Rectangle in Histogram


class Solution {
public:
    void NSEL(vector<int> &nums, vector<int> &prev){
        int n = nums.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if(!st.empty()) prev[i] = st.top();

            st.push(i);
        }
    }

    void NSER(vector<int> &nums, vector<int> &next){
        int n = nums.size();
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if(!st.empty()) next[i] = st.top();

            st.push(i);
        }
    }



    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        
        NSEL(heights, prev);
        NSER(heights, next);

        int maxArea = 0;
        for(int i=0; i<n; i++){
            int H = heights[i];
            int W = next[i] - prev[i] - 1;
            int area = H*W;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};