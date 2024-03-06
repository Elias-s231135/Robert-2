#include <iostream>
#include "StringTester.h"
#include "ctype.h"

using namespace std;

int main()
{
	String st("Hello, World");
	String sta("Hello, ");
	String stb("World");
	
	{
		if (st.CharacterAt(8) == 'W')
		{
			//cout << "Your letter is " << st.CharacterAt(1) << endl;
			cout << "CharAt Successful" << endl;
		}
		else
		{
			cout << "CharAt Failed" << endl;
		}
	}

	{
		if (st.EqualTo("Hello, World"))
		{
			//cout << "true :)" << endl;
			cout << "EqualTo Succesful" << endl;
		}
		else
		{
			//cout << "false >:(" << endl;
			cout << "EqualTo Failed" << endl;
		}
	}

	{
		if (st.Append(stb) == "Hello, WorldWorld")
		{
			//cout << sta.CStr() << endl;
			cout << "Append Successful" << endl;
		}
		else
		{
			cout << "Append Failed" << endl;
		}
	}

	{
		if (st.Prepend(sta) == "Hello, Hello, WorldWorld")
		{
			//cout << stb.CStr() << endl;
			cout << "Prepend Successful" << endl;
		}
		else
		{
			cout << "Prepend Failed" << endl;
		}
	}

	{
		st.ToLower();
		if (st == "hello, hello, worldworld")
		{
			//cout << st.CStr() << endl;
			cout << "ToLower Successful" << endl;
		}
		else
		{
			cout << "ToLower Failed" << endl;
		}
	}

	{
		st.ToUpper();
		if (st == "HELLO, HELLO, WORLDWORLD")
		{
			//cout << st.CStr() << endl;
			cout << "ToUpper Successful" << endl;
		}
		else
		{
			cout << "ToUpper Failed" << endl;
		}
	}

	{
		int testFind = st.Find("O");
		if (testFind == 4) // logical success / what I was expecting
		{
			//cout << "Found index was: " << testFind << endl;
			cout << "Find Successful" << endl;
		}
		else
		{
			cout << "Find Failed" << endl;
		}
	}

	{
		int testFind = st.Find(6, "O");
		if (testFind == 11)
		{
			//cout << "Found index was: " << testFind << endl;
			cout << "Find(startIndex) Successful" << endl;
		}
		else
		{
			cout << "Find(startIndex) Failed" << endl;
		}
	}

	{
		if (st.Replace("W", "M") == "HELLO, HELLO, MORLDMORLD")
		{
			//cout << st.CStr() << endl;
			cout << "Replace Successful" << endl;
		}
		else
		{
			cout << "Replace Failed" << endl;
		}
	}

	{
		cout << "Please write the string \"Hello, World\" exactly as is:" << endl;
		st.ReadFromConsole();
		if (st == "Hello, World")
		{
			cout << "ReadFromConsole Successful" << endl;
		}
		else
		{
			cout << "ReadFromConsole Failed" << endl;
		}
	}
	
	{
		st.WriteToConsole();
		{
		}
	}

	//st1 == st2
	//st.operator==(sta);
	{
		if (st == sta)
		{
			//cout << "true" << endl;
			cout << "operator== Failed" << endl;
		}
		else
		{
			//cout << "false" << endl;
			cout << "operator== Successful" << endl;
		}

	}

	//st.operator!=(stb);
	{
		if (st != stb)
		{
			//cout << "true" << endl;
			cout << "operator!= Successful" << endl;
		}
		else
		{
			//cout << "false" << endl;
			cout << "operator!= Failed" << endl;
		}
	}

	cout << st.CStr() << endl;
	//st.operator[];
	{
		 if (st[2] == 'l')
		{
			//cout << st[2] << endl;
			 cout << "operator[] Successful" << endl;
		}
		 else
		 {
			 cout << "operator[] Failed" << endl;
		 }
	}

	//st.operator=;
	{
		st = sta;
		if (st == sta)
		{
			//cout << "they are equal! :)" << endl;
			cout << "operator= Successful" << endl;
		}
		else
		{
			//cout << "they are not equal! :(" << endl;
			cout << "operator= Failed" << endl;
		}
	}

	//st.operator<;
	{
		if (st < stb)
		{
			//cout << "lhs is before rhs" << endl;
			cout << "operator< Successful" << endl;
		}
		else
		{
			//cout << "rhs is before lhs" << endl;
			cout << "operator< Failed" << endl;
		}
	}
}