#include "main.h"


void pliki(const string nazwaPliku, const int licznik, const char wartosc)
{
    ofstream mFile(nazwaPliku);
    int i = 0;

        for (i = 0; i < licznik; i++) {
            mFile << wartosc;

        }
}

void losowy(const string nazwaPliku, const int licznik, const char wartosc1, const char wartosc2)
{
    ofstream mFile(nazwaPliku);
    int i = 0;

    for (i = 0; i < 90; i++) {
        mFile << wartosc1;

    }
    for (i = 90; i < licznik; i++) {
        mFile << wartosc2;

    }
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}



void Porownanie(const char* Plik1, const char* Plik2) {
    ifstream file1 (Plik1, ios::binary);
    ifstream file2 (Plik2, ios::binary);
    char a{};
    char b{};
    long long int  bity = 0, ber = 0;

    while (!file1.eof())
    {
        file1 >> a;
        file2 >> b;

        if (file1.eof()) { break; }

        bity = bity + 8;
        ber = hammingDistance(a, b) + ber;

    }
	ofstream log;
    log.open("logi.txt", ios_base::app);
    if (log.good())
    {
        log << "Porownano:" << Plik1 << " i " << Plik2 << endl;
        log << "Bity: " << bity << endl;
        log << "Roznica bitow: : " << ber << endl;
		log << "*********************" << endl;
		log << endl;
        log.close();


    }

    cout << "Porownano :" << Plik1 << " i " << Plik2 << endl;
    cout << "Bity: " << bity << endl;
    cout << "Roznica bitow : " << ber << endl;


}



int main(int argc, char * argv[]) {




					   cout << "Patryk Szadkowski - Program liczacy roznice bitow - BER " << endl;
                       cout << endl;
                       cout << "Test 1" << endl;
                       pliki("plik1.bin", 100, 0x55);
                       pliki("plik2.bin", 100, 0x55);
                       Porownanie("plik1.bin","plik2.bin");
                       cout << "***********" << endl;
					   cout << "Wynik zapisano w logach!" << endl;

					   cout << "Test 2" << endl;
                       pliki("plik3.bin", 100, 0x55);
                       losowy("plik4.bin", 100, 0x55, 0x45);
                       Porownanie("plik3.bin","plik4.bin");
					   cout << "***********" << endl;
					   cout << "Wynik zapisano w logach!" << endl;


					   cout << "Test 3" << endl;
                       pliki("plik5.bin", 1024 * 1024 * 400, 0x55);
                       pliki("plik6.bin", 1024 * 1024 * 400, 0x50);
                       Porownanie("plik5.bin","plik6.bin");
					   cout << "***********" << endl;
					   cout << "Wynik zapisano w logach!" << endl;
					   cout << "Koniec programu." << endl;
                       return 0;




}
