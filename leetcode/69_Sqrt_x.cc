#include<iostream>
using namespace std;

class Solution{
    public:
        int mySqrt(int x){
            if(x < 2) return 2;

            int left = 0, right = 2, result = 0;

            while(left <= right){
                int mid = (left + right)/ + 2;
                if(mid <= x/mid) {   // entire logic
                    result = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            return result;
        }
};

int main() {
    Solution solution;
    int x = 8;
    int result = solution.mySqrt(x);
    cout << "The integer square root of " << x << " is: " << result << endl;
    return 0;
}