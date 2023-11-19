#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool checkValidInput()
{
	if (cin.fail())
	{
		throw "Incorrect input";
	}
	return true;
}

bool checkValidNumberOfIteration(double numberOfIteration)
{
	if (numberOfIteration < 2) {
		throw "Not correct number of iteration";
	}
	return true;
}

bool checkStep(double step)
{
	if (step <= 0)
	{
		throw "Step can not be <=0";
	}
	return true;
}

bool checkStartAndEnd(double start, double end)
{
	if (start > end)
	{
		throw "Input incorrrect iteration";
	}
	return true;
}


double calculate(double value, double numberOfIteration)
{
	double y = 0.;
	if (value >= 0)
	{
		for (int i = 1; i <= numberOfIteration - 1; i++)
		{
			y += (value / i);
		}
	}
	else
	{
		for (int i = 1; i <= numberOfIteration - 1; i++) {
			for (int j = 1; j <= numberOfIteration; j++) {
				y += (value - i + j);
			}
		}

	}
	return y;
}



int main()
{
	try
	{
		ofstream fout("Resultat.txt");
		double start, end, step, numberOfIteration, save;
		cout << "Input start of iterations ";
		cin >> start;
		checkValidInput();
		cout << "Input end of iterations ";
		cin >> end;
		checkValidInput();
		checkStartAndEnd(start, end);
		cout << "Input step ";
		cin >> step;
		checkValidInput();
		checkStep(step);
		cout << "Input number of iteration ";
		cin >> numberOfIteration;
		checkValidInput();
		checkValidNumberOfIteration(numberOfIteration);
		cout << "Save to file input 0 ";
		cin >> save;
		checkValidInput();

		for (; start <= end; start = start + step)
		{
			cout << "x = " << start << " y = " << calculate(start, numberOfIteration);
			cout << endl;
			if (save == 0)
			{
				fout << "x = " << start << " y = " << calculate(start, numberOfIteration);
				fout << endl;
			}
		}

	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}
	catch (const char exception_2)
	{
		cout << "Unnkown error";
	}
}
