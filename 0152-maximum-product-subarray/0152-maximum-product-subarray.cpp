class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int p =1;//prefix product
        int ans=INT_MIN;
        for(auto &x:nums){
            p *=x;
            ans=max(ans,p);
            if(p==0){
                p=1;
            }
        }
        int s=1;//suffix product
        for(int i=n-1;i>=0;i--){
            s*=nums[i];
            ans=max(ans,s);
            if(s==0) s=1;
        }
        return ans;
    }
};