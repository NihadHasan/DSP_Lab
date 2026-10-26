
#include <iostream>
using namespace std;

int main() {
    int n, m, sy, sh;

    cout << "Enter first signal size: ";
    cin >> n;

    cout << "Enter second signal size: ";
    cin >> m;

    cout << "Enter first starting index: ";
    cin >> sy;

    cout << "Enter second starting index: ";
    cin >> sh;

    double y[100], h[100], x[100] = {0};

    cout << "Enter first signal: ";
    for(int i = 0; i < n; i++)
        cin >> y[i];

    cout << "Enter second signal: ";
    for(int i = 0; i < m; i++)
        cin >> h[i];

    if(h[0] == 0 || m > n || n > 100) {
        cout << "Invalid input";
        return 0;
    }

    int size = n - m + 1;

    for(int i = 0; i < size; i++) {
        double sum = 0;

        for(int j = 1; j < m; j++) {
            if(i - j >= 0)
                sum += x[i-j] * h[j];
        }

        x[i] = (y[i] - sum) / h[0];
    }

    cout << "Result starting index: " << sy - sh << endl;
    cout << "Deconvolution result: ";

    for(int i = 0; i < size; i++)
        cout << x[i] << " ";

    return 0;
}
