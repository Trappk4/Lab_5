
#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 
       ofstream fout("Resultat.txt");
    double start, end, step, numberOfIteration, save;
    cout << "Input start of iterations ";
    cin >> start;
    cout << "Input end of iterations ";
    cin >> end;
    cout << "Input step ";
    cin >> step;
    cout << "Input number of iteration ";
    cin >> numberOfIteration;
    cout << "Save to file input 0  ";
    cin >> save;

    if (numberOfIteration >= 2 && step > 0 && start<end )
    {
        for (; start <= end; start = start + step) {
            if (start >= 0) 
            {
                double y = 0;
                for (int i = 1; i <= numberOfIteration - 1; i++) 
                {
                    y += (start / i);
                }
                if (save == 0) 
                {
                    fout << "x = " << start << " y = " << y << '\n';
                }
                cout << "x = " << start << " y = " << y << '\n';
            }
            else
            {
                double y = 0.;
                for (int i = 1; i <= numberOfIteration - 1; i++) {
                    for (int j = 1; j <= numberOfIteration; j++) {
                        y += (start - i + j);
                    }
                }
                if (save == 0)
                {
                    fout << "x = " << start << " y = " << y << '\n';
                }
                cout << "x = " << start << " y = " << y << '\n';
            }
        }
        
    }
    else 
    {
        if (save == 0) {
          fout << "Incorrect input!!!" << '\n';
        }
       
        cout << "Incorrect input!!!" << '\n';
    }
   
}



   

