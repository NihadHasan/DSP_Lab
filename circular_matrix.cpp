#include <iostream>
using namespace std;

int main() {
    int n;
    int x[100], h[100], matrix[100][100], y[100] = {0};

    cout << "Enter number of samples: ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid input";
        return 0;
    }

    cout << "Enter first signal: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter second signal: ";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = h[(i - j + n) % n];
        }
    }

    cout << "\nCirculant Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += matrix[i][j] * x[j];
        }
    }

    cout << "\nCircular Convolution Result: ";
    for (int i = 0; i < n; i++)
        cout << y[i] << " ";

    cout << endl;
    return 0;
}