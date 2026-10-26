
//Addition 
///////////

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of first samples: ";
    cin >> n;

    cout << "Enter number of second samples: ";
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



//Multi
/////////


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





//amplitude scaling
//////////////////


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




//even odd 
///////////


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





//linear convolution
//////////////////


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





//deconvolution

////////////////


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






//circular convolution
/////////////////////




#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n1, n2, n;
    double x[100] = {0}, h[100] = {0}, y[100] = {0};

    cout << "Enter number of first signal samples: ";
    cin >> n1;

    cout << "Enter number of second signal samples: ";
    cin >> n2;

    if (n1 < 1 || n2 < 1 || n1 > 100 || n2 > 100) {
        cout << "Invalid input!";
        return 0;
    }

    cout << "Enter first signal sequences: ";
    for (int i = 0; i < n1; i++)
        cin >> x[i];

    cout << "Enter second signal sequences: ";
    for (int i = 0; i < n2; i++)
        cin >> h[i];

    n = max(n1, n2);

    cout << "\nCircular Convolution result: ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += x[j] * h[(i - j + n) % n];
        }
    }

    for (int i = 0; i < n; i++)
        cout << y[i] << " ";

    cout << endl;
    return 0;
}





//circular matrix
/////////////////



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

