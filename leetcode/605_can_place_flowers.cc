#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int total = 0;
        for(int i=0; i<flowerbed.size() && total < n; ++i){
            if(flowerbed[i] == 0 && (i == 0 && flowerbed[i-1] == 0) && (i < flowerbed.size()-1 && flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                total++;
            }
        }
        if(total == n)
            return true;
        
        return false;
    }
};

int main() {
    Solution solution;

    vector<int> flowerbed = {1, 0, 0, 0, 1}; // Example flowerbed
    int n = 1; // Number of flowers we want to place

    bool result = solution.canPlaceFlowers(flowerbed, n);
    if (result) {
        cout << "Yes, you can place " << n << " flowers in the flowerbed." << endl;
    } else {
        cout << "No, you cannot place " << n << " flowers in the flowerbed." << endl;
    }

    return 0;
}