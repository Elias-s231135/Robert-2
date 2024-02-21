#include <iostream>
#include "StringTester.h"

using namespace std;

int main()
{
	String st("Hello, ");
	String st2("World");

	cout << "Your letter is " << st.CharacterAt(1) << endl;

	if (st.EqualTo("Hello, World"))
	{
		cout << "true :)" << endl;
	}
	else
	{
		cout << "false >:(" << endl;
	}

	st.Append(st2);
	{
		cout << st.CStr() << endl;
	}

	st.Prepend(st);
	{
		cout << st2.CStr() << endl;
	}
}