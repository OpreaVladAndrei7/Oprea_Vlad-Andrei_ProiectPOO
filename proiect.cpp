#include < iostream>
using namespace std;
//domeniul avioanelor cu obiectele: Avion; Aeroport; CompanieAeriana
class Avion {
public:
	string model;
	static int nrInitialAvioane;
	const int nrAvioane;
	int nrTurbine;
	string* numeTurbine;

	static int initializareNrAvioane(int nrInitialAvioane) {
		return nrInitialAvioane;
	};

	Avion() : nrAvioane(nrInitialAvioane++) {
		model = "Boeing 49";
		nrTurbine = 3;
		numeTurbine = new string[3];
		numeTurbine[0] = "General Electric CFM56";
		numeTurbine[1] = "Rolls-Royce Trent XWB";
		numeTurbine[2] = "Pratt & Whitney JT8D";
	}
	Avion(string model) : nrAvioane(nrInitialAvioane++) {
		this->model = model;
		nrTurbine = 2;
		numeTurbine = new string[2];
		numeTurbine[0] = "Gen Electric C12M56";
		numeTurbine[1] = "Trent AIR XWB";
	}
	Avion(string model, int nrTurbine, string *numeTurbine) : nrAvioane(nrInitialAvioane++) {
		this->model = model;
		this->nrTurbine = nrTurbine;
		this->numeTurbine = new string[nrTurbine];
		for (int i = 0; i < nrTurbine; i++) {
			this->numeTurbine[i] = numeTurbine[i];
		}
	}
	void afisareAvion() {
		cout<<"Avionul: "<<nrAvioane<<" "<< model << " are un numar de " << nrTurbine << " turbine cu denumirile: ";
		for (int i = 0; i < nrTurbine; i++)
		{cout << numeTurbine[i] << " "; 
		}
		cout << endl;
	}
};

int Avion::nrInitialAvioane = 30000;

class Aeroport {
public:
	string numeAeroport;
	static int numarInitial;
	const int numarAeroporturi;
	int nrProduse;
	float* pretProdus;

	static int initializareNumarInitial(int numarInitial) {
		return numarInitial;
	}

	Aeroport() : numarAeroporturi(numarInitial++) {
		numeAeroport = "Henri Coanda";
		nrProduse = 3;
		pretProdus = new float[3];
		pretProdus[0] = 3.44;
		pretProdus[1] = 12;
		pretProdus[2] = 5.99;
	}
	Aeroport(string numeAeroport) : numarAeroporturi(numarInitial++) {
		this->numeAeroport = numeAeroport;
		nrProduse = 2;
		pretProdus = new float[2];
		pretProdus[0] = 9.99;
		pretProdus[1] = 3.99;
	}
	Aeroport(string numeAeroport, int nrProduse, float* pretProdus) : numarAeroporturi(numarInitial++) {
		this->numeAeroport = numeAeroport;
		this->nrProduse = nrProduse;
		this->pretProdus = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->pretProdus[i] = pretProdus[i];
		}
	}
	void afisareAeroport() {
		cout << "Aeroportul: "<<numarAeroporturi <<" "<< numeAeroport << " are in cadrul acestuia un numar de: " << nrProduse << " fiecare cu pretul de: ";
		for (int i = 0; i < nrProduse; i++) {
			cout << pretProdus[i] << " ";
		}
		cout << endl;
	}
};

int Aeroport::numarInitial = 45000;

class CompanieAeriana {
public:
	string nume;
	int numarAeronave;
	float valoareNetaM;
	static float TVA;
	const string codCompanie;
	bool companieComericala;
	string* modelAeronava;

	static int initializareTVA(float TVA) {
		return TVA;
	}

	CompanieAeriana(): codCompanie("E3F108") {
		nume = "WizAir";
		numarAeronave = 2;
		valoareNetaM = 4.2;
		companieComericala = true;
		modelAeronava = new string[2];
		modelAeronava[0] = "Aircraft 1203";
		modelAeronava[1] = "Space Passenger23";
	}
	CompanieAeriana(float valoareNetaM) : codCompanie("1290ES") {
		nume = "RYANAIR";
		numarAeronave = 3;
		this->valoareNetaM = valoareNetaM;
		companieComericala = true;
		modelAeronava = new string[3];
		modelAeronava[0] = "Aircraft S203";
		modelAeronava[1] = "Space Passenger223";
		modelAeronava[2] = "AirManager 23";
	}
	CompanieAeriana(string nume, int numarAeronave, float valoareNetaM, bool companieComerciala, string* modelAeronava) : codCompanie("WE23ER2") {
		this->nume = nume;
		this->numarAeronave = numarAeronave;
		this->valoareNetaM = valoareNetaM;
		this->companieComericala = companieComerciala;
		this->modelAeronava = new string[numarAeronave];
		for (int i = 0; i < numarAeronave; i++) {
			this->modelAeronava[i] = modelAeronava[i];
		}
	}
	void afisareCompanie() {
		cout << "Compania " <<codCompanie<<" "<< nume << " are o valoare neta de " << valoareNetaM << "si un numare de: " << numarAeronave << " aeronave ";
		for (int i = 0; i < numarAeronave; i++) {
			cout << modelAeronava[i] << " ";
		}
		cout << endl;
	}
};

float CompanieAeriana::TVA = 9;

void main() {

	Avion avion1;
	avion1.afisareAvion();
	Avion avion2("Boeing23");
	avion2.afisareAvion();
	string* numeTurbine = new string[3];
	numeTurbine[0] = "General Electric CFM56";
	numeTurbine[1] = "Rolls-Royce Trent XWB";
	numeTurbine[2] = "Pratt & Whitney JT8D";
	Avion avion3("Electro 23 air", 3, numeTurbine);
	avion3.afisareAvion();

	Aeroport aeroport1;
	aeroport1.afisareAeroport();
	Aeroport aeroport2("Henri Coanda");
	aeroport2.afisareAeroport();
	float* pretProdus = new float[3];
	pretProdus[0] = 5;
	pretProdus[1] = 2;
	pretProdus[2] = 59;
	Aeroport aeroport3("King Fahd", 3, pretProdus);
	aeroport3.afisareAeroport();

	CompanieAeriana companie1;
	companie1.afisareCompanie();
	CompanieAeriana companie2(130);
	companie2.afisareCompanie();
	string* modelAeronava = new string[2];
	modelAeronava[0] = "Traveleer Air 23";
	modelAeronava[1] = "Boeing 45";
	CompanieAeriana companie3("Turkish Airlines", 2, 980, true, modelAeronava);
	companie3.afisareCompanie();

}