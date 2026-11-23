class ProductOfNumbers {
public:
    vector<int> products;
    int n;
    ProductOfNumbers() { n = 0; }

    void add(int num) {
        if (num == 0) {
            products.erase(products.begin(), products.end());
            n = 0;
        } else {
            if (products.empty())
                products.push_back(num);
            else
                products.push_back(products[n - 1] * num);
            n++;
        }
    }

    int getProduct(int k) {
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