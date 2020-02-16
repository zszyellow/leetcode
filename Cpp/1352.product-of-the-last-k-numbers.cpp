/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
class ProductOfNumbers {
public:
    vector<int> products;
    
    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            products = {1};
        } else {
            products.push_back(num * products.back());
        }
    }
    
    int getProduct(int k) {
        int n = products.size();
        return k < n ? products.back() / products[n-k-1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

