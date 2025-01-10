#include <iostream>
#include <cstring>

using namespace std;

class Frigider {
private:
    string marca;
    float capacitate;
    float* pret;
    static int numarFrigidere;
    const int numarUsi;

public:
    Frigider() : numarUsi(2) {
        this->marca = "Necunoscuta";
        this->capacitate = 0.0;
        this->pret = new float(0.0);
        numarFrigidere++;
    }

    Frigider(string marca, float capacitate) : numarUsi(2) {
        this->marca = marca;
        this->capacitate = capacitate;
        this->pret = new float(0.0);
        numarFrigidere++;
    }

    Frigider(string marca, float capacitate, float pret) : numarUsi(2) {
        this->marca = marca;
        this->capacitate = capacitate;
        this->pret = new float(pret);
        numarFrigidere++;
    }

    Frigider(const Frigider& obj) : numarUsi(obj.numarUsi) {
        this->marca = obj.marca;
        this->capacitate = obj.capacitate;
        this->pret = new float(*obj.pret);
    }

    ~Frigider() {
        delete this->pret;
    }

    Frigider& operator=(const Frigider& obj) {
        if (this != &obj) {
            this->marca = obj.marca;
            this->capacitate = obj.capacitate;
            *(this->pret) = *(obj.pret);
        }
        return *this;
    }

    Frigider operator+(float valoare) const {
        return Frigider(this->marca, this->capacitate, *(this->pret) + valoare);
    }

    bool operator<(const Frigider& obj) const {
        return this->capacitate < obj.capacitate;
    }

    friend ostream& operator<<(ostream& os, const Frigider& f) {
        os << "Frigider marca: " << f.marca << ", capacitate: " << f.capacitate
            << ", pret: " << *(f.pret) << " lei, numar usi: " << f.numarUsi;
        return os;
    }

    float getPret() const { return *this->pret; }
    void setPret(float pret) { *(this->pret) = pret; }

    static int getNumarFrigidere() { return numarFrigidere; }
};

int Frigider::numarFrigidere = 0;

class MasinaDeSpalat {
private:
    string marca;
    int capacitateKg;
    int* vitezaCentrifugare;
    static int numarMasiniDeSpalat;
    const bool areUscator;

public:
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

    MasinaDeSpalat(const MasinaDeSpalat& obj) : areUscator(obj.areUscator) {
        this->marca = obj.marca;
        this->capacitateKg = obj.capacitateKg;
        this->vitezaCentrifugare = new int(*obj.vitezaCentrifugare);
    }

    ~MasinaDeSpalat() {
        delete this->vitezaCentrifugare;
    }

    MasinaDeSpalat& operator=(const MasinaDeSpalat& obj) {
        if (this != &obj) {
            this->marca = obj.marca;
            this->capacitateKg = obj.capacitateKg;
            *(this->vitezaCentrifugare) = *(obj.vitezaCentrifugare);
        }
        return *this;
    }

    MasinaDeSpalat operator-(int valoare) const {
        return MasinaDeSpalat(this->marca, this->capacitateKg, *(this->vitezaCentrifugare) - valoare);
    }

    bool operator>(const MasinaDeSpalat& obj) const {
        return *(this->vitezaCentrifugare) > *(obj.vitezaCentrifugare);
    }

    friend ostream& operator<<(ostream& os, const MasinaDeSpalat& m) {
        os << "Masina de spalat marca: " << m.marca << ", capacitate: " << m.capacitateKg
            << ", viteza centrifugare: " << *(m.vitezaCentrifugare);
        return os;
    }

    int getVitezaCentrifugare() const { return *this->vitezaCentrifugare; }
    void setVitezaCentrifugare(int viteza) { *(this->vitezaCentrifugare) = viteza; }

    static int getNumarMasiniDeSpalat() { return numarMasiniDeSpalat; }
};

int MasinaDeSpalat::numarMasiniDeSpalat = 0;

class CuptorMicrounde {
private:
    string marca;
    int putere;
    bool* functieDezghetare;
    static int numarCuptoare;
    const int capacitateLitri;

public:
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

    CuptorMicrounde(const CuptorMicrounde& obj) : capacitateLitri(obj.capacitateLitri) {
        this->marca = obj.marca;
        this->putere = obj.putere;
        this->functieDezghetare = new bool(*obj.functieDezghetare);
    }

    ~CuptorMicrounde() {
        delete this->functieDezghetare;
    }

    CuptorMicrounde& operator=(const CuptorMicrounde& obj) {
        if (this != &obj) {
            this->marca = obj.marca;
            this->putere = obj.putere;
            *(this->functieDezghetare) = *(obj.functieDezghetare);
        }
        return *this;
    }

    CuptorMicrounde operator*(int factor) const {
        return CuptorMicrounde(this->marca, this->putere * factor, *(this->functieDezghetare));
    }

    bool operator!() const {
        return !*(this->functieDezghetare);
    }

    friend ostream& operator<<(ostream& os, const CuptorMicrounde& c) {
        os << "Cuptor microunde marca: " << c.marca << ", putere: " << c.putere
            << " W, functie dezghetare: " << (*(c.functieDezghetare) ? "Da" : "Nu")
            << ", capacitate: " << c.capacitateLitri << " litri";
        return os;
    }

    int getPutere() const { return this->putere; }
    void setPutere(int putere) { this->putere = putere; }

    static int getNumarCuptoare() { return numarCuptoare; }
};

int CuptorMicrounde::numarCuptoare = 0;

int main() {
    Frigider f1("Samsung", 350, 1500);
    Frigider f2("LG", 300, 1200);
    Frigider f3 = f1 + 200;
    cout << f3 << endl;

    MasinaDeSpalat m1("Bosch", 8, 1400);
    MasinaDeSpalat m2("Whirlpool", 10, 1200);
    MasinaDeSpalat m3 = m1 - 200;
    cout << m3 << endl;

    CuptorMicrounde c1("Whirlpool", 800, true);
    CuptorMicrounde c2("Samsung", 1000, false);
    CuptorMicrounde c3 = c1 * 2;
    cout << c3 << endl;

    return 0;
}
