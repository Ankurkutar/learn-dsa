#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        // brute force approach
        /*vector<string> findRelativeRanks(vector<int>& score) {
           int n = score.size();
            vector<string>ranks(n);

            for(int i=0; i<n; i++){
                int rank = 1;
                for(int j=0; j<n; j++){
                    if(score[j] > score[i]){
                        ++rank;
                    }
                }

                if(rank == 1){
                    ranks[i] = "Gold Medal";
                }else if(rank == 2){
                    ranks[i] = "Silver Medal";
                }else if(rank == 3){
                    ranks[i] = "Bronze Medal";
                }else{
                    ranks[i] = to_string(rank);
                }
            }

            return ranks;
        }*/

        // second approach 
        vector<string> findRelativeRanks(vector<int>& score) {
            int n = score.size();
            
            // Corrected: Use vector of pairs to store scores with their indices
            vector<pair<int, int>> scoreWithIndex;

            // Pair each score with its index
            for (int i = 0; i < n; i++) {
                scoreWithIndex.push_back({score[i], i});
            }

            // Sort pairs in descending order based on the score
            sort(scoreWithIndex.begin(), scoreWithIndex.end(), greater<>()); // sorting in decending order

            // Vector to store ranks in string format
            vector<string> ranks(n);
            for (int i = 0; i < n; i++) {
                if (i == 0) ranks[scoreWithIndex[i].second] = "Gold Medal";
                else if (i == 1) ranks[scoreWithIndex[i].second] = "Silver Medal";
                else if (i == 2) ranks[scoreWithIndex[i].second] = "Bronze Medal";
                else ranks[scoreWithIndex[i].second] = to_string(i + 1);
            }

            return ranks;
        }
};

int main() {
    // Example input
    vector<int> scores = {5, 3, 8, 10, 2};

    // Creating an object of Solution class
    Solution solution;

    // Calling the findRelativeRanks function
    vector<string> result = solution.findRelativeRanks(scores);

    // Output the result
    cout << "Relative ranks: ";
    for (const string& rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}

