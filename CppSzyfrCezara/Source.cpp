#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>


using namespace std;



void main()
{
	setlocale(LC_ALL, "");

	fstream f_files;
	fstream t_files;
	string s_from;
	string s_where;

	auto x = 0;
	auto szyfr = 0;

	cout << "1.Szyfrowanie " << endl << "2.Deszyfrowanie " << endl;
	cin >> x;
	cout << "Nazwa pliku z którego czytamy" << endl;
	cin >> s_from;
	cout << "Nazwa pliku do którego zapisujemy" << endl;
	cin >> s_where;
	cout << "Podaj przesuniecie" << endl;
	cin >> szyfr;

	f_files.open(s_from);
	t_files.open(s_where, ios::out);

	string t_string;
	string line;

	if (f_files.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(f_files, line))
		{

			t_string += line + '\n';
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}
	for (auto& i : t_string)
	{
		if (i > 95) i -= 32;
	}
	if (x == 1)
	{
		for (auto& i : t_string)
		{
			if ((48 <= i && i <= 57) || (65 <= i && i <= 90))
			{
				for (auto j = 0; j < szyfr; j++)
				{
					i++;
					if (i == 58) i = 65;
					if (i == 91) i = 48;
				}
			}
		}
	}
	else
	{
		for (auto& i : t_string)
		{
			if ((48 <= i && i <= 57) || (65 <= i && i <= 90))
			{
				for (auto j = 0; j < szyfr; j++)
				{
					i--;
					if (i == 47) i = 90;
					if (i == 64) i = 57;
				}
			}
		}
	}

	cout << t_string << endl;
	t_files << t_string;
	f_files.close();
	t_files.close();
}