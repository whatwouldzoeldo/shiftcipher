#include <iostream>
#include <string.h>
using namespace std;

void enkripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout<<"Masukkan plainteks : ";
    cin.ignore(); getline (cin, plainteks);
    cout<<"Masukkan kunci (0-25): "; cin>>k;
    cipherteks = "";

    for (i=0; i<plainteks.length(); i++) {
        c = plainteks[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
        }
        cipherteks = cipherteks + c;
    }
    cout<<"Cipherteks: "<<cipherteks<<endl;
}

void dekripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout<<"Masukkan cipherteks: ";
    cin.ignore();getline (cin, cipherteks);
    cout<<"Masukkan kunci (0-25): "; cin>>k;
    plainteks = "";

    for (i=0;i<cipherteks.length();i++) {
        c = cipherteks[i];
        if (isalpha(c)){
            c= toupper(c);
            c = c - 65;
            if (c - k < 0)
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65;
            c = tolower(c);
        }
        plainteks = plainteks + c;
    }
    cout<<"Plainteks: "<<plainteks<<endl;
}

main ()
{
    int pil; bool stop;
    stop = false;

    while (!stop) {
        cout<<"Menu"<<endl;
        cout<<"1. Enkripsi"<<endl;
        cout<<"2. Dekripsi"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Pilih menu: "; cin>>pil;
        switch (pil)
        {
        case 1 : enkripsi(); break;
        case 2 : dekripsi(); break;
        case 3 : stop = true; break;
        }
    }
}
