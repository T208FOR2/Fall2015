#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    ifstream theinputfile;
    int tala,maxtala = 0,mintala = 0,fjolditolur = 0;
    string thefilename;

    cout << "Please write the name of the file: ";
    cin >> thefilename;

    theinputfile.open(thefilename.c_str());

    if (theinputfile.fail()) {
        cout << "Can't open the file!" << endl;
        exit(1);
    }

    theinputfile >> tala;



    cout << "The file contains " << fjolditolur << " numbers." << endl;
    theinputfile.close();
    return 0;
}
