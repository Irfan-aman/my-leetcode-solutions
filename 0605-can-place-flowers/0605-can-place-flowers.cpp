class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l=flowerbed.size();
        if(n==0 ) return true;
        for(int i=0;i<l;i++){
            if(!flowerbed[i]){
                bool left=(i==0)|| !flowerbed[i-1] ;
                bool right=(i==l-1) || !flowerbed[i+1];
                if(left && right){
                    flowerbed[i]=1;
                    n--;
                    if(n==0) return true;
                }
            }
        }
        return false;
    }
};