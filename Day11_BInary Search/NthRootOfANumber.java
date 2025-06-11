// Not a LeetCode Question (GeekForGeeks)

// https://www.geeksforgeeks.org/n-th-root-number/

// Q - Find the nth root of a number using binary Search.

class Solution{
    double multiply(double x, int n){
        for ( int i = 0; i < n; i++ ){
            x *= x;
        }
        return x;
    }
    // n = root , m = number
    // For eg. n = 3, m = 27, then find cube root of 27.
    double nthRoot(int n, int m){
        double low = 1.0, high = m;
        double eps = 1e-6;
        while((high - low) > eps){
            double mid = (low + high) / 2.0;
            if(multiply(mid, n) < m){
                low = mid;
            } else{
                high = mid;
            }
        }
        System.out.println(low + " = " + high + "both are same ");
        return 1.0;
    }
}

// TC -> O(N) {From multiply function}
// TC -> O(log2(M * 10^d)), where 
                            // M is the number
                            // d is the no of decimals the mid can go upto (in our case max 5)
                            // M *10^d is {1.0,1.1,1.2,1.3, ...... M.0}, then d is {1.01,1.02,1.03 .... 27.00000}