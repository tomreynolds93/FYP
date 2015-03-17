//Copyright (c) 2015 Thomas Reynolds

#include <iostream>		//Header for C++ output stream 'cout'
#include <conio.h>		//Header for console I/O _getch()
#include <ctime>		//Header for time functions
#include <fstream>		//Header for file stream
#include <cmath>		//Header for cmaths to use log
using namespace std;

int main()
{
	double tmax=0, ta=0, tic=0, toc=0, ts = 650; //declaring variables for temperatures
	double kf = 2.65, kc = 15, kd = 1, hg = 5000, R = 40000; // declaring values for heat transfer
	double rh = 2.55E-3, a = 7.25E-3, rc = 0.38E-3, rd = 0.45E-3; //declaring values for sizes rc and rd are thickness of clad and deposit
	double b, c; //declares variables for b and c dimensions
	char x, i = 1, y = 0;//declares values which are needed by the program
	const double pi = 4 * atan(1); //declares a definition of pi for the program
	
	ofstream myfile; //declares file output stream
	myfile.open("temperatures.txt"); //sets output file name 


	while (i == 1) //while loop to keep menu reappearing after each run
	{
		
		b = a + rc; //calculation of b dimension
		c = b + rd; //calculation of c dimension
		// equation below calculate temperatures at interfaces
		toc = ts + (R / (2 * pi*kd))*log(c / b);
		tic = toc + (R / (2 * pi*kc))*log(b / a);
		ta = tic + (R / (2 * pi*a*hg));
		tmax = ta + (R / (4 * pi*kf))*(1 - ((2 * rh*rh) / ((a*a) - (rh*rh)))*log(a / rh));


		//outputs menu
		cout << "Select Menu Item \n";
		cout << "  ====================================\n";
		cout << "1. Edit/View pin surface temperature \n";
		cout << "2. Edit/View heat transfer propertiers\n";
		cout << "3. Edit/View fuel pin dimensions\n";
		cout << "4. Display temperatures\n";
		cout << "5. Restore default values\n";
		cout << "6. Write to Text File\n";
		cout << "7. Exit\n";
		cout << "  ====================================\n";

		cin >> x; //takes selection from user

		switch (x) //switch used to process selection
		{
		case '1': // takes new value of surface temperature
			cout << "Current surface temperature set to: " << ts << " degress celcius\n";
			cout << "do you wish to edit this temperature (y/n)";
			cin >> y;
			if (y == 'y') {
				cout << "Input new surface temperature\n";
				cin >> ts;
				y = 0;
				break;
			}
			else {
				break;
			}
		case '2': //allows user to modify heat transfer properties
			cout << "1. Thermal conductivity of UO2 fuel is " << kf << " W/m K\n";
			cout << "2. Heat transfer coefficient of gas gap is " << hg << " W/m^2 K\n";
			cout << "3. Thermal conductivity of fuel cladding is " << kc << " W/m K\n";
			cout << "4. Thermal conductivity of carbon deposit is " << kd << " W/m k\n";
			cout << "5. Linear heat generation is " << R << " W/m K\n";
			cout << "6. Return\n";
			cout << endl;
			cin >> y;
			switch (y)
			{
			case '1':
				cout << "Input new fuel conductivity\n";
				cin >> kf;
				break;

			case '2':
				cout << "Input new has heat transfer\n";
				cin >> hg;
				break;

			case '3':
				cout << "Input new clad conductivity\n";
				cin >> kc;
				break;

			case '4':
				cout << "Input new deposit conductivity\n";
				cin >> kd;
				break;

			case '5':
				cout << "Input new linear heat generation\n";
				cin >> R;
				break;
				
			case '6':
				break;
				
			default:
				cout << y << " is not a valid menu option\n";
				break;
			}
			y = 0;
			break;
		case '3': //allows user to modify fuel pin dimensions
			cout << "1. Fuel pellet radius is " << a << " m\n";
			cout << "2. Fuel pellet central hole radius is " << rh << " m\n";
			cout << "3. Cladding thickness is " << rc << " m\n";
			cout << "4. Carbon deposit thickness is " << rd << " m\n";
			cout << "5. Return\n";
			cout << endl;
			cin >> y;
			switch (y){
			case'1':
				cout << "Enter new fuel pellet radius (m)\n";
				cin >> a;
				break;

			case '2':
				cout << "Enter new hole radius (m)\n";
				cin >> rh;
				break;

			case '3':
				cout << "Enter new cladding thickness (m)\n";
				cin >> rc;
				break;

			case '4':
				cout << "Enter new deposit thickness (m)\n";
				cin >> rd;
				break;

			case'5':
				break;
			default: 
				cout << y << " is not a valid menu option\n";
				break;

			}
			y = 0;
			break;


		case '4': //displays temperature
			cout << "Ts = " << ts << " degrees\n";
			cout << "Toc = " << toc << " degrees\n";
			cout << "Tic = " << tic << " degrees\n";
			cout << "Tmax = " << tmax << " degrees\n";
			cout << "Press any key to exit...\n";
			cout << endl;
			_getch();
			break;

		case '5': //resets all properties to default
			kf = 2.65, kc = 15, kd = 1, hg = 5000, R = 40000;
			rh = 5.1E-3, a = 14.5E-3, rc = 0.38E-3, rd = 0.4E-3;
			tmax = 0, ta = 0, tic = 0, toc = 0, ts = 650;
			break;

		case '6':
			myfile << "Thermal conductivity of UO2 fuel is " << kf << " W/m K\n";
			myfile << "Heat transfer coefficient of gas gap is " << hg << " W/m^2 K\n";
			myfile << "Thermal conductivity of fuel cladding is " << kc << " W/m K\n";
			myfile << "Thermal conductivity of carbon deposit is " << kd << " W/m K\n";
			myfile << "Linear heat generation is " << R << " W/m K\n";
			myfile << endl;
			myfile << "Fuel pellet radius is " << a << " m\n";
			myfile << "Fuel pellet central hole radius is " << rh << " m\n";
			myfile << "Cladding thickness is " << rc << " m\n";
			myfile << "Carbon deposit thickness is " << rd << " m\n";
			myfile << endl;
			myfile << "Ts = " << ts << " degrees\n";
			myfile << "Toc = " << toc << " degrees\n";
			myfile << "Tic = " << tic << " degrees\n";
			myfile << "Tmax = " << tmax << " degrees\n";
			cout << "All values have been written to file\n";
			break;

		case '7':
			i = 0;
			break;
		default:
			cout << x << " is not a valid menu item\n";
		}
	}




	return 0;
}
