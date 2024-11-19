#include<iostream>
#include<vector>
#include<list>
#include <algorithm>
using namespace std;

// brute force approch 
/*class MyHashMap{
    public:
        vector<int>vec;
        int size;

        MyHashMap(){
            size = 1e6+1;
            vec.resize(size);
            fill(begin(vec), end(vec), -1);
        }

        void put(int key, int value){
            vec[key] = value;
        }

        int get(int key){
            return vec[key];
        }

        void remove(int key){
            vec[key] = -1;
        }

};*/

// optimized approach 
class MyHashMap {
private:
    vector<list<pair<int, int>>> buckets; // Buckets to store key-value pairs
    int size; // Number of buckets

    int getIndex(int key) {
        return key % size; // Hash function to get the bucket index
    }

    list<pair<int, int>>::iterator findKey(int key, int index) {
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                return it; // Return iterator to the key-value pair
            }
        }
        return buckets[index].end(); // Return end iterator if not found
    }

public:
    MyHashMap() {
        size = 10000; // Number of buckets
        buckets.resize(size);
    }

    void put(int key, int value) {
        int index = getIndex(key);
        auto it = findKey(key, index);
        if (it != buckets[index].end()) {
            it->second = value; // Update the value if the key exists
        } else {
            buckets[index].emplace_back(key, value); // Add a new key-value pair
        }
    }

    int get(int key) {
        int index = getIndex(key);
        auto it = findKey(key, index);
        if (it != buckets[index].end()) {
            return it->second; // Return the value if the key exists
        }
        return -1; // Return -1 if the key does not exist
    }

    void remove(int key) {
        int index = getIndex(key);
        auto it = findKey(key, index);
        if (it != buckets[index].end()) {
            buckets[index].erase(it); // Remove the key-value pair if found
        }
    }
};

int main() {
    MyHashMap* hashMap = new MyHashMap();

    // Test cases
    hashMap->put(1, 1);        // Add key 1 with value 1
    hashMap->put(2, 2);        // Add key 2 with value 2
    cout << "Get 1: " << hashMap->get(1) << endl; // Returns 1
    cout << "Get 3: " << hashMap->get(3) << endl; // Returns -1 (not found)
    hashMap->put(2, 1);        // Update key 2 with value 1
    cout << "Get 2: " << hashMap->get(2) << endl; // Returns 1
    hashMap->remove(2);        // Remove key 2
    cout << "Get 2 after removal: " << hashMap->get(2) << endl; // Returns -1 (not found)

    delete hashMap; // Free memory
    return 0;
}