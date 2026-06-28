class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int st=0 , end=height.size()-1;
        while(st<end){
            ans=max(ans, min(height[st],height[end])*(end-st));
            if(height[st]<height[end]) st++;
            else end--;
        }
        return ans;
    }
};