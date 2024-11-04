#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    int n = candyType.size();
    set<int>st;  // set store unique value  only
    for(int ele : candyType){
        st.insert(ele);
    }

    int set_size = st.size();
    return min(n/2, set_size);
}


int main() {

   vector<int> nums = {1,1,2,2,3,3};

    int result = distributeCandies(nums);
    cout << "CandyType: " << result <<endl;

    return 0;
}