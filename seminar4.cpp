#include <iostream>
using namespace std;

class cofetarie
{
private:
	string nume; //
	int nrAngajati; //
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;


public:

	cofetarie() :adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;

	}
	cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an)
	{
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}
	cofetarie(const cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	~cofetarie() {
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string nume)
	{
		if (nume.length() > 2) {
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
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float* getSalarii()
	{
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}
	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "nr angajati: " << this->nrAngajati << endl;
		cout << "este vegana: " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "an deschidere: " << this->anDeschidere << endl;
		cout << "adaos: " << this->adaos << endl;
		cout << "TVA: " << cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0)
			cofetarie::TVA = noulTVA;
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
		{
			suma += vector[i].nrAngajati;
		}
		return suma;
	}


};
int cofetarie::TVA = 9;

int main()
{
	cofetarie c;
	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;
	cout << c.getNrAngajati() << endl;
	c.setNrAngajati(4, new float[4] {2, 6, 4, 9});
	cout << c.getNrAngajati() << endl;

	cofetarie c2("Minimal", 3, false, 2020, 10);

	cout << c2.getSalarii()[1] << endl;
	cout << c2.getSalariu(1) << endl;
	c2.setNrAngajati(5, new float[5] {1, 2, 3, 4, 5});//dc nu e recomandat?
	cout << c2.getSalariu(3);
	cofetarie c3(c2);//cofetarie c4 = c2;, constructor de copiere

}