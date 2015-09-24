#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

void openinputfile(ifstream& inputfile, string thefilename);

int main()
{
    string currentline;
    ifstream inputfile;
    string tag;
    string t = "#TDSBreakingNews Hillary may delay presidential campaign. Makes the election that much more intense. #TantricCampaigning";
    cout << t << endl;

    unsigned int hashstart, hashend;

    hashstart = t.find("#");
    while ( hashstart < t.length() ) {
        hashend = t.find_first_of(" .,\n\"#;?!", hashstart+1);
        tag = t.substr(hashstart, hashend - hashstart);

        hashstart = t.find("#", hashstart+1);
    }

    /*
    openinputfile(inputfile, THEFILENAME);

    while (!inputfile.eof()) {
        getline(inputfile, currentline);
        cout << currentline << endl;
    }


    inputfile.close();
*/

    return 0;
}

void openinputfile(ifstream& inputfile, string thefilename) {
    inputfile.open(thefilename.c_str());

    if (inputfile.fail()) {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

