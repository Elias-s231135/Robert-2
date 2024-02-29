#include <iostream>
#include "StringTester.h"
#include "ctype.h"

using namespace std;

int main()
{
	String st("Hello, World");
	String sta("Hello, ");
	String stb("World");

	cout << "Your letter is " << st.CharacterAt(1) << endl;

	if (st.EqualTo("Hello, World"))
	{
		cout << "true :)" << endl;
	}
	else
	{
		cout << "false >:(" << endl;
	}

	st.Append(stb);
	{
		cout << sta.CStr() << endl;
	}

	st.Prepend(sta);
	{
		cout << stb.CStr() << endl;
	}

	st.ToLower();
	{
		cout << st.CStr() << endl;
	}

	st.ToUpper();
	{
		cout << st.CStr() << endl;
	}

	st.Find(sta);
	{
		cout << st.CStr() << endl;
	}

	st.ReadFromConsole();
	{
	}

	st.WriteToConsole();
	{
	}

	st.operator==(sta);
	{
		if (st == sta) cout << "true\n";
		else cout << "false\n";
	}
}