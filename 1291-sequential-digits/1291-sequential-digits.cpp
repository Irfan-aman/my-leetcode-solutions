class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty() && q.front()<=high){
            int t=q.front();
            q.pop();
            if(t>=low)ans.push_back(t);
            int dig=t%10;
            if(dig<9){
                q.push(t*10+(dig+1));
            }
        }
        return ans;
    }
};