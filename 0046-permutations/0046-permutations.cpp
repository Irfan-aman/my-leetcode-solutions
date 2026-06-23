class Solution {
public:
    void solve(vector<int>nums,vector<int>& v,vector<vector<int>>& ans){
        int n=nums.size();
        if(n==0){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
            vector<int> temp=nums;
            temp.erase(temp.begin()+i);
            solve(temp,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,v,ans);
        return ans;
    }
};