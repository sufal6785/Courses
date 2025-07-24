#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) return;

    // Move n-1 disks to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move nth disk to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');  // A = source, B = auxiliary, C = destination
    return 0;
}