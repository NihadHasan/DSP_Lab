
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a;

    cout << "Enter number of samples: ";
    cin >> n;

    int x[n], y[n];

    cout << "Enter signal samples: ";
    for(int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter scaling value: ";
    cin >> a;

    for(int i = 0; i < n; i++)
        y[i] = a * x[i];

    cout << "Scaled signal: ";
    for(int i = 0; i < n; i++)
        cout << y[i] << " ";

    return 0;
}
