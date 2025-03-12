// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
// "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]
//
// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
#include <iostream>
#include <vector>

class MyHashSet {
private:
    std::vector<bool> set;
    static const int MAX_SIZE = 1000001;  // Size to accommodate numbers 0 to 1000000

public:
    MyHashSet() {
        set.resize(MAX_SIZE, false);  // Initialize all elements to false
    }
    
    void add(int key) {
        if (key >= 0 && key < MAX_SIZE) {
            set[key] = true;
        }
    }
    
    void remove(int key) {
        if (key >= 0 && key < MAX_SIZE) {
            set[key] = false;
        }
    }
    
    bool contains(int key) {
        if (key >= 0 && key < MAX_SIZE) {
            return set[key];
        }
        return false;
    }
};

int main() {
    MyHashSet hashSet;
    
    // Test the HashSet operations
    hashSet.add(1);
    hashSet.add(2);
    
    std::cout << "Contains 1? " << (hashSet.contains(1) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 3? " << (hashSet.contains(3) ? "Yes" : "No") << std::endl;
    
    hashSet.add(2);
    std::cout << "Contains 2? " << (hashSet.contains(2) ? "Yes" : "No") << std::endl;
    
    hashSet.remove(2);
    std::cout << "Contains 2? " << (hashSet.contains(2) ? "Yes" : "No") << std::endl;
    
    hashSet.add(1000000);
    std::cout << "Contains 1000000? " << (hashSet.contains(1000000) ? "Yes" : "No") << std::endl;
    
    return 0;
}
