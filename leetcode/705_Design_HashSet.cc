#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;


// brute force approach 
/*
class MyHashSet{
    private:
        static const int SIZE = 1000001; // Maximum possible key value (0 to 10^6)
        bool hashSet[SIZE];
    public:
        MyHashSet() {
            for(int i = 0; i < SIZE; i++) {
                hashSet[i] = false; // Initialize all elements to false
            }
        }

        void add(int key){
            hashSet[key] = true;
        }

        void remove(int key){
            hashSet[key] = false;
        }

        bool contains(int key){
           hashSet[key];
        }
};
*/

// optimized approach 
class MyHashSet {
private:
    int m; // Number of buckets
    vector<list<int>> buckets;

    int getIndex(int key) {
        return key % m; // Hash function
    }

    auto findKey(int key) {
        int index = getIndex(key);
        return find(buckets[index].begin(), buckets[index].end(), key);
    }

    public:
        MyHashSet() {
            m = 14983; // Use a large prime number for better distribution
            buckets = vector<list<int>>(m, list<int>{});
        }

        void add(int key) {
            int index = getIndex(key);
            if (findKey(key) == buckets[index].end()) {
                buckets[index].push_back(key);
            }
        }

        void remove(int key) {
            int index = getIndex(key);
            auto itr = findKey(key);
            if (itr != buckets[index].end()) {
                buckets[index].erase(itr);
            }
        }

        bool contains(int key) {
            return findKey(key) != buckets[getIndex(key)].end();
        }
};


int main() {
    MyHashSet* hashSet = new MyHashSet();

    // Add elements to the hash set
    hashSet->add(1);
    hashSet->add(2);

    // Check if elements are present
    cout << "Contains 1: " << (hashSet->contains(1) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 3: " << (hashSet->contains(3) ? "Yes" : "No") << endl; // Output: No

    // Add another element
    hashSet->add(2);
    cout << "Contains 2: " << (hashSet->contains(2) ? "Yes" : "No") << endl; // Output: Yes

    // Remove an element
    hashSet->remove(2);
    cout << "Contains 2 after removal: " << (hashSet->contains(2) ? "Yes" : "No") << endl; // Output: No

    delete hashSet; // Free allocated memory
    return 0;
}











