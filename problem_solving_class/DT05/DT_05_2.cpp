#include <iostream>
#include<string>
// getline(istream, str); -> istream getur veri� cin e�a ifstream
// str.find_first_of(str2)
// str.find_first_not_of(str2)
// str.find(str2)
// str.insert(pos, str2)
// str.erase(pos, n)
// str.length()

#include <cctype>
// isalpha(character)
// tolower(character)

#include<fstream>
// ifstream
// ofstream
// stream.open()
// stream.close()
// stream.fail()

#include<cstdlib>
// exit

using namespace std;

// F�ll til a� opna straum/skr�
void openInFile(ifstream& fin, string filename);
void openOutFile(ofstream& fout, string filename);

// Fall sem les � fylki
void readData(string array[], int size, istream& in );
// Fall sem prentar �t �ll st�k � fylki
void printArray(string array[], int size, ostream& out);

// F�ll til a� laga strenginn
void fixNumber( string &line);
void downBarToSpace(string &line);
void dashForDot(string &line);
void bigFirstLetter(string &line);
void smallMP3(string &line);
void smallMP3_2(string &line);

// Fall sem athuga hvort eigi a� breyta streng e�a ekki
bool fixLine(string &line);

// Skilgreini st�r�ina � fylkinu sem fasta �ar sem ekki m� breyta henni � keyrslut�ma.
// skr�in okkar inniheldur 10 l�nur svo vi� skilgreinum st�r�ina sem 10
const int SIZE = 10;

int main()
{
    // sta�setning � skr�nni
    string filename = "C:\\Users\\sarakri13\\Desktop\\songlist.txt";

    // straumur sem vi� munum tengja vi� skr�nna
    ifstream fin;

    openInFile(fin, filename);

    // Skilgreinum strengja fylki af st�r� SIZE
    string fylki[SIZE];

    // Fall sem les �r skr�nni � fylki�.
    // Hver l�na � skr�nni ver�ur eitt stak � fylkinu
    readData(fylki, SIZE, fin);

    // �ar sem vi� erum b�in a� s�kja g�gnin �� getum vi� loka� straumnum/skr�nni aftur
    fin.close();

    // �trum okkur � gegnum fylki� og eitt stak � einu -> �.e eina l�nu � einu
    // og l�gum hana ef �a� � a� gera �a�
    for( int i = 0; i < SIZE; i++)
    {
        // athugum hvort �a� eigi a� laga stak n�mer i � fylkinu
        if(fixLine(fylki[i]))
        {
            // l�gum t�lustafina �r 1.texti � 01.texti
            fixNumber(fylki[i]);
            // breytum �llum "_" � bil
            downBarToSpace(fylki[i]);
            // breytum 01.texti � 01 - texti
            dashForDot(fylki[i]);
            // breytum fyrsta staf � hverju or�i � h�staf
            bigFirstLetter(fylki[i]);
            // breytum "MP3" � "mp3"
            smallMP3(fylki[i]);
        }
    }

    // Skilgreinum straum sem ver�ur nota�ur til a� skrifa � skr�
    ofstream fout;

    // skilgreinum skr�nna sem � a� skrifa �
    // ef h�n er ekki til �� b�r forriti� hana til. Ef h�n er til �� er h�n yfirskrifu�
    string outputFileName = "C:\\Users\\sarakri13\\Desktop\\prettysonglist.txt";

    // Opnum skr�nna sem vi� �tlum a� skrifa �
    openOutFile(fout, outputFileName);

    // Skrifum gildin �r fylkinu okkar � skr�nna
    printArray(fylki, SIZE, fout);

    // lokum skr�nni
    fout.close();

    return 0;
}

// Fall sem opnar ifstream �.e inntaksskr�
void openInFile(ifstream& fin, string filename)
{
    fin.open(filename.c_str());

    if(fin.fail())
    {
        cout << " gat ekki opna� skr�" << endl;
        exit(1);
    }
}

// Fall sem opnar ofstream �.e �ttaksskr�
void openOutFile(ofstream& fout, string filename)
{
    fout.open(filename.c_str());

    if(fout.fail())
    {
        cout << " gat ekki opna� skr� " << endl;
        exit(2);
    }
}

