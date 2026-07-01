class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int ans = 0 ,cnt=0;
        int oddCnt=0;
        while (j < n) {
            oddCnt += (nums[j]&1 ==1)?1:0;
            cnt=(nums[j]&1 ==1)?0:cnt;
            while(oddCnt==k){
                cnt++;
                if(nums[i]&1 ==1) oddCnt--;
                i++;
            }
            ans +=cnt;
            j++;
        }
        return ans;
    }
};