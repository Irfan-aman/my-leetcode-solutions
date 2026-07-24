class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;//xor of all pair
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> ans;
        for(auto &it:s){
            for(int &x:nums){
                ans.insert(it^x);
            }
        }
        return ans.size();
    }
};