// Leet Code -> 53. Maximum Subarray

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long sum = 0, maxi = LONG_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum > maxi)
                maxi = sum;

            if (sum < 0)
                sum = 0;
        }
        return maxi; // only returns value of the sub-array
                     // with maximum sum
    }
};

// FIND AND PRINT THE SUBARRAY HAVING  MAX SUM

// class Solution
// {
// public:
//     int start = 0, ansstart = -1, ansend = -1;
//     int maxSubArray(vector<int> &nums)
//     {
//         long long sum = 0, maxi = LONG_MIN;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (sum == 0)
//                 start = i;

//             sum += nums[i];

//             if (sum > maxi)
//             {
//                 ansstart = start;
//                 ansend = i;
//                 maxi = sum;
//             }

//             if (sum < 0)
//                 sum = 0;
//         }
//         for (int j = ansstart; j <= ansend; j++)
//         {
//             cout << nums[j]; // TO PRINT THE SUB ARRAY
//         }
//         return maxi; // only returns value of the sub-array
//                      // with maximum sum
//     }
// };