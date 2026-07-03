class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i+1;
        }
        for(int i=1;i<k;i++){
            reverse(ans.begin()+i,ans.end());
        }
        return ans;
    }
};