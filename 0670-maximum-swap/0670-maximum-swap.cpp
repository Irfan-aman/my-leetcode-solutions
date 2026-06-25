class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        for(int i=0;i<s.size()-1;i++){
            int max=i+1;
            for(int j=i+2;j<s.size();j++){
                if(s[j]>=s[max]){
                    max=j;
                }
            }
            if(s[i]<s[max]){
                swap(s[i],s[max]);
                break;
            }
        }
        return stoi(s);
    }
};