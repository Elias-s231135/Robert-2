#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	//// This is a comment
	//
	///* The code below will print the words Hello World!
	//to the screen, and it is amazing */
	//cout << "Hello World!" << endl;
	//cout << "I am learning C++\n";
	//
	////int myNum = 15; // myNum is 15
	////myNum = 10; // Now myNum is 10
	////cout << myNum << endl; // Outputs 10
	//
	//int myNumber = 5;				// Integer (whole number without decimals)
	//double myFloatNum = 5.99;	// Floating point number (with decimals)
	//char myLetter = 'D';		// Character
	//string myText = "Hello";	// String (text)
	//bool myBoolean = true;		// Boolean (true or false)
	//cout << myText << ", World!" << endl;
	//
	///*int x = 5;
	//int y = 6;*/
	///*int x = 5, y = 6;
	//int sum = x + y;
	//cout << sum << endl;*/
	//int x, y, z;
	//x = y = z = 50;
	//cout << x + y + z;
	//
	//// Good v
	//int minutesPerHour = 60;

	//// OK, but not so easy to understand what m actually is v
	//int m = 60;
	
	//const int myNum = 15; // myNum will always be 15
	//myNum = 10; //error: assignment of read only variable 'myNum'

	//const int minutesPerHour = 60; // value that is unlikely to change
	//const float PI = 3.14; // value that is unlikely to change

	//const int minutesPerHour = 60; // Works (has value assigned)
	//const int secondsPerMinute // Doesn't work (no value assigned) v
	//	secondsPerMinute = 60; // error

	//int x;
	//cout << "Type a number: "; // Type a number and press enter
	//cin >> x; // Get user input from the keyboard
	//cout << "Your number is: " << x; // Display the input value

	/*int x, y;
	int sum;
	cout << "Type a number: ";
	cin >> x;
	cout << "Type another number: ";
	cin >> y;
	sum = x + y;
	cout << "Sum is: " << sum;*/

	//int myNum = 5;				// Integer (whole number)
	//float myFloatNum = 5.99;	// Floating point number
	//double myDoubleNum = 9.98;	// Floating point number
	//char myLetter = 'D';		// Character 
	//bool myBoolean = true;		// Boolean
	//string myText = "Hello";	// String

	//// int
	//int myNum1 = 1000;
	//cout << myNum1 << endl;

	//// float
	//float myNum2 = 5.75;
	//cout << myNum2 << endl;

	//// double
	//double myNum3 = 19.99;
	//cout << myNum3 << endl;

	//// scientific numbers
	//float f1 = 35e3;
	//double d1 = 12E4;
	//cout << f1 << endl;
	//cout << d1 << endl;

	//// booleans
	//bool isCodingFun = true;
	//bool isFishTasty = false;
	//cout << isCodingFun << endl; // Outputs 1 (true)
	//cout << isFishTasty << endl; // Outputs 0 (false)

	//// Character Types
	//char myGrade = 'B';
	//cout << myGrade << endl;

	//// ASCII (Uppercase?)
	//char a = 65, b = 66, c = 67;
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	//// String
	//string greeting = "Hello";
	//cout << greeting << endl;

	///* <string> library */

	//// Inlcude the string library (see top)

	//// Create a string variable
	//string greeting = "Hello";

	//// Output string value
	//cout << greeting << endl;

	///* Operators */

	//int x = 100 + 50;

	//int sum1 = 100 + 50;	// 150 (100 + 50)
	//int sum2 = sum1 + 250;	// 400 (150 + 250)
	//int sum3 = sum2 + sum2;	// 800 (400 + 400)

	//// Arithmetic Operators (+, -, *, /, %, ++(increase by 1), --(decrease by 1))

	//// Assignment Operators 
	//
	//// = assigns the value to a variable (no change)
	//int x = 10;

	//// += adds a value to a variable
	//int x = 10;
	//x += 5;		// 15

	//// list of all
	//// = ^
	//// += ^
	//// -= subtracts a value to a variable
	//// *= multiplies a value to a variable
	//// /= divides a value to a variable
	//// %= percentages
	//// &= 
	//// |=
	//// ^=
	//// >>=
	//// <<=

	//// Comparison Operators
	//// Booleans (true or false)

	//int x = 5;
	//int y = 3;
	//cout << (x > y) << endl; // returns 1 (true) because 5 is greater than 3

	//// list of all
	//// == equal to
	//// != not equal
	//// > greater than
	//// < less than
	//// >= greater than or equal to
	//// <= less than or equal to

	//// Logical Operators
	//// used to determine the logic between variables or values

	//// && Logical and	(Returns true if both statements are true)
	//// || Logical or	(Returns true if one of the statements is true)
	//// ! Logical not	(Reverse the result, returns false if the result is true)

	//// Strings
	//string greeting = "Hello";

	////Include the <string> library (see top)

	//// Create a string variable
	//string greeting = "Hello";

	//// String Concatenation
	//string firstName = "John ";
	//string lastName = "Doe";
	//string fullName = firstName + lastName;
	//cout << fullName;

	//string firstName = "John";
	//string lastName = "Doe";
	//string fullName = firstName + " " + lastName;
	//cout << fullName;
	
	//// Append
	//string firstName = "John ";
	//string lastName = "Doe";
	//string fullName = firstName.append(lastName);
	//cout << fullName;

	//// Adding Number and Strings
	//int x = 10;
	//int y = 20;
	//int z = x + y;	// z will be 30 (an integer)

	//string x = "10";
	//string y = "20";
	//string z = x + y;	// z will be 1020 (a string)

	//string x = "10";
	//int y = 20;
	//string z = x + y;	// error

	//// String Length
	//string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//cout << "The lenght of the txt string is: " << txt.length();

	//string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//cout << "The length of the txt string is: " << txt.size();

	//// Access Strings
	//string myString = "Hello";
	////cout << myString[0];
	////// Outputs H
	////cout << myString[1];
	////// Outputs e
	//myString[0] = 'J';
	//cout << myString;
	//// Outputs Jello instead of Hello

	// Strings - Special Characters 
	//string txt = "We are the so called "Vikings" from the north."; // error
	// \' " single quote
	// \" " double quote
	// \\ \ backslah
	
	//string txt = "We are the so called \"Vikings\" from the north.";

	//string txt = "It\'s alright."

	//string txt = "The character \\ is called backslash.";
	
	// other
	// \n new line
	// \t tab

	//// User Input Strings
	//string firstName;
	//cout << "Type your first name: ";
	//cin >> firstName; // get user input from the keyboard
	//cout << "Your name is: " << firstName;

	//// Type your first name: John
	//// Your name is: John

	//string fullName;
	//cout << "Type your full name: ";
	//cin >> fullName;
	//cout << "Your name is: " << fullName;

	//// Type your full name: John Doe
	//// Your name is: John

	//string fullName;
	//cout << "Type your full name: ";
	//getline (cin, fullName);
	//cout << "Your name is: " << fullName;

	//// Type your full name: John Doe
	//// Your name is: John Doe

	// Omitting Namespace
	//#include <iostream>
	//#include <string>

	////int main() {
	///*std::*/string greeting = "Hello";
	///*std::*/cout << greeting;
	////return 0;
	////}

	///* C++ Math */
	//// max(x, y) finds highest value of x and y
	//cout << max(5, 10) << endl;

	//// min(x, y) finds lowest value of x and y
	//cout << min(5, 10);

	//// C++ <cmath> Header
	////include the cmath library (see top)
	//cout << sqrt(64) << endl;
	//cout << round(2.6) << endl;
	//cout << log(2);

	// Other Math Functions
	// abs(x) returns the absolute value of x
	// acos(x) returns the arccosine of x
	// asin(x) returns the arcsine of x
	// atan(x) returns the arctangent of x
	// cbrt(x) returns the cube root of x
	// ceil(x) returns the value of x rounded up to its nearest integer
	// cos(x) returns the cosine of x
	// cosh(x) returns the hyperbolic cosine of x
	// exp(x) returns the value of E^x
	// expm1(x) returns e^x -1
	// fabs(x) returns the absolute value of a floating x
	// fdim(x, y) returns the positive difference between x and y
	// floor(x) returns the value of x rounded down to its nearest integer
	// hypot(x, y) returns sqrt(x^2+y^2) without intermediate overflow or underflow
	// fma(x, y, z) returns x*y+z without losing precision
	// fmax(x, y) returns the highest value of a floating x and y
	// fmin(x, y) returns the lowest value of a floating x and y
	// fmod(x, y) returns the floating point remainder of x/y
	// pow(x, y) returns the value of x to the power of x/y
	// sin(x) returns the sine of x (x is in radians)
	// sinh(x) returns the hyperbolic sine of a double value
	// tan(x) returns the tangent of an angle
	// tanh(x) returns the hyperbolic tangent of a double value

	//// C++ Booleans
	//bool isCodingFun = true;
	//bool isFishTasty = false;
	//cout << isCodingFun << endl; // Outputs 1 (true)
	//cout << isFishTasty; // Outputs 0 (false)
	
	//// Boolean Expression
	//int x = 10;
	//int y = 9;
	//cout << (x > y);	// returns 1 (true), because 10 is higher than 9

	//cout << (10 > 9);	// returns 1 (true), because 10 is higher than 9 

	//int x = 10;
	//cout << (x == 10);	// returns 1 (true), because the value of x is equal to 10

	//cout << (10 == 15);	// returns 0 (false), because 10 is not equal to 15

	//int myAge = 25;
	//int votingAge = 18;

	////cout << (myAge >= votingAge);	// returns 1 (true), meaning 25 year olds are allowed to vote!

	//if (myAge >= votingAge) {
	//	cout << "Old enough to vote!";
	//}
	//else {
	//	cout << "Not old enough to vote.";
	//}

	/* Conditions */

	// If Statement

	//if (condition) {
	//	// block of code to be executed if the condition is true
	//}

	//if (20 > 18) {
	//	cout << "20 is greater than 18";
	//}

	//int x = 20;
	//int y = 18;
	//if (x > y) {
	//	cout << "x is greater than y";
	//}

	// Else Statement

	//if (condition) {
	//	//block of code to be executed if the condition is true
	//} else {
	//	// block of code to be executed if the condition is false
	//}

	//int time = 20;
	//if (time < 18) {
	//	cout << "Good day.";
	//} else {
	//	cout << "Good evening.";
	//}
	//// Outputs "Good evening."

	// Else If Statement

	//if (condition1) {
	//// block of code to be executed f condition1 is true
	//}
	//else if (condition2) {
	//// block of code to be executed if the condition1 is false and condition2 is true
	//} else {
	//// block of code to be executed if the condition1 is false and condition2 is false 
	//}

	//int time = 22;
	//if (time < 10) {
	//	cout << "Good morning.";
	//} else if (time < 20) {
	//	cout << "Good day.";
	//} else {
	//	cout << "Good evening.";
	//}
	//// Outputs "Good evening."

	// Short Hand If..Else (Ternary Operator)

	//variable = (condition) ? expressionTrue : expressionFalse;

	//int time = 20;
	//string result = (time < 18) ? "Good day." : "Good evening.";
	//cout << result;

	/* Switch */

	// Switch Statements

	//switch (expression) {
	//case x:
	//	// code block
	//	break;
	//case y:
	//	// code block
	//	break;
	//default:
	//	// code block
	//}

	//int day = 4;
	//switch (day) {
	//	case 1:
	//		cout << "Monday";
	//		break;
	//	case 2:
	//		cout << "Tuesday";
	//		break;
	//	case 3:
	//		cout << "Wednesday";
	//		break;
	//	case 4:
	//		cout << "Thursday";
	//		break;
	//	case 5:	
	//		cout << "Friday";
	//		break;
	//	case 6:
	//		cout << "Saturday";
	//		break;
	//	case 7:
	//		cout << "Sunday";
	//		break;
	//}

	//// Outputs "Thursday" (day 4)

	//int day = 4;
	//switch (day) {
	//	case 6:
	//		cout << "Today is Saturday";
	//		break;
	//	case 7:
	//		cout << "Today is Sunday";
	//		break;
	//	default:
	//		cout << "Looking forward to the Weekend";
	//}

	//// Outputs "Looking forward to the Weekend"

	/* Loops */

	// While Loop

	//while (condition) {
	//	// code block to be executed
	//}

	//int i = 0;
	//while (i < 5) {
		//cout << i << "\n";
		//i++;
	//}

	// Do/While

	//do {
	//	// code block to be executed
	//} 
	//while (condition);

	//int i = 0;
	//do {
	//	cout << i << "\n";
	//	i++;
	//} 
	//while (i < 5);

	// For Loop

	//for (statement 1; statement 2; statement 3) {
	//	// code block to be executed
	//}

	//for (int i = 0; i < 5; i++) {
	//	cout << i << "\n";
	//}

	//for (int i = 0; i <= 10; i = i + 2) {
		//cout << i << "\n";
	//}

	//// Outer loop 
	//for (int i = 1; i <= 2; ++i) {
	//	cout << "Outer: " << i << "\n"; // Executes 2 times

	//	// Inner loop
	//	for (int j = 1; j <= 3; ++j) {
	//		cout << " Inner: " << j << "\n"; // Executes 6 times (2 * 3)
	//	}
	//}

	// foreach Loop

	//for (type variable : arrayName) {
	//	// code block to be executed
	//}

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i : myNumbers) {
	//		cout << i << "\n";
	//}

	// Break and Continue
	
	// Break 	

	//for (int i = 0; i < 10; i++) {
		//if (i == 4) {
			//break;
		//}
		//cout << i << "\n";
	//}

	// Continue

	//for (int i = 0; i < 10; i++) {
		//if (i == 4) {
			//continue;
		//}
		//cout << i << "\n";
	//}

	// Break and Continue in While Loop

	// Break

	//int i = 0;
	//while (i < 10) {
		//cout << i << "\n";
		//i++;
		//if (i == 4) {
			//break;
		//}
	//}

	// Continue

	//int i = 0;
	//while (i < 10) {
		//if (i == 4) {
			//i++;
			//continue;
		//}
		//cout << i << "\n";
		//i++;
	//}

	/* Arrays */

	//string cars[4]; = { "Volvo", "BMW", "Ford", "Mazda" };

	//int myNum[3] = { 10, 20, 30 };

	//string cars[4] = { "Volvo", "BMW", "Ford", "Mazda" };
	//cout << cars[0];
	//// Outputs Volvo

	// Change an Array Element
	//cars[0] = "Opel";

	//string cars[4] = { "Volvo", "BMW", "Ford", "Mazda" };
	//cars[0] = "Opel";
	//cout << cars[0];
	//// Now outputs Opel instead of Volvo

	// Loop Through an Array

	//string cars[5] = { "Volvo", "BMW", "Ford", "Mazda", "Tesla" };
	//for (int i = 0; i < 5; i++) {
	//	cout << cars[i] << "\n";
	//}

	//string cars[5] = { "Volvo", "BMW", "Ford", "Mazda", "Tesla" };
	//for (int i = 0; i < 5; i++) {
		//cout << i << " = " << cars[i] << "\n";
	//}

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i = 0; i < 5; i++) {
		//cout << myNumbers[i] << "\n";
	//}

	// The for-each Loop

	//for (type variableName : arrayName) {
	//// code block to be executed
	//}

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i : myNumbers) {
		//cout << i << "\n";
	//}

	// Omit Array Size

	//string cars[] = { "Volvo", "BMW", "Ford" }; // Three array elements

	//string cars[3] = { "Volvo", "BMW", "Ford" }; // Also three array elements

	//string cars[5];
	//cars[0] = "Volvo";
	//cars[1] = "BMW";
	//...

	// Array Size
	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//cout << sizeof(myNumbers);
	// Result: 20
	// 'sizeof()' shows sizes in bytes

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//int getArrayLength = sizeof(myNumbers) / sizeof(int);
	//cout << getArrayLength;

	// Loop Through an Array with sizeof()
	
	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i = 0; i < 5; i++) {
		//cout << myNumbers[i] << "\n";
	//}

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i = 0; i < sizeof(myNumbers) / sizeof(int); i++) {
	//	cout << myNumbers[i] << "\n";
	//}

	//int myNumbers[5] = { 10, 20, 30, 40, 50 };
	//for (int i : myNumbers) {
		//cout << i << "\n";
	//}

	// Multi-Dimensional Arrays

	string letters[2][4] = {
		{ "A", "B", "C", "D" },
		{ "E", "F", "G", "H" }
	};

	cout << letters[0][2]; // Outputs "C"

	// Arrays can have any number of dimensions.

	// refer to the index number of the element in each of the dimensions to change the value of an element.

	return 0;
}