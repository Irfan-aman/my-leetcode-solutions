class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0 , j = 0;
        int ans=0 , oneFreq=0;
        while(j<n){
            if(nums[j]==1) oneFreq++;
            while( (j-i+1)-oneFreq >k ){
                if(nums[i]==1) oneFreq--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};