#include <iostream>
#include "StringTester.h"
#include "ctype.h"
#include <fstream>

using namespace std;

std::fstream file;

void PrintDateAndTime()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int sec = newtime.tm_sec;
	int minute = newtime.tm_min;
	int hour = newtime.tm_hour;
	int day = newtime.tm_mday;
	int month = 1 + newtime.tm_mon;
	int year = newtime.tm_year;

	file << "Date: " << day << "/" << month << "/" << year + 1900 << " ";
	file << "Time:" << hour << ":" << minute << ":" << sec << "." << endl;

}

int main()
{
	float successRate = 0;
	file.open("File.txt", std::ios::app);

	PrintDateAndTime();

	String st("Hello, World");
	String sta("Hello, ");
	String stb("World");
	
	{
		if (st.CharacterAt(7) == 'W')
		{
			//cout << "Your letter is " << st.CharacterAt(1) << endl;
			file << "CharAt Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "CharAt Failed" << endl;
		}
	}

	{
		if (st.EqualTo("Hello, World"))
		{
			//cout << "true :)" << endl;
			file << "EqualTo Succesful" << endl;
			successRate += 1;
		}
		else
		{
			//cout << "false >:(" << endl;
			file << "EqualTo Failed" << endl;
		}
	}

	{
		if (st.Append(stb) == "Hello, WorldWorld")
		{
			//cout << sta.CStr() << endl;
			file << "Append Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "Append Failed" << endl;
		}
	}

	{
		if (st.Prepend(sta) == "Hello, Hello, WorldWorld")
		{
			//cout << stb.CStr() << endl;
			file << "Prepend Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "Prepend Failed" << endl;
		}
	}

	{
		st.ToLower();
		if (st == "hello, hello, worldworld")
		{
			//cout << st.CStr() << endl;
			file << "ToLower Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "ToLower Failed" << endl;
		}
	}

	{
		st.ToUpper();
		if (st == "HELLO, HELLO, WORLDWORLD")
		{
			//cout << st.CStr() << endl;
			file << "ToUpper Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "ToUpper Failed" << endl;
		}
	}

	{
		int testFind = st.Find("O");
		if (testFind == 4) // logical success / what I was expecting
		{
			//cout << "Found index was: " << testFind << endl;
			file << "Find Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "Find Failed" << endl;
		}
	}

	{
		int testFind = st.Find(6, "O");
		if (testFind == 11)
		{
			//cout << "Found index was: " << testFind << endl;
			file << "Find(startIndex) Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "Find(startIndex) Failed" << endl;
		}
	}

	{
		if (st.Replace("W", "M") == "HELLO, HELLO, MORLDMORLD")
		{
			//cout << st.CStr() << endl;
			file << "Replace Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "Replace Failed" << endl;
		}
	}

	{
		cout << "Please write the string \"Hello, World\" exactly as is:" << endl;
		st.ReadFromConsole();
		if (st == "Hello, World")
		{
			file << "ReadFromConsole Successful" << endl;
			successRate += 1;
		}
		else
		{
			file << "ReadFromConsole Failed" << endl;
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
			file << "operator== Failed" << endl;
		}
		else
		{
			//cout << "false" << endl;
			file << "operator== Successful" << endl;
			successRate += 1;
		}

	}

	//st.operator!=(stb);
	{
		if (st != stb)
		{
			//cout << "true" << endl;
			file << "operator!= Successful" << endl;
			successRate += 1;
		}
		else
		{
			//cout << "false" << endl;
			file << "operator!= Failed" << endl;
		}
	}

	cout << st.CStr() << endl;
	//st.operator[];
	{
		 if (st[2] == 'l')
		{
			//cout << st[2] << endl;
			 file << "operator[] Successful" << endl;
			 successRate += 1;
		}
		 else
		 {
			 file << "operator[] Failed" << endl;
		 }
	}

	//st.operator=;
	{
		st = sta;
		if (st == sta)
		{
			//cout << "they are equal! :)" << endl;
			file << "operator= Successful" << endl;
			successRate += 1;
		}
		else
		{
			//cout << "they are not equal! :(" << endl;
			file << "operator= Failed" << endl;
		}
	}

	//st.operator<;
	{
		if (st < stb)
		{
			//cout << "lhs is before rhs" << endl;
			file << "operator< Successful" << endl;
			successRate += 1;
		}
		else
		{
			//cout << "rhs is before lhs" << endl;
			file << "operator< Failed" << endl;
		}
	}

	successRate /= 15;
	successRate *= 100;
	file << "Successful: " << successRate << "%." << endl;

	file.close();

}

