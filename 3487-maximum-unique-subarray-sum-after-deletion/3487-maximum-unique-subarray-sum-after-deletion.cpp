class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        vector<bool> seen(101,false); //0 to 100
        for(int &x:nums){
            maxi=max(maxi,x);
            if(x<=0 || seen[x])continue;
            seen[x]=true;
            sum+=x;
        }
        if(maxi<=0)return maxi;
        return sum;
    }
};