#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

private:
    int n;  //Fj�ldi staka
    int *p;  //Bendir � fylki af n t�lum

    void initializenumbers();
};

Numbers::Numbers() {
    cout << "Constructor!" << endl;
    n = 10;
    p = new int[n];

    initializenumbers();
}

void Numbers::initalizenumbers() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
}

int main()
{
    Numbers thenumbers;

    return 0;
}
