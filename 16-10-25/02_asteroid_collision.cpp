#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> asteroidCollision(const vector<int>& asteroids) {
    stack<int> s;
    for (int asteroid : asteroids) {
        bool survives = true;
        while (!s.empty() && s.top() > 0 && asteroid < 0) {
            if (s.top() < abs(asteroid)) {
                s.pop();
                continue; // Current asteroid survives, check next top
            } else if (s.top() == abs(asteroid)) {
                s.pop();
                survives = false; // Both destroyed
                break;
            } else {
                survives = false; // Stack top survives
                break;
            }
        }
        if (survives) {
            s.push(asteroid);
        }
    }

    vector<int> result(s.size());
    for (int i = s.size() - 1; i >= 0; --i) {
        result[i] = s.top();
        s.pop();
    }
    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    cout << "Remaining Asteroids: ";
    for (int a : result) cout << a << " "; // Output: 5 10
    cout << endl;
    return 0;
}