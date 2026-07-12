class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<pair<int,int>> mp;
        for(int i=0;i<arr.size();i++){
            mp.push_back({arr[i],i});
        }
        sort(mp.begin(),mp.end());
        int p=mp[0].first;
        arr[mp[0].second]=1;
        for(int i=1;i<arr.size();i++){
            if(p==mp[i].first){
                arr[mp[i].second]=arr[mp[i-1].second];
            }else {
                arr[mp[i].second]=arr[mp[i-1].second]+1;
                p=mp[i].first;
            }
        }
        return arr;
    }
};