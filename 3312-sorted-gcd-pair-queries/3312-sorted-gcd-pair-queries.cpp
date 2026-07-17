class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> factorFreq(maxi+1,0);
        for(int &x:nums){
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    factorFreq[i]++;
                    if(x/i != i){
                        factorFreq[x/i]++;
                    }
                }
            }
        }
        vector<long long> gcdPairCount(maxi+1);
        for(int i=maxi;i>=1;i--){
            long long cnt=factorFreq[i];
            gcdPairCount[i]= cnt*(cnt-1)/2;
            //delete extra pair counted
            for(int j=i*2;j<=maxi;j +=i){
                gcdPairCount[i] -= gcdPairCount[j];
            }
        }
        vector<long long> prefPair(maxi+1);
        for(int i=1;i<=maxi;i++){
            prefPair[i]= gcdPairCount[i] + prefPair[i-1];
        }
        vector<int> ans;
        for(auto &x:queries){
            int l=1 , r=maxi;
            int temp=0;
            while(l<=r){
                int mid_gcd= l+(r-l)/2;
                if(prefPair[mid_gcd]>x){
                    temp=mid_gcd;
                    r=mid_gcd-1;
                }else l=mid_gcd+1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};