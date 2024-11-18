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
class MyHashMap{
    public:
        vector<list<pair<int, int>>>buckets;
        int size = 10000;

        MyHashMap(){
            buckets.resize(size);
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