class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int p =1;//prefix product
        int s=1;//suffix product
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            p *=nums[i];
            s*=nums[n-i-1];
            ans=max(ans,max(p,s));
            if(p==0 || s==0){
                p=(p==0)?1:p;
                s=(s==0)?1:s;
            }
        }
        return ans;
    }
};