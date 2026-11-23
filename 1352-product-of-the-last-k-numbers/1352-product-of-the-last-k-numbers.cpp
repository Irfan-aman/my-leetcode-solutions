class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {}

    void add(int num) { nums.push_back(num); }

    int getProduct(int k) {
        int prod = 1;
        int i = nums.size() - 1;
        while (k--) {
            prod *= nums[i--];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */