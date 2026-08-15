class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0 , zeroCnt=0;
        for(int &x:nums){
            if(x==0)zeroCnt++;
            ans^=x;
        }
        if(zeroCnt==n)return 0;
        return (ans!=0)?n:n-1;
    }
};