class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxE=*max_element(begin(nums),end(nums));
        int T=1;
        while(T<=maxE) T<<=1;
        vector<bool> s1(T,false);
        vector<bool> s2(T,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<T;i++){
            if(s1[i]){
                for(int &x:nums){
                    s2[i^x]=true;
                }
            }
        }
        return count(s2.begin(),s2.end(),true);
    }
};