
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of first signal: ";
    cin >> n;

    cout << "Enter number of second signal: ";
    cin >> m;

    int size = max(n, m);

    vector<int> x(size, 0), y(size, 0), z(size, 0);

    cout << "Enter first signal: ";
    for(int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter second signal: ";
    for(int i = 0; i < m; i++)
        cin >> y[i];

    for(int i = 0; i < size; i++)
        z[i] = x[i] + y[i];

    cout << "Result: ";
    for(int i = 0; i < size; i++)
        cout << z[i] << " ";

    return 0;
}
