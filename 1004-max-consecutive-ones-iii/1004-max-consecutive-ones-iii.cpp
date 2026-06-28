class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0 , j = 0;
        int ans=0 , zeroF=0;
        while(j<n){
            if(nums[j]==0) zeroF++;
            while( zeroF >k ){
                if(nums[i]==0) zeroF--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};