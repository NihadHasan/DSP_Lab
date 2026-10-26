
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n1, n2;
    double x[100] = {0}, h[100] = {0}, y[100] = {0};

    cout << "Enter number of first signal samples: ";
    cin >> n1;

    cout << "Enter number of second signal samples: ";
    cin >> n2;

    if (n1 < 1 || n2 < 1 || n1 > 100 || n2 > 100) {
        cout << "Invalid number of samples!";
        return 0;
    }

    cout << "Enter first signal sequences: ";
    for (int i = 0; i < n1; i++)
        cin >> x[i];

    cout << "Enter second signal sequences: ";
    for (int i = 0; i < n2; i++)
        cin >> h[i];

    int n = max(n1, n2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += x[j] * h[(i - j + n) % n];
        }
    }

    cout << "Circular convolution result: ";
    for (int i = 0; i < n; i++)
        cout << y[i] << " ";

    cout << endl;
    return 0;
}
