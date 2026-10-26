
#include <iostream>
using namespace std;

int main()
{
    int n, origin, x[100], a[100];

    cout << "Enter the size of signal : ";
    cin >> n;

    cout << "Enter the input signal : ";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "Enter the origin : ";
    cin >> origin;

    int left = origin - 1;
    int right = n - origin;
    int size = (left > right) ? left : right;

    for (int i = 0; i <= 2 * size; i++)
        a[i] = 0;

    for (int i = 0; i < n; i++)
        a[size - left + i] = x[i];

    cout << "X[n] : ";
    for (int i = 0; i <= 2 * size; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "X[-n] : ";
    for (int i = 2 * size; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

    cout << "Even component : ";
    for (int i = 0; i <= 2 * size; i++)
        cout << (a[i] + a[2 * size - i]) / 2.0 << " ";
    cout << endl;

    cout << "Odd component : ";
    for (int i = 0; i <= 2 * size; i++)
        cout << (a[i] - a[2 * size - i]) / 2.0 << " ";
    cout << endl;

    return 0;
}
