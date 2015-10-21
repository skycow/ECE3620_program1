#include<iostream>
#include<fstream>

using namespace std;

int main() {

	ofstream outfile("Problem1");

	double y0, deltat, a, t1, t2;
	int n;

	cout << "Enter initial condition y0(0) = ";
	cin >> y0;
	cout << "Enter number of iterations: ";
	cin >> n;
	cout << "Enter min bound of t: ";
	cin >> t1;
	cout << "Enter max bound of t: ";
	cin >> t2;
	cout << "Enter value for a in (D-a)y0(t)=0 : ";
	cin >> a;

	deltat = (t2 - t1) / n;

	double y = y0;
	outfile <<"0 " << y << endl;
	for (int i = 1; i < n; i++) {
		y = (1 + a*deltat)*y;
		outfile << (i*deltat) << " " << y << endl;
	}

	outfile.close();
	return 0;
}