#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    char aux;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl << a + b << endl;
    aux = a[0];
    a[0] = b[0];
    b[0] = aux;
    cout << a + " " << b;
    return 0;
}

