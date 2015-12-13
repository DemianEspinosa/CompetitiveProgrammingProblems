#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int a, b, c, d;

int main(){
	ifstream in ("paint.in");
	ofstream out ("paint.out");
	in >> a >> b >> c >> d;
	out << max(b, d) - min(a, c) - (b < c ? c - b : 0) - (d < a ? a - d : 0) << endl;
}

