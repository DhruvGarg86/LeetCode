// Leet Code -> 50. Pow(x, n)

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
    public:
        double myPow(double x, int n) {
            double ans = 1.0;
            long long n1 = n;
            if(n1 < 0)
                n1 = -1 * n1;
            while(n1) {
                if(n1 % 2) { // if n1 is odd
                    ans = ans * x;
                    n1 = n1 - 1;
                }
                else {  // if n1 is even
                    x = x * x; // reduces time complexity to O(log n)
                    n1 = n1 / 2;
                }
            }
            if(n < 0) // x^(-n) -> 1 / (x^n)
                ans = 1.0 / ans;
            return ans;
        }
    };
    