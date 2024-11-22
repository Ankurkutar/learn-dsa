#include <iostream>
#include <vector>
using namespace std;


// video link which one i follow  // https://www.youtube.com/watch?v=_59HE5lVuLg&t=341s

// optimized approach 
/*int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev1 = 0, prev2 = 0;

    for(int i=0; i<n; ++i){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}*/

// recursive approach 

// recursion function 
int minCostFromStep(int i, const vector<int>& cost, int n) {
    // Base case: If beyond the last step, no cost is incurred
    if (i >= n) return 0;

    // Recursive case: Cost at current step + min cost of next steps
    return cost[i] + min(minCostFromStep(i + 1, cost, n), minCostFromStep(i + 2, cost, n));
}

int minCostClimbingStairs(const vector<int>& cost) {
    int n = cost.size();
    return min(minCostFromStep(0, cost, n), minCostFromStep(1, cost, n));
}

int main() {
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost: " << minCostClimbingStairs(cost) << endl;

    return 0;
}