
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, sx, sh;

    cout << "Enter first signal size: ";
    cin >> n;

    cout << "Enter second signal size: ";
    cin >> m;

    cout << "Enter first starting index: ";
    cin >> sx;

    cout << "Enter second starting index: ";
    cin >> sh;

    vector<int> x(n), h(m), y(n + m - 1, 0);

    cout << "Enter first signal: ";
    for(int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter second signal: ";
    for(int i = 0; i < m; i++)
        cin >> h[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            y[i + j] += x[i] * h[j];
    }

    cout << "Result starting index: " << sx + sh << endl;

    cout << "Convolution result: ";
    for(int i = 0; i < n + m - 1; i++)
        cout << y[i] << " ";

    return 0;
}
