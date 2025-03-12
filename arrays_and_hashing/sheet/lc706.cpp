// Input
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// Output
// [null, null, null, 1, -1, null, 1, null, -1]
//
// Explanation
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // The map is now [[1,1]]
// myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
// myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
// myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
// myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
// myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
// myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
// myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
#include <iostream>
#include <vector>

class MyHashMap {
private:
    std::vector<int> map;
    static const int SIZE = 1e6 + 1;
public:
    MyHashMap() {
        map.resize(SIZE, -1);
    }

    void put(int key, int value) {
        if (key >= 0 && key < SIZE) {
            map[key] = value;
        }
    }

    int get(int key) {
        if (key >= 0 && key < SIZE) {
            return map[key];
        }
        return -1;
    }

    void remove(int key) {
        if (key >= 0 && key < SIZE) {
            map[key] = -1;
        }
    }
};

int main() {
    MyHashMap myMap;

    // Adding some key-value pairs
    myMap.put(1, 100);
    myMap.put(2, 200);
    myMap.put(3, 300);

    // Retrieving values
    std::cout << "Value for key 1: " << myMap.get(1) << std::endl; // Output: 100
    std::cout << "Value for key 2: " << myMap.get(2) << std::endl; // Output: 200
    std::cout << "Value for key 3: " << myMap.get(3) << std::endl; // Output: 300

    // Removing a key-value pair
    myMap.remove(2);

    // Trying to retrieve the value after removal
    std::cout << "Value for key 2 after removal: " << myMap.get(2) << std::endl; // Output: -1 (not found)

    // Adding a value with an existing key (updates the value)
    myMap.put(1, 150);
    std::cout << "Updated value for key 1: " << myMap.get(1) << std::endl; // Output: 150

    return 0;
}
