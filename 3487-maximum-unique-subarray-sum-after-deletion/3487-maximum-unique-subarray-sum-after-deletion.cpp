class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int sum=0;
        int maxi=*(max_element(nums.begin(),nums.end()));
        for(int &x:nums){
            if(x<=0 || s.count(x))continue;
            s.insert(x);
            sum+=x;
        }
        if(maxi<=0)return maxi;
        return sum;
    }
};