// Fall sem les inn� fylki �ar sem st�kin eru strengir.
// H�gt er a� nota falli� b��i me� skr� og cin
// D�mi um hvernig falli� v�ri nota� me� skr�
//
//  ifstream fin;
//  openInFile(fin, filename);
//  readData(fylki, SIZE, fin);
//
// D�mi um hvernig v�ri kalla� � falli� me� cin
//  H�r �arf notandinn sj�lfur a� skrifa inn g�gnin af lyklabor�i
//
//  readData(fylki, SIZE, cin);
void readData(string array[], int size, istream& in )
{
    for( int i = 0; i < size; i++)
    {
        // nota getline �v� �g vil f� eina l�nu � hvert stak
        getline(in, array[i]);
    }
}

// Fall sem prentar �t �ll st�kin � fylkinu
// H�gt er a� nota falli� b��i me� skr� og cout
// D�mi um hvernig falli� v�ri nota� me� skr�
//      H�r myndu st�kin � fylkinu skrifast � skr�
//
//  ofstream fout;
//  openOutFile(fout, output_filename);
//  printArray(fylki, SIZE, fout);
//
// D�mi um hvernig v�ri kalla� � falli� me� cout
//      H�r myndu st�kin � fylkinu skrifast � skj�inn
//
//  printArray(fylki, SIZE, cout);

void printArray(string array[], int size, ostream& out)
{
    for( int i = 0; i < size; i++)
    {
        out << array[i] << endl;
    }
}

// Fall sem breytir streng �annig a� ef hann l�tur svona �t � byrjun
// 1.�etta er strengur
// Ver�ur hann a�
// 01.�etta er strengur
void fixNumber( string &line)
{
    unsigned int pos = 0;

    // Vi� viljum finna sta�setninguna � fyrsta stakinu sem er ekki t�lustafur
    pos = line.find_first_not_of("0123456789"); //  hef�um l�ka geta� gert -> pos = line.find_first_of(".");
    // Erum a� ganga �r skugga um a� fyrsta punkturinn s� stak n�mer 1, �.e a� strengurinn l�ti svona �t
    // 1.�etta er strengur
    if( pos == 1)
    {
        // insert skipunin virkar svona
        // line.insert(pos, str) -> b�tum vi� strengnum str � sta�setningu pos
        // b�tum strengnum "0" inn � stak n�mer 0 � line.
        // �ll hin st�kin f�rast �� eitt s�ti til h�gri.
        line.insert(0,"0");
    }
}
// Fall sem tekur inn streng og breytir �llum ni�urstrikum _ � bil
void downBarToSpace(string &line)
{
    unsigned int pos = 0;
    // Finnum sta�setningu � fyrsta "_"
    pos = line.find_first_of("_");

    // Ef �a� er ekkert "_" � strengnum �� skilar falli� line.find_first_of("_")
    // gildi sem er miklu st�rra en lengt strengsins.
    // While lykkjan keyrir �� �anga� til strengurinn inniheldur ekkert "_"
    while(pos < line.length())
    {
        // erase skipunin virkar svona
        // line.erase(pos, n) -> byrjum a� ey�a �r strengnum � sta�setningu pos og ey�um n st�kum
        // staki� sem er � sta�setningu pos er "_". Vi� viljum �v� byrja a� ey�a � pos og viljum ey�a einu staki.
        line.erase(pos,1);
        // pos er sta�setningin �ar sem "_" var og vi� viljum �v� b�ta vi� bili � �� sta�setningu � sta�in
        line.insert(pos," ");
        // uppf�rum pos breytuna og finnum n�sta "_"
        // ef vi� v�rum ekki a� ey�a �t "_" �� �yrftum vi� a� gera
        // pos = line.find_first_of("_", pos + 1);
        // �.e finna n�sta ni�urstrik sem er � eftir sta�setningu pos + 1
        pos = line.find_first_of("_");
    }
}

// Fall sem tekur inn streng og ey�ir skiptir �t fyrsta punktinum fyrir bandstrik e�a " - "
void dashForDot(string &line)
{
    unsigned int pos = 0;

    // Finnum sta�setningu � fyrsta punktinum
    pos = line.find_first_of(".");

    // Ef strengurinn inniheldur punkt �� skilar line.find_first_of(".")
    // gildi sem er minni heldur en lengd strensins.
    // Ef strengurinn inniheldur punkt �� �tlum vi� a� skipta honum �t
    if( pos < line.length())
    {
        // staki� sem er � sta�setningu pos er ".". Vi� viljum �v� byrja a� ey�a � pos og viljum ey�a einu staki.
        line.erase(pos,1);
        // pos er stasetningin �ar sem punkturinn var.
        // vi� viljum �v� b�ta vi� " - " � �� sta�setningu
        line.insert(pos, " - ");
    }

}

// Fall sem tekur inn streng og breytir fyrsta staf � hverju or�i � h�staf
// Gert er r�� fyrir a� or� s�u a�skilin me� bili
void bigFirstLetter(string &line)
{
    unsigned int pos = 0;

    // finnum sta�setningu � fyrsta bilinu
    pos = line.find_first_of(" ");

    // Til a� koma � veg fyrir a� vi� v�sum �t fyrir strenginn
    while( pos < ( line.length()-1 ) )
    {
        // athugum hvort a� n�sta stak � eftir bilinu s� b�kstafur
        // ef �etta er ekki b�kstafur �� viljum vi� ekkert gera vi�s taki�
        if(isalpha(line[pos + 1]))
        {
            // breytir n�sta staki � eftir bilinu � h�staf
            // toupper er innbygg� skipun sem tekur inn char
            line[pos + 1] = toupper(line[pos + 1]);
        }

        // Finnum n�sta bil � eftir bilinu okkar � strengnum.
        // bili� okkar var sta�sett � pos, �� viljum vi� byrja a� leita af bili � pos+1
        pos = line.find_first_of(" ", pos + 1);
    }
}

// Fall sem tekur inn streng. Ef strengurinn inniheldur MP3 �� breytir falli�
// �v� � mp3
void smallMP3(string &line)
{
    unsigned int pos = 0;

    //find skipunin virkar svona
    // pos = line.find(str) -> ef line inniheldur strenginn str �� ver�ur pos sta�setninginn � fyrsta skainu � str
    pos = line.find("MP3");
    // Ef line inniheldur "MP3" �� er pos sta�setning � M � line. Ef line inniheldur ekki "MP3"
    // �� ver�ur pos st�rri en lengdin � line
    if(pos < line.length())
    {
        // ey�um �t 3 s�kum �r sta�setningu pos
        line.erase(pos,3);
        // b�tum "mp3" inn � sta�setningu pos � sta�in
        line.insert(pos, "mp3");
    }
}

// �NNUR A�FER�
// Fall sem tekur inn streng. Ef strengurinn inniheldur MP3 �� breytir falli�
// �v� � mp3
// Falli� notar skipunina tolower
void smallMP3_2(string &line)
{
    unsigned int pos = 0;

    string str = "MP3";

    // finnum sta�setningu � str � line, �.e finnum sta�setningu � "MP3" � line
    pos = line.find(str);

    // ef line inniheldur strenginn str �� �tlum viljum breytum vi� str � l�stafi
    if(pos < line.length())
    {
        // l�tum forlykkjuna byrja � pos �ar sem pos er sta�setningin � fyrsta stakinu � str
        // �.e pos er sta�setning � M
        // Ef line l�tur svona �t
        // stutt.MP3
        // 012345678
        // �� er pos = 6
        // vi� viljum breyta �llum strengnum "MP3" � l�stafi �annig st��vunarskilyr�i er
        // i < pos + str.length()
        // ->  str.length() = 3,
        //     pos + str.length() = 9
        //     seinasta stak � str er stak n�mer 8 � line svo i < pos + str.length()
        for( unsigned int i = pos; i < pos + str.length(); i++ )
        {
            line[i] = tolower(line[i]);
        }
        // �a� hef�i veri� h�gt a� sleppa forlykkjunni og gera �etta � sta�inn
        // Ef strenguinn okkar hef�i veri� langur �� er miklu hendtugara a� kunna forlykkjuna
        //line[pos] = tolower(line[pos]);
        //line[pos+1] = tolower(line[pos+1]);
        //line[pos+2] = tolower(line[pos+2]);
    }
}

// Fall sem athugar hvort �a� eigi a� breyta streng e�a ekki
// �a� � a� breyta streng ef hann byrjar � "//"
bool fixLine(string &line)
{
    // Vi� viljum athuga hvort line[0]=='/' og line[1] == '/'.
    // Me� �v� a� gera line.length() > 1, �� er �g a� fullvissa mig um a� line innihaldi amk 2 st�k
    // Ef line v�ri t�mur strengur e�a bara eitt stak, �� v�rum f�rum vi� �t fyrir strenginn
    // �egar vi� getum line[1] == '/'
    if(line.length() > 1 && line[0] == '/' && line[1] == '/')
    {
        // Ef fyrstu 2 st�kin eru // �� � ekki a� laga strenginn
        return false;
    }
    return true;
}
