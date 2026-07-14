class Solution {
public:
    int MOD=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>> prev(maxi+1,vector<int>(maxi+1,0));
        for(int first=1;first<=maxi;first++){
            for(int second=1;second<=maxi;second++){
                if(first==second)prev[first][second]=1;
                else prev[first][second]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(maxi+1,vector<int>(maxi+1,0));
            for(int first=maxi;first>=0;first--){
                for(int second=maxi;second>=0;second--){
                    int skip=prev[first][second];
                    int take1=prev[__gcd(first,nums[i])][second];
                    int take2=prev[first][__gcd(second,nums[i])];
                    curr[first][second] =(0LL+skip+take1+take2)%MOD;
                }
            }
            prev=move(curr);
        }
        return prev[0][0];
    }
};