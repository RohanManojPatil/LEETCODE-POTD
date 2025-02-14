*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int product = 1;
    
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefixProduct since multiplication with 0 makes further calculations invalid
            prefixProduct.clear();
            product = 1;
        } else {
            product *= num;
            prefixProduct.push_back(product);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k > n) return 0; // If k is larger than available elements, return 0

        int totalProduct = prefixProduct[n - 1];
        int leftProduct = (n - k - 1 >= 0) ? prefixProduct[n - k - 1] : 1;
        
        return totalProduct / leftProduct;
    }
};
