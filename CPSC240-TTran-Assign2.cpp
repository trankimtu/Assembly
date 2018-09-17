#include <iostream>
using namespace std;

int main() {
	
//	=========================================================================================
//	||	1.	All variables are SHORT TYPE						||							||
//	||		--------------------MENU------------------				||						||
//	||		Drinks................$2						||									||
//	||		Sandwiches............$4						||								||
//	||		How many drinks	     : 3						||									||
//	||		How many sandwiches  : 3						||								||
//	||		Your total bill $18							||									||
//	=========================================================================================
	short drinkPrice = 2, sandwichPrice = 4, numDrink, numSandwich, total;
	cout << "Drink................ $" << drinkPrice << endl;
	cout << "Sandwiches........... $" << sandwichPrice << endl;
	cout << "How many drinks      : ";
	cin >> numDrink;
	cout << "How many sandwiches  : ";
	cin >> numSandwich;

	_asm {
		mov  ax, drinkPrice;		// ax = 2
		imul ax, numDrink;		// ax = 2*numDrink
		mov  bx, sandwichPrice;		// bx = 4
		imul bx, numSandwich;		// bx = 4*numSandwich
		add  ax, bx;			// ax = 2*numDrink + 4*numSandwich
		mov  total, ax;			// total = 2*numDrink + 4*numSandwich
	} // End _asm

	cout << "Your total bill: $" << total << "\n\n" ;

//      =========================================================================================
//	||	2.     All sides are INT TYPE							||
//	||											||
//	||			/|\                 ------------------------			||
//	||		       / | \                |                      |			||
//	||		  a   /  |  \  b            |                      | width		||
//	||		     / h |   \              |                      |			||
//	||		    /    |    \             |                      |			||
//	||	    	    ------------ 	    ------------------------			||
//	||			c                           length				||
//	||											||
//	||	Enter the values of a, b, c, and h  for the triangle : 4  6   9   10		||
//	||	Enter the length and the width of the rectangle : 15  10			||
//	||	Triangle									||
//	||	Area.................45								||
//	||	Perimeter............19								||
//	||	Rectangle									||
//	||	Area................150								||
//	||	Perimeter............50								||
//      =========================================================================================
	int a, b, c, h, two = 2, rlength, rwidth;
	int tArea, tPerimeter, rArea, rPerimeter;

	cout << "Enter the values of a,b,c and h for the triangle: ";
	cin >> a >> b >> c >> h;

	cout << "Enter the length and the width of the rectangle: ";
	cin >> rlength >> rwidth;

	_asm {
		// Calculate triangle area
		mov  eax, h;				// eax   = h
		imul eax, c;				// eax   = h * c
		cdq;
		idiv two;				// eax   = (h * c)/2
		mov  tArea, eax;			// tArea = (h * c)/2

		// Calculate triangle perimeter
		mov eax, a;				// eax   = a
		add eax, b;				// eax   = a + b
		add eax, c;				// eax   = a + b + c
		mov tPerimeter, eax;			// tArea = a + b + c

		// Calculate rectangle perimeter
		mov eax, rlength;
		add eax, rwidth;
		imul two;
		mov rPerimeter, eax;
		
		// Calculate rectangle area
		mov eax, rwidth;
		imul rlength;
		mov rArea, eax;		
	} // End _asm

	cout << "Triangle \n";
	cout << "\t Area ............. " << tArea << endl;
	cout << "\t Perimeter ........ " << tPerimeter << endl;

	cout << endl;

	cout << "Rectangle \n";
	cout << "\t Area ............. " << rArea << endl;
	cout << "\t Perimeter ........ " << rPerimeter << "\n\n";

//	=========================================================================================
//	||	3.Use the following formula for the temperature conversion : 			||
//	||	C = 5(F - 32) / 9,								||
//	||	C and F are type short								||
//	||	Enter temperature in Fahrenheit : 95						||
//	||	95 F⁰ is  35 C⁰									||
//	==========================================================================================
	short C, F;
	int Fdegree, Cdegree;
		cout << "Enter temperature in Fahrenheit: ";
		cin >> Fdegree;
	_asm {		
		mov eax, Fdegree;	// eax = Fdegree
		mov ebx, 32;		// ebx = 32
		sub eax, ebx;		// eax = eax - ebx --> F-32
		mov ebx, 5;		// ebx = 5
		imul ebx;		// eax = eax * 5   -->5(F-32)
		mov ebx, 9;
		idiv ebx;		// eax = eax / 9
		mov Cdegree, eax;
	} // End _asm

	cout << Fdegree << " F" << char(248) << " is " << Cdegree << " C" << char(248) << "\n\n";

//	==========================================================================================
//	||	4. Enter a 3 digit int number : 358						||
//	||	The total of digits in 358  is 16						||
//	==========================================================================================
	int num;
	short hundred = 100, ten = 10, d2, d1, sumInt;
	cout << "Enter a 3 digit int number : ";
	cin >> num;			// XYZ
	_asm {
		//d2
		mov eax, num;		// eax = XYZ
		cwd;			// dx:ax = num
		idiv hundred;		// eax / 100 --> ax = X, dx = YZ
		mov d2, ax;		// d2 = ax = X
		
		//d1
		mov ax, dx;		// ax = dx
		cwd;			// dx:ax = YZ
		idiv ten;		// ax = Y, dx = Z
		mov d1, ax;		// d2 = ax = Y
		
		//d0 = dx, sum
		mov ax, dx;		// d0 = dx = Z	
		add ax, d1;		// ax = Z + d1
		add ax, d2;		// ax = Z + d1 + d2

		mov sumInt, ax;

	} // End _asm
	
	cout << "The total of degits in " << num << " is " << sumInt << "\n\n";

	system("pause");
	return 0;
} // End main
