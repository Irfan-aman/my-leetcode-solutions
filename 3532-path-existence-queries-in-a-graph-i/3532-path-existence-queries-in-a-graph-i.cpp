class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,0);//Component of each node
        comp[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                comp[i]=comp[i-1];//Abs diff is <= maxDiff ,so there is edge b/w them hence having same compon
            }else comp[i]=comp[i-1]+1;                  
        }
        vector<bool> ans;
        for(auto &it:queries){
            ans.push_back(comp[it[0]]==comp[it[1]]);
        }
        return ans;
    }
};