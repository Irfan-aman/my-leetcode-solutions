class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0 ,oddCnt=0;
        unordered_map<int,int> mp;//<oddCnt,freq>
        mp[0]=1;
        for(int &x:nums){
            if((x&1)==1){
                oddCnt++;
            }
            if(mp.count(oddCnt-k)){
                ans+=mp[oddCnt-k];
            }
            mp[oddCnt]++;
        }
        return ans;
    }
};