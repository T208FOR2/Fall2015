#include <iostream>

using namespace std;

class Timi {
public:
    void set_klst(int k);
    void set_minutur(int m);
    int get_klst();
    int get_minutur();
private:
    int minutur;
    int klst;

    void fix_minutur();
    void fix_klst();
};

void Timi::set_klst(int k) {
    klst = k;
}

void Timi::set_minutur(int m) {
    minutur = m;
}

int Timi::get_klst() {
    return klst;
}
int Timi::get_minutur() {
    return minutur;
}

void fix_minutur() {
    while (minutur < 0) {
        minutur += 60;
        klst--;
    }
    while (minutur >= 60) {
        minutur -= 60;
        klst++;
    }
}

void fix_klst() {

}


int main()
{
    Timi t1;

    t1.set_klst(13);
    t1.set_minutur(21);

    cout << t1.get_klst() << ":" << t1.get_minutur() << endl;

    t1.set_klst(908374);
    t1.set_minutur(-448934);

    cout << t1.get_klst() << ":" << t1.get_minutur() << endl;

    return 0;
}
