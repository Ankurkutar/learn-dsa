#include<iostream>
#include<string>
#include<vector>
#include <climits>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2){
            unordered_map<string, int>indexMap;

            for(int i=0; i<list1.size(); i++){
                indexMap[list1[i]] = i;
            }

            vector<string>result;
            int minSum  = INT_MAX;

            for(int j=0; j<list2.size(); j++){
                if(indexMap.find(list2[j]) != indexMap.end()){
                    int sum = j + indexMap[list2[j]];
                    if(sum < minSum){
                        result.clear();
                        result.push_back(list2[j]);
                         minSum = sum;
                    }else if(sum == minSum){
                        result.push_back(list2[j]);
                    }
                }
            }
            return result;
        }
};


int main() {
    // Test case input
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    // Create an instance of Solution
    Solution solution;
    
    // Call the findRestaurant method
    vector<string> result = solution.findRestaurant(list1, list2);
    
    // Print the result
    cout << "Common restaurants with minimum index sum:" << endl;
    for (const string& restaurant : result) {
        cout << restaurant << endl;
    }

    return 0;
}