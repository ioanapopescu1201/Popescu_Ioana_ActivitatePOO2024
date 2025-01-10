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

    Frigider(const Frigider& other) : numarUsi(obj.numarUsi) {
        this->marca = obj.marca;
        this->capacitate = obj.capacitate;
        this->pret = new float(*obj.pret);
    }

    ~Frigider() {
        delete this->pret;
    }

   
    string getMarca() const { return this->marca; }
    void setMarca(string marca) { this->marca = marca; }

    float getCapacitate() const { return this->capacitate; }
    void setCapacitate(float capacitate) { this->capacitate = capacitate; }

    float getPret() const { return *this->pret; }
    void setPret(float pret) { *(this->pret) = pret; }

    int getNumarUsi() const { return this->numarUsi; }

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

    // Getter și setter
    string getMarca() const { return this->marca; }
    void setMarca(string marca) { this->marca = marca; }

    int getCapacitateKg() const { return this->capacitateKg; }
    void setCapacitateKg(int capacitate) { this->capacitateKg = capacitate; }

    int getVitezaCentrifugare() const { return *this->vitezaCentrifugare; }
    void setVitezaCentrifugare(int viteza) { *(this->vitezaCentrifugare) = viteza; }

    bool getAreUscator() const { return this->areUscator; }

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

    CuptorMicrounde(const CuptorMicrounde& other) : capacitateLitri(obj.capacitateLitri) {
        this->marca = obj.marca;
        this->putere = obj.putere;
        this->functieDezghetare = new bool(*obj.functieDezghetare);
    }

    ~CuptorMicrounde() {
        delete this->functieDezghetare;
    }

    
    string getMarca() const { return this->marca; }
    void setMarca(string marca) { this->marca = marca; }

    int getPutere() const { return this->putere; }
    void setPutere(int putere) { this->putere = putere; }

    bool getFunctieDezghetare() const { return *this->functieDezghetare; }
    void setFunctieDezghetare(bool functie) { *(this->functieDezghetare) = functie; }

    int getCapacitateLitri() const { return this->capacitateLitri; }

    static int getNumarCuptoare() { return numarCuptoare; }
};

int CuptorMicrounde::numarCuptoare = 0;

void actualizeazaPret(Frigider& f, float procent) {
    f.setPret(f.getPret() + (f.getPret() * procent / 100));
}

void actualizeazaPutere(CuptorMicrounde& c, int valoare) {
    c.setPutere(c.getPutere() + valoare);
}


int main() {
    Frigider f1("Samsung", 350, 1500);
    f1.setPret(1600);
    cout << "Pret frigider: " << f1.getPret() << endl;

    MasinaDeSpalat m1("LG", 8, 1200);
    m1.setVitezaCentrifugare(1400);
    cout << "Viteza centrifugare: " << m1.getVitezaCentrifugare() << endl;

    CuptorMicrounde c1("Whirlpool", 800, true);
    actualizeazaPutere(c1, 200);
    cout << "Putere cuptor: " << c1.getPutere() << endl;

    return 0;
}
