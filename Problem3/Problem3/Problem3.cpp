#include<iostream>
#include<fstream>

using namespace std;

void mattimes(double t, double a[][2], double m[][2]);
void matsub(double a[][2], double b[][2], double c[][2]);
void matvecmult(double m[][2], double *v, double *prod);

int main() {

	ofstream outfile("Problem3");

	double m1[2][2];
	double m2[2][2];
	double I[2][2] = { { 1,0 },{ 0,1 } };

	double deltat, a0, a1, t1, t2, x[2];
	int n;

	cout << "Enter initial condition y0(0) = ";
	cin >> x[0];
	cout << "Enter initial condition y1(0) = ";
	cin >> x[1];
	cout << "Enter number of iterations: ";
	cin >> n;
	cout << "Enter min bound of t: ";
	cin >> t1;
	cout << "Enter max bound of t: ";
	cin >> t2;
	cout << "For x3(t) + a1x2(t) + a0x1(t) = 0" << endl;
	cout << "Enter value for a0: ";
	cin >> a0;
	cout << "Enter value for a1: ";
	cin >> a1;

	double a[2][2] = { { 0,-1 },{ a0,a1 } };
	deltat = (t2 - t1) / n;

	outfile << "0" << " " << x[0] << endl;
	for (int i = 1; i < n; i++) {

		mattimes(deltat, a, m1);
		matsub(I, m1, m2);
		matvecmult(m2, x, x);
		outfile << (i*deltat) << " " << x[0] << endl;
	}
	return 0;
}

void mattimes(double t, double a[][2], double m[][2])
{
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			m[i][j] = t*a[i][j];
}
void matsub(double a[][2], double b[][2], double c[][2])
{
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			c[i][j] = a[i][j] - b[i][j];
}
void matvecmult(double m[][2], double *v, double *prod)
{
	double sum;
	int i, j;
	for (i = 0; i < 2; i++) {
		sum = 0;
		for (j = 0; j < 2; j++) {
			sum += m[i][j] * v[j];
		}
		prod[i] = sum;
	}
}
