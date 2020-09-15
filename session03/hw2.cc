/* 
    This is the actual homework assignment for homework 2
    based off of 03bfiles.cc
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void stats(const double x[], int m, double &mean, double &sdev, double &max, double &min) {
    /*
        x: input array of doubles to run stats on
        m: length of array x
        other parameters are self explanatory and are to be passed in by reference
    */

    max = 0;
    min = 100;
    double sum = 0;
    double tempValue = 0;
    for (int i = 0; i < m; i++) {
        tempValue = x[i];
        sum += tempValue;

        if (tempValue > max)
            max = tempValue;
        if (tempValue < min)
            min = tempValue;
    }

    mean = sum / (double) m;

    sum = 0;
    for (int i = 0; i < m; i++) {
        sum += pow(mean - x[i], 2);
    }
    sdev = sqrt(sum / m);
}

int main() {
    ifstream f("grades.txt");
    int n;
    if (!f.eof())
        f >> n;
    
    int temp = 0;
    double x[n];
    while(!f.eof()) {
        f >> x[temp];
        temp++;
    }

    cout << "Dataset: " << '\n';
    for (auto i : x)
        cout << i << " ";
    cout << '\n';
    
    double min, max, mean, sdev;
    stats(x, n, mean, sdev, max, min);
    cout << "min " << min << "\n";
    cout << "max " << max << "\n";
    cout << "mean " << mean << "\n";
    cout << "standard deviation " << sdev << "\n";
    return 0;
}