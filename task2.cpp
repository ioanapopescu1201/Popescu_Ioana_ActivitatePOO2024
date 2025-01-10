#include <iostream>
#include <cstring>

using namespace std;


class Frigider {
public:
    string marca;
    float capacitate;
    float* pret;
    static int numarFrigidere;
    const int numarUsi;

    
    Frigider() : numarUsi(2) {
        this->marca = "Necunoscuta";
        this->capacitate = 0;
        this->pret = new float(0);
        numarFrigidere++;
    }

    Frigider(string marca, float capacitate) : numarUsi(2) {
        this->marca = marca;
        this->capacitate = capacitate;
        this->pret = new float(0);
        numarFrigidere++;
    }

    Frigider(string marca, float capacitate, float pret) : numarUsi(2) {
        this->marca = marca;
        this->capacitate = capacitate;
        this->pret = new float(pret);
        numarFrigidere++;
    }

    ~Frigider() {
        delete this->pret;
    }

    static void afisareNumarFrigidere() {
        cout << "Numar total frigidere: " << numarFrigidere << endl;
    }

    void afisareFrigider() const {
        cout << "Frigider marca: " << this->marca
            << ", capacitate: " << this->capacitate
            << " litri, pret: " << *this->pret
            << " lei, numar usi: " << this->numarUsi << endl;
    }
};

int Frigider::numarFrigidere = 0;

// Clasa MasinaDeSpalat
class MasinaDeSpalat {
public:
    string marca;
    int capacitateKg;
    int* vitezaCentrifugare;
    static int numarMasiniDeSpalat;
    const bool areUscator;

    // Constructori
    MasinaDeSpalat() : areUscator(false) {
        this->marca = "Necunoscuta";
        this->capacitateKg = 0;
        this->vitezaCentrifugare = new int(0);
        numarMasiniDeSpalat++;
    }

    MasinaDeSpalat(string marca, int capacitateKg) : areUscator(false) {
        this->marca = marca;
        this->capacitateKg = capacitateKg;
        this->vitezaCentrifugare = new int(0);
        numarMasiniDeSpalat++;
    }

    MasinaDeSpalat(string marca, int capacitateKg, int viteza) : areUscator(true) {
        this->marca = marca;
        this->capacitateKg = capacitateKg;
        this->vitezaCentrifugare = new int(viteza);
        numarMasiniDeSpalat++;
    }

    ~MasinaDeSpalat() {
        delete this->vitezaCentrifugare;
    }

    static void afisareNumarMasini() {
        cout << "Numar total masini de spalat: " << numarMasiniDeSpalat << endl;
    }

    void afisareMasina() const {
        cout << " marca: " << this->marca
            << ", capacitate: " << this->capacitateKg
            << " kg, viteza centrifugare: " << *this->vitezaCentrifugare
            << " rpm, uscator: " << (this->areUscator ? "Da" : "Nu") << endl;
    }
};

int MasinaDeSpalat::numarMasiniDeSpalat = 0;

// Clasa CuptorMicrounde
class CuptorMicrounde {
public:
    string marca;
    int putere;
    bool* functieDezghetare;
    static int numarCuptoare;
    const int capacitateLitri;

    // Constructori
    CuptorMicrounde() : capacitateLitri(20) {
        this->marca = "Necunoscuta";
        this->putere = 0;
        this->functieDezghetare = new bool(false);
        numarCuptoare++;
    }

    CuptorMicrounde(string marca, int putere) : capacitateLitri(20) {
        this->marca = marca;
        this->putere = putere;
        this->functieDezghetare = new bool(false);
        numarCuptoare++;
    }

    CuptorMicrounde(string marca, int putere, bool functie) : capacitateLitri(30) {
        this->marca = marca;
        this->putere = putere;
        this->functieDezghetare = new bool(functie);
        numarCuptoare++;
    }

    ~CuptorMicrounde() {
        delete this->functieDezghetare;
    }

    static void afisareNumarCuptoare() {
        cout << "Numar total cuptoare cu microunde: " << numarCuptoare << endl;
    }

    void afisareCuptor() const {
        cout << " marca: " << this->marca
            << ", putere: " << this->putere
            << " W, functie dezghetare: " << (*this->functieDezghetare ? "Da" : "Nu")
            << ", capacitate: " << this->capacitateLitri << " litri" << endl;
    }
};

int CuptorMicrounde::numarCuptoare = 0;

// Functia main
int main() {
    // Frigider
    Frigider f1;
    Frigider f2("Arctic", 300);
    Frigider f3("LG", 400, 2500.99);
    f1.afisareFrigider();
    f2.afisareFrigider();
    f3.afisareFrigider();
    Frigider::afisareNumarFrigidere();

    // Masina de spalat
    MasinaDeSpalat m1;
    MasinaDeSpalat m2("Samsung", 8);
    MasinaDeSpalat m3("Bosch", 10, 1400);
    m1.afisareMasina();
    m2.afisareMasina();
    m3.afisareMasina();
    MasinaDeSpalat::afisareNumarMasini();

    // Cuptor microunde
    CuptorMicrounde c1;
    CuptorMicrounde c2("Whirlpool", 800);
    CuptorMicrounde c3("Panasonic", 1000, true);
    c1.afisareCuptor();
    c2.afisareCuptor();
    c3.afisareCuptor();
    CuptorMicrounde::afisareNumarCuptoare();

    return 0;
}
