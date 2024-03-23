#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

double mappa(double x) // Funzione che mappa i punti nell'intervallo [-1,2]
{
    const double a = 1.0;
    const double b = 5.0;
    const double A = -1.0;
    const double B = 2.0;
    double y = (B-A)/(b-a) *(x-a) +A;
    return y;
}
int main()
{
    string fileName = "data.csv";
    ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    string outputFile = "result.csv";
    ofstream ofstr(outputFile);

    if(ofstr.fail())
    {
        cerr << "outFile does not exist" << endl;
        return 1;
    }
    ofstr << scientific;
    double val = 0.0;
    unsigned int countVal = 0;
    double sum = 0.0;

    ofstr << "N" << " " << "Mean" << endl;
    ofstr << setprecision(16);

    while(ifstr >> val)
    {
        countVal+=1;
        sum+=mappa(val);
        double average = sum/countVal;
        ofstr << countVal << " " << average << endl;
    }

    ifstr.close();
    ofstr.close();

    return 0;
}
