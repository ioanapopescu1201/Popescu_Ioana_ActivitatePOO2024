#include<iostream>

using namespace std;

struct Farmacie {
	char* nume;
	string adresa;
	int nrMedicamente;
	float* preturi;
};

void afisareFarmacie(Farmacie f) {
	cout << "Nume:" << f.nume << endl;
	cout << "Adresa:" << f.adresa << endl;
	cout << "Nr medicamente:" << f.nrMedicamente << endl;
	cout << "Preturi:";
	for (int i = 0; i < f.nrMedicamente; i++) {
		cout << f.preturi[i] << "";
	}
}

Farmacie citireFarmacie() {
	Farmacie f;
	cout << "La ce adresa este";
	cin >> f.adresa;
	cout << "ce nume are";
	char buffer[100];
	cin >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer);
	cout << "nr medicamente";
	cin >> f.nrMedicamente;
	f.preturi = new float[f.nrMedicamente];
	cout << "preturi";
	for (int i = 0; i < f.nrMedicamente; i++) {
		cin >> f.preturi[i];
	}
	return f;
}

int main() {
	Farmacie* pointer;
	pointer = new Farmacie();
	pointer->adresa = "Romana";
	pointer->nume = new char[strlen("Catena") + 1];
	strcpy_s(pointer->nume, strlen("Catena") + 1, "Catena");
	pointer->nrMedicamente = 5;
	pointer->preturi = new float[pointer->nrMedicamente];
	for (int i = 0; i < pointer->nrMedicamente; i++) {
		pointer->preturi[i] = i + 1;
	}

	afisareFarmacie(*pointer);
	int nrFarmacii = 3;
	Farmacie* vector;
	vector = new Farmacie[nrFarmacii];
	for (int i = 0; i < nrFarmacii; i++) {
		afisareFarmacie(vector[i]);
	}
	/*Farmacie** pointeri;
	pointeri = new Farmacie * [4];*/


	return 0;
}

