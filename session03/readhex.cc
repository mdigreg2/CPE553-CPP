#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    ifstream f("DovKruger.calendar");
    stringstream s;
    string line, style, n1, n2;

    while (getline(f, line)) {
        // escape condition
        if (line == "")
            break;
        // ignore comments
        if (line.at(0) == '#')
            continue;

        // save the line into the stringstream
        s << line;
        // break it up into the descriptor and the numbers
        s >> style >> n1 >> n2;
        // print our result
        cout << style << '\t' << n1 << '\t' << n2 << '\n';

        // clear the streams
        s.clear();
    }
}