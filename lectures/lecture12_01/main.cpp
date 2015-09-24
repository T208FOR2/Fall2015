#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

void openinputfile(ifstream& inputfile, string thefilename);
string getnexthashtag(string texti, unsigned int& pos);


int main()
{
    string currentline;
    ifstream inputfile;
    string tag;
    string t = "#TDSBreakingNews Hillary may delay presidential campaign. Makes the election that much more intense. #TantricCampaigning";
    cout << t << endl;

    unsigned int pos = 0;
    string hashtag;

    hashtag = getnexthashtag(t, pos);
    if (hashtag != "no hash") {
        cout << hashtag << endl;
        hashtag = getnexthashtag(t, pos);
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

string getnexthashtag(string texti, unsigned int& pos) {
    unsigned int hashstart, hashend;

    hashstart = texti.find("#", pos);

    if ( hashstart < texti.length() ) {
        hashend = texti.find_first_of(" .,\n\"#;?!", hashstart+1);
        pos = hashstart+1;
        return texti.substr(hashstart, hashend - hashstart);
    }
    else {
        return "no hash";
    }
}


void openinputfile(ifstream& inputfile, string thefilename) {
    inputfile.open(thefilename.c_str());

    if (inputfile.fail()) {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

