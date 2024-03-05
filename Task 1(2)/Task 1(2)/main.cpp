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

	int testFind = st.Find("O");
	{
		cout << "Found index was: " << testFind << endl;
	}

	testFind = st.Find(6, "O");
	{
		cout << "Found index was: " << testFind << endl;
	}

	st.Replace("W", "M");
	{
		cout << st.CStr() << endl;
	}

	st.ReadFromConsole();
	{
	}

	st.WriteToConsole();
	{
	}

	//st1 == st2
	//st.operator==(sta);
	{
		if (st == sta)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}

	}

	//st.operator!=(stb);
	{
		if (st != stb) cout << "true" << endl;
		else cout << "false" << endl;
	}
	cout << st.CStr() << endl;
	//st.operator[8];
	{
		cout << st[2] << endl;
	}

	//st.operator=;
	{
		st = sta;
		if (st == sta)
		{
			cout << "they are equal! :)" << endl;
		}
		else
		{
			cout << "they are not equal! :(" << endl;
		}
	}

	//st.operator<;
	{

	}
}