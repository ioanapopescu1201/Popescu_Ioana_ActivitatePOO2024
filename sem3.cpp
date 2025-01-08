#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Cofetarie {
public:
	string nume;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

	Cofetarie() :anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
		this->adaos = 30;
	}
	Cofetarie(string nume, int nrAngajati, bool esteVegana, int anDeschidere, float adaos) :anDeschidere(anDeschidere) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;
	}
	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "nr angajati:" << this->nrAngajati << endl;
		cout << "este vegana:" << (this->esteVegana ? "da" : "nu") << endl;
		cout << "an deschidere:" << this->anDeschidere << endl;
		cout << "adaos:" << this->adaos << endl;
		cout << "tva:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int sumaAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}
};

int Cofetarie::TVA = 9;

int main() {
	Cofetarie c1;
	c1.afisare();

	Cofetarie::modificaTVA(19);
	Cofetarie c2("Maria", 6, false, 2000, 50);
	c2.afisare();

	Cofetarie* pointer;
	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
	//(*pointer).afisare();
	//->dereferentiere+accesare
	//[]-deplasare+dereferentiere
	pointer->afisare();

	delete pointer;

	int nrCofetarii = 3;
	Cofetarie* vector;
	vector = new Cofetarie[nrCofetarii];
	for (int i = 0; i < nrCofetarii; i++) {
		vector[i].afisare();
	}
	cout << "nr total angajati" << Cofetarie::sumaAngajati(nrCofetarii, vector);
	delete[]vector;
	return 0;
}