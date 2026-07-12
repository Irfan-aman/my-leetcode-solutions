class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<pair<int,int>> mp;//mp =<value,idx> = <arr[i],i>
        for(int i=0;i<arr.size();i++){
            mp.push_back({arr[i],i});
        }
        sort(mp.begin(),mp.end());
        arr[mp[0].second]=1;
        for(int i=1;i<arr.size();i++){
            if(mp[i].first==mp[i-1].first){
                arr[mp[i].second]=arr[mp[i-1].second];
            }else {
                arr[mp[i].second]=arr[mp[i-1].second]+1;
            }
        }
        return arr;
    }
};