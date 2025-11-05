

#include <iostream>
#include <cmath>

using namespace std;


void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) return;
    
    
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
   
    cout << "Move disc " << n << " from " << source << " to " << destination << endl;
    
    
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n_discs = 3;
    cout << "Tower of Hanoi for " << n_discs << " discs:" << endl;
    towerOfHanoi(n_discs, 'A', 'B', 'C');
    cout << "Total moves: " << pow(2, n_discs) - 1 << endl;
    return 0;
}