#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Declaring a priority queue of integers in ascending order
    priority_queue<int, vector<int>, greater<>> pq;

    // Inserting elements into the priority queue
    pq.push(5);
    pq.push(1);
    pq.push(2);
    pq.push(9);

    // Output: 1 2 5 9 (ascending order)
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}