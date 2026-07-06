class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=n;
        sort(intervals.begin(),intervals.end(),cmp);
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            int y=intervals[i][1];
            if(y<=end) ans--;
            else {
                end=y;
            }
        }
        return ans;
    }
};