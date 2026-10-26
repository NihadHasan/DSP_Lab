
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;

    cout << "Enter first signal size: ";
    cin >> n;

    cout << "Enter second signal size: ";
    cin >> m;

    int s = max(n, m);

    vector<int> x(s, 0), y(s, 0), z(s);

    cout << "Enter first signal: ";
    for(int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter second signal: ";
    for(int i = 0; i < m; i++)
        cin >> y[i];

    for(int i = 0; i < s; i++)
        z[i] = x[i] * y[i];

    cout << "Result: ";
    for(int i = 0; i < s; i++)
        cout << z[i] << " ";

    return 0;
}
