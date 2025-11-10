#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// --- Optimized Solution (Using C++ STL unordered_map) ---
// This class wraps the standard unordered_map to demonstrate the required operations.
class MyHashMap {
private:
    unordered_map<int, int> data;

public:
    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        if (data.count(key)) {
            return data[key]; // Key found
        }
        return -1; // Value to indicate key not found
    }

    bool containsKey(int key) {
        return data.count(key);
    }

    vector<int> keySet() {
        vector<int> keys;
        for (auto const& [key, val] : data) {
            keys.push_back(key);
        }
        return keys;
    }
    
    // Deletion operation (often required for complete implementation)
    void remove(int key) {
        data.erase(key);
    }
};

int main() {
    MyHashMap map;
    map.put(1, 100);
    map.put(2, 200);

    cout << "Get key 1: " << map.get(1) << endl; // Output: 100
    cout << "Contains key 3: " << map.containsKey(3) << endl; // Output: 0 (false)

    map.put(3, 300);
    map.remove(1);
    
    vector<int> keys = map.keySet();
    cout << "Keys in map: ";
    for (int k : keys) cout << k << " "; // Output: (might be 2 3 or 3 2)
    cout << endl;
    return 0;
}