#include<iostream>

using namespace std;

struct ciocolata {
	int gramaj;
	float pret;
	string nume;
	bool esteAmaruie; //DA SI NU
};

//tip_returnat nume_functie([params]) { }

void afisareCiocolata(ciocolata c) {

	cout << "Nume ciocolata:" << c.nume << endl;
	cout << "Pret ciocolata:" << c.pret << endl;
	cout << "Gramaj ciocolata:" << c.gramaj << endl;
	cout << "Este amaruie:" << (c.esteAmaruie ? "DA" : "NU") << endl;

	//conditie?dacaEAdevarat:DacaEFals
}
//void modifica, int float returneaza ceva
void modificaPret(ciocolata* c, float pretNou) {
	c->pret = pretNou; // (*c).pret
}

void modificaPretRef(ciocolata& c, float pretNou) {
	c.pret = pretNou;
}

ciocolata initializareCiocolata(int gramaj, float pret, string nume, bool amaruie) {
	ciocolata c;
	c.gramaj = gramaj;
	c.pret = pret;
	c.nume = nume;
	c.esteAmaruie = amaruie;
	return c;
}

int main() {
	ciocolata c1;
	c1 = initializareCiocolata(50, 7, "Milka", 0);
	afisareCiocolata(c1);

	ciocolata c2;
	cout << "introduceti numele:";
	cin >> c2.nume;
	cout << "introduceti pret:";
	cin >> c2.pret;
	cout << "introduceti gramaj:";
	cin >> c2.gramaj;
	cout << "Este amaruie? (1-da 0-nu)";
	cin >> c2.esteAmaruie;
	afisareCiocolata(c2);
	modificaPret(&c2, 40);
	afisareCiocolata(c2);
	modificaPretRef(c2, 60);
	afisareCiocolata(c2);

	//int a=40;
	//int* pa= &a;
}