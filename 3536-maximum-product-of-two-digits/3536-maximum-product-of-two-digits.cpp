class Solution {
public:
    int maxProduct(int n) {
        string nums=to_string(n);
        sort(begin(nums),end(nums),greater<char>());
        return (nums[0]-'0')*(nums[1]-'0');
    }
};