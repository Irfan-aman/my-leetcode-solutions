class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int st=i+1 , end=n-1;
            while(st < end){
                int sum=nums[i] + nums[st] + nums[end];
                if ( abs(sum-target) < abs(ans-target)) {
                    ans=sum;
                }
                if(sum==target) return target;
                else if(sum<target) st++;
                else end--;
            }
        }
        return ans;
    }
};