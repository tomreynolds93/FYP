#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <ctime>		//Header for time functions
#include <fstream>		//Header for file stream
#include <cmath>		//Header for cmaths to use log
using namespace std;

int main()
{
	double tmax = 0, ta = 0, tic = 0, toc = 0, ts = 650; //declaring variables for temperatures
	double kf = 2.65, kc = 15, kd = 1, hg = 5000, R = 40000; // declaring values for heat transfer
	double rh = 2.55E-3, a = 7.25E-3, rc = 0.38E-3, rd = 0.45E-3; //declaring values for sizes rc and rd are thickness of clad and deposit
	double b, c; //declares variables for b and c dimensions
	char x, i = 1, y = 0;//declares values which are needed by the program
	const double pi = 4 * atan(1); //declares a definition of pi for the program
	double cmin, cmax;
	ofstream myfile; //declares file output stream
	myfile.open("thickness.txt"); //sets output file name 

	cout << "Input minimum carbon thickness in um \n ";
	cin >> cmin;
	cmin = cmin * 1E-6;
	cout << "Input maximum carbon thickness in um \n";
	cin >> cmax;
	cmax = cmax * 1E-6;
	cout << "Enter surface temperature \n";
	cin >> ts;

	rd = cmin;
	b = a + rc; //calculation of b dimension

	while (rd <= cmax) {
	
		c = b + rd;
		toc = ts + (R / (2 * pi*kd))*log(c / b);
		tic = toc + (R / (2 * pi*kc))*log(b / a);
		ta = tic + (R / (2 * pi*a*hg));
		tmax = ta + (R / (4 * pi*kf))*(1 - ((2 * rh*rh) / ((a*a) - (rh*rh)))*log(a / rh));
		
		myfile << rd << " " << ts << " " << toc << " " << tic << " " << ta << " " << tmax << endl;
		rd = rd + 1E-6;

	}
	return 0;
}
