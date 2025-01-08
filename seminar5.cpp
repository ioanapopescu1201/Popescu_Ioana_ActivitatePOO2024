#include<iostream>

using namespace std;

class Cofetarie {
private:
	string nume;
	int nrAngajati;
	float* salarii;
	bool esteVegana;
	const int anDeschidere;   //anul deschiderii nu se modifica -> atribut constant;
	float adaos;
	static int TVA;

public:
	//constructor: nu are tip returnat si are acelasi nume ca si clasa
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}
	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}


	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		//string nume;
		//int nrAngajati;
		//float* salarii;
		//bool esteVegana;
		//const int anDeschidere;  
		//float adaos;
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}

	~Cofetarie() {
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	Cofetarie& operator+(Cofetarie c) {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		return temp;
	}

	Cofetarie operator=(const Cofetarie c) {
		if (&c != this) {  //verificare de autoasignare
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}


	string getNume() {
		return this->nume;
	}

	//void pt ca e setter si nu returneaza nimic
	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c2)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;

		return temp;

	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}
	Cofetarie operator+=(Cofetarie c) {  //+= -> facem modificarea in this; + -> this este constant
		*this = *this + c;
		return *this;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {  //operatorii sunt binari <=> primesc doar 2 parametri
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "Da" : "Nu") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {    //functie statica -> nu avem "this", deci facem cum am facut mai sus cu ::
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}

	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}


};
int Cofetarie::TVA = 9;

int main() {
	/*Cofetarie c;
	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;
	c.setNrAngajati(4, new float[4] {2, 6, 4, 9}); //initializare in-line

	Cofetarie c2("Minimal", 3, false, 2020, 10);
	cout << c2.getSalarii()[1] << endl;
	cout << c2.getSalariu(1) << endl;

	c2.setNrAngajati(5, new float[5] {1, 2, 3, 4, 5});   //de ce nu e bine
	cout << c2.getSalariu(3);

	Cofetarie c3(c2);
	Cofetarie c4 = c2;
	Cofetarie c5;
	//c5 = c2;
	c2 = c2;   //autoasignare*/


	Cofetarie c1;
	Cofetarie c2("Maria", 3, true, 2019, 10);

	int a = 9;
	int b = 6;
	int c = a + b;   //c=15

	Cofetarie c3 = c1 + c2;
	Cofetarie c4 = c1.operator + (c2);
	Cofetarie c5 = c1 + 2000.0f;   //c1.operator+(2000.0f);
	Cofetarie c6 = 3000.0f + c1;
	c1 += c2;  //c1.operator+=(c2)
	c1 = c1 + c2;
	return 765756;

}