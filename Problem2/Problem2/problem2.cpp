#include<iostream>
#include<fstream>

using namespace std;

void mattimes(double t, double a[][3], double m[][3]);
void matsub(double a[][3], double b[][3], double c[][3]);
void matvecmult(double m[][3], double *v, double *prod);
/*
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
	//cout << "Enter value for change in t: ";
	//cin >> deltat;
	cout << "Enter value for a in (D-a)y0(t)=0 : ";
	cin >> a;

	deltat = (t2 - t1) / n;


	//outfile << "t" << "   " << "y" << endl;
	double y = y0;
	outfile << "0 " << y << endl;
	for (int i = 1; i < n; i++) {
		y = (1 + a*deltat)*y;
		outfile << (i*deltat) << " " << y << endl;
	}

	//ex outfile << t << " " << y << endl;

	outfile.close();
	return 0;
}*/

int main() {

	ofstream outfile("Problem2");
	
	double m1[3][3];
	double m2[3][3];
	double I[3][3] = { { 1,0,0 },{ 0,1,0 },{ 0,0,1 } };

	double deltat, a1, a2, a3, t1, t2, x[3];
	int n;

	cout << "Enter initial condition y0(0) = ";
	cin >> x[0];
	cout << "Enter initial condition y1(0) = ";
	cin >> x[1];
	cout << "Enter initial condition y2(0) = ";
	cin >> x[2];
	cout << "Enter number of iterations: ";
	cin >> n;
	cout << "Enter min bound of t: ";
	cin >> t1;
	cout << "Enter max bound of t: ";
	cin >> t2;
	cout << "For x'3(t) + a2x3(t) + a1x2(t) + a0x1(t) = 0"<<endl;
	cout << "Enter value for a0 in (D-a)y0(t)=0 : ";
	cin >> a1;
	cout << "Enter value for a1 in (D-a)y0(t)=0 : ";
	cin >> a2;
	cout << "Enter value for a2 in (D-a)y0(t)=0 : ";
	cin >> a3;

	double a[3][3] = { { 0,-1,0 },{ 0,0,-1 },{ a1,a2,a3 } };
	deltat = (t2 - t1) / n;



	outfile << "0" << " " << x[0] << endl;
	for (int i = 1; i < n; i++) {

		mattimes(deltat, a, m1);
		matsub(I, m1, m2);


		// x = (1 + m1)*x;
		matvecmult(m2, x, x);
		outfile << (i*deltat) << " " << x[0] << endl;
	}



	
	

}



void mattimes(double t, double a[][3],double m[][3])
{
int i,j;
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)
m[i][j] = t*a[i][j];
}
void matsub(double a[][3],double b[][3],double c[][3])
{
int i,j;
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)
c[i][j] = a[i][j]-b[i][j];
}
void matvecmult(double m[][3], double *v, double *prod)
{
double sum;
int i,j;
for(i = 0; i < 3; i++) {
sum = 0;
for(j = 0; j < 3; j++) {
sum += m[i][j]*v[j];
}
prod[i] = sum;
}
}

/* HINTS
And here is a suggested way to use some of these (but check the signs carefully!):

...
mattimes(deltat,a,m);
matsub(I,a,m);
Miscellaneous hints Remember that the starting index for arrays in C/C++ is 0.
An example loop for the time variable:
for(t = 0; t <= 4; t += deltat) {

*/