#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

private:
    int n;  //Fj�ldi staka
    int *p;  //Bendir � fylki af n t�lum
};

Numbers::Numbers() {
    cout << "Constructor!" << endl;
    n = 0;
    p = NULL;
}

int main()
{
    Numbers thenumbers;

    return 0;
}
