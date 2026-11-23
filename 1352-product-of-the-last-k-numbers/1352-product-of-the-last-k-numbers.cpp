class ProductOfNumbers {
public:
    vector<int> products;
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            products.clear();
        } else {
            products.push_back(products.empty() ? num : products.back() * num);
        }
    }

    int getProduct(int k) {
        int n = products.size();
        if (k > n)
            return 0;
        else if (n == k)
            return products[n - 1];
        else {
            return products[n - 1] / products[n - k - 1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */