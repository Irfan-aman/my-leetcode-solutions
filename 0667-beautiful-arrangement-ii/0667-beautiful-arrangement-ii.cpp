class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n,0);
        int low=1 , high=n;
        int idx=0;
        ans[idx++]=low++;
        bool isHigh=false;
        while(k>1){
            ans[idx++]=high--;
            k--;
            isHigh=true;
            if(k>1){
                ans[idx++]=low++;
                isHigh=false;
                k--;
            }
        }
        while(idx<n){
            if(isHigh){
                ans[idx++]=high--;
            }else ans[idx++]=low++;
        }
        return ans;
    }
};