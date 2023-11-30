#include < iostream>
#include <fstream>
using namespace std;
//domeniul avioanelor cu obiectele: Avion; Aeroport; CompanieAeriana
class Avion {
private:
	string model;
	static int nrInitialAvioane;
	const int nrAvioane;
	int nrTurbine;
	string* numeTurbine;
public:


	Avion() : nrAvioane(nrInitialAvioane++) {
		model = "Boeing 49";
		nrTurbine = 3;
		numeTurbine = new string[3];
		numeTurbine[0] = "General_Electric_CFM56";
		numeTurbine[1] = "Rolls-Royce_Trent_XWB";
		numeTurbine[2] = "Pratt & Whitney_JT8D";
	}
	Avion(string model) : nrAvioane(nrInitialAvioane++) {
		this->model = model;
		nrTurbine = 2;
		numeTurbine = new string[2];
		numeTurbine[0] = "Gen_Electric_C12M56";
		numeTurbine[1] = "Trent_AIR_XWB";
	}
	Avion(string model, int nrTurbine, string* numeTurbine) : nrAvioane(nrInitialAvioane++) {
		this->model = model;
		this->nrTurbine = nrTurbine;
		this->numeTurbine = new string[nrTurbine];
		for (int i = 0; i < nrTurbine; i++) {
			this->numeTurbine[i] = numeTurbine[i];
		}
	}

	Avion(const Avion& a) : nrAvioane(nrInitialAvioane++) {
		this->model = a.model;
		this->nrTurbine = a.nrTurbine;
		this->numeTurbine = new string[nrTurbine];
		for (int i = 0; i < nrTurbine; i++) {
			this->numeTurbine[i] = a.numeTurbine[i];
		}
	};
	~Avion() {
		if (nrTurbine > 0) {
			delete[]this->numeTurbine;
		}
	}

	void afisareAvion() {
		cout << "Avionul: " << nrAvioane << " " << model << " are un numar de " << nrTurbine << " turbine cu denumirile: ";
		for (int i = 0; i < nrTurbine; i++)
		{
			cout << numeTurbine[i] << " ";
		}
		cout << endl;
	}

	static int getInitializareNrAvioane() {
		return nrInitialAvioane;
	};
	string getModel() {
		return model;
	}
	void setModel(string model) {
		this->model = model;
	}
	int getNrAvioane() {
		return nrAvioane;
	}
	int getNrTurbine() {
		return nrTurbine;
	}
	void setNrTurbine(int nrTurbine) {
		this->nrTurbine = nrTurbine;
	}
	string* getNumeTurbine() {
		return numeTurbine;
	}
	void setNumeTurbine(string* numeTurbine, int nrTurbine) {
		if (this->nrTurbine > 0) {
			delete[]this->numeTurbine;
			this->numeTurbine = new string[nrTurbine];
			for (int i = 0; i < nrTurbine; i++) {
				this->numeTurbine[i] = numeTurbine[i];
			}
		}
	}
	int lungimeString = 0;
	void afisareFisBin() {
		fstream f("avi.dat", ios::binary | ios::out);
			lungimeString = sizeof(this->model);
			f.write((char*)&lungimeString, sizeof(int));
			f.write(this->model.c_str(), lungimeString);
			f.write((char*)&this->nrTurbine, sizeof(int));
			f.close();
	}

	void citireFisBin() {
		fstream g("avi.dat", ios::binary | ios::in);
		int lungimeString = 0;
		g.read((char*)&lungimeString, sizeof(int));
		char* buffer = new char[lungimeString];
		g.read(buffer, lungimeString);
		this->model=buffer;
		delete[] buffer;

		cout <<  this->model << endl;

		g.read((char*)&this->nrTurbine, sizeof(int));
		cout<< this->nrTurbine << endl;
		g.close();
	
	}

	Avion operator=(const Avion& av) {
		this->model = av.model;
		this->nrInitialAvioane = av.nrInitialAvioane;
		if (this->nrTurbine > 0) {
			delete[]this->numeTurbine;
		}
		this->nrTurbine = av.nrTurbine;
		this->numeTurbine = new string[nrTurbine];
		for (int i = 0; i < nrTurbine; i++) {
			this->numeTurbine[i] = av.numeTurbine[i];
		}
		return*this;
	}
	Avion operator+(const Avion& av) {
		Avion aux;
		aux.nrTurbine = this->nrTurbine + av.nrTurbine;
		aux.numeTurbine = new string[aux.nrTurbine];
		for (int i = 0; i < this->nrTurbine; i++) {
			aux.numeTurbine[i] = this->numeTurbine[i];
		}
		for (int i = this->nrTurbine; i < aux.nrTurbine; i++) {
			aux.numeTurbine[i] = av.numeTurbine[i - this->nrTurbine];
		}
		return aux;
	}
	bool operator>(const Avion& av) {
		return (this->nrTurbine > av.nrTurbine);
	}
	friend ostream& operator<<(ostream& avion, const Avion& a) {
		avion << a.model << " ";
		avion << a.nrAvioane << " ";
		avion << a.nrInitialAvioane << " ";
		avion << a.nrTurbine << " ";
		for (int i = 0; i < a.nrTurbine; i++) {
			avion << a.numeTurbine[i] << " ";
		}
		return avion;
	}
	friend istream& operator>>(istream& av, Avion& a) {
		cout << "Model:" << endl;
		av >> a.model;
		if (a.nrTurbine != NULL) delete[]a.numeTurbine;
		cout << "Numar Turbine:" << endl;
		av >> a.nrTurbine;
		a.numeTurbine = new string[a.nrTurbine];
		for (int i = 0; i < a.nrTurbine; i++) {
			cout << "Numele turbinei" << i + 1 << endl;
			av >> a.numeTurbine[i];
		}
		return av;

	}
	friend ofstream& operator<<(ofstream& ofs, const Avion& a) {
		ofs << a.model << endl;
		ofs<< a.nrTurbine << endl;
		for (int i = 0; i < a.nrTurbine; i++) {
			ofs << a.numeTurbine[i] << " ";
		}
		ofs << endl;
		ofs << a.nrAvioane << endl;
		ofs << a.nrInitialAvioane << endl;
		return ofs;
	}
	friend ifstream& operator>>(ifstream& ifs, Avion& a) {
		ifs >> a.model;
		if (a.nrTurbine != NULL) delete[]a.numeTurbine;
		ifs >> a.nrTurbine;
		a.numeTurbine = new string[a.nrTurbine];
		for (int i = 0; i < a.nrTurbine; i++) {
			ifs >> a.numeTurbine[i];
		}
		return ifs;
	}
	friend float medieTurbinePeAvion(const Avion& avi);
	friend string getSirNumeTurbine(const Avion& avi);
};

float medieTurbinePeAvion(const Avion& avi) {
	return avi.nrTurbine / avi.nrAvioane;
}

string getSirNumeTurbine(const Avion& avi) {
	string aux = "";
	for (int i = 0; i < avi.nrTurbine; i++) {
		aux = aux + " " + avi.numeTurbine[i];

	}
	return aux;
}

int Avion::nrInitialAvioane = 30000;

class Aeroport {
private:
	string numeAeroport;
	static int numarInitial;
	const int numarAeroporturi;
	int nrProduse;
	float* pretProdus;

public:


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
	Aeroport(const Aeroport& ae) : numarAeroporturi(numarInitial++) {
		this->numeAeroport = ae.numeAeroport;
		this->nrProduse = ae.nrProduse;
		this->pretProdus = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->pretProdus[i] = ae.pretProdus[i];
		}
	}
	~Aeroport() {
		if (nrProduse > 0) {
			delete[]this->pretProdus;
		}
	}
	void afisareAeroport() {
		cout << "Aeroportul: " << numarAeroporturi << " " << numeAeroport << " are in cadrul acestuia un numar de: " << nrProduse << " produse fiecare cu pretul de: ";
		for (int i = 0; i < nrProduse; i++) {
			cout << pretProdus[i] << " ";
		}
		cout << endl;
	}
	static int getInitializareNumarInitial() {
		return numarInitial;
	}

	string getNumeAeroport() {
		return numeAeroport;
	}
	void setNumeAeroport(string numeAeroport) {
		this->numeAeroport = numeAeroport;
	}
	int getNrAeroport() const {
		return numarAeroporturi;
	}
	int getNrProduse() {
		return nrProduse;
	}
	void setNrProduse(int nrProduse) {
		this->nrProduse = nrProduse;
	}
	float* getPretProduse() {
		return pretProdus;
	}
	void setPretProduse(float* pretProdus, int nrProduse) {
		if (this->nrProduse > 0) {
			delete[]this->pretProdus;
			this->pretProdus = new float[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->pretProdus[i] = pretProdus[i];
			}
		}
	}
	int lungimeString1 = 0;
	void afiFisBin() {
		fstream f("aeroport.dat", ios::binary | ios::out);
		lungimeString1 = sizeof(this->numeAeroport);
		f.write((char*)&lungimeString1, sizeof(int));
		f.write(this->numeAeroport.c_str(), lungimeString1);
		f.write((char*)&this->nrProduse, sizeof(int));
		for (int i = 0; i < this->nrProduse; i++) {
			f.write((char*)&this->pretProdus[i], sizeof(float));
		}
	}
	
	void citireFisBin() {
		fstream g("aeroport.dat", ios::binary | ios::in);
		int lungimeString1 = 0;
		g.read((char*)&lungimeString1, sizeof(int));
		char* buffer = new char[lungimeString1];
		g.read(buffer, lungimeString1);
		this->numeAeroport = buffer;
		delete[]buffer;
		cout << this->numeAeroport<<endl;
		g.read((char*)&this->nrProduse, sizeof(int));
		cout << this->nrProduse<<endl;
		for (int i = 0; i < this->nrProduse; i++) {
			g.read((char*)&this->pretProdus[i], sizeof(float));
		}
		for (int i = 0; i < this->nrProduse; i++) {
			cout << this->pretProdus[i]<<endl;
		}
	}
	Aeroport operator=(const Aeroport& a) {
		this->numeAeroport = a.numeAeroport;
		this->numarInitial = a.numarInitial;
		if (this->nrProduse > 0) {
			delete[] this->pretProdus;
		}
		this->nrProduse = a.nrProduse;
		this->pretProdus = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->pretProdus[i] = a.pretProdus[i];
		}
		return *this;
	}
	Aeroport operator++(int) {
		this->nrProduse++;
		/*this->pretProdus[nrProduse - 1] = 0;*/
		return *this;
	}

	Aeroport operator+=(const Aeroport& a) {
		int aux = this->nrProduse;
		this->nrProduse += a.nrProduse;
		float* vector = new float[this->nrProduse];
		for (int i = 0; i < aux; i++) {
			vector[i] = this->pretProdus[i];
		}
		for (int i = aux; i < this->nrProduse; i++) {
			vector[i] = a.pretProdus[i - aux];
		}
		delete[]this->pretProdus;
		this->pretProdus = vector;
		return *this;
	}

	friend istream& operator>>(istream& cit, Aeroport& aer) {
		cout << "Numele aeroportului este:";
		cit >> aer.numeAeroport;
		cout << "Numar Initial al aeroportului:";
		cit >> aer.numarInitial;
		/*cit >> aer.getNrAeroport();*/
		cout << "Are un numar de produse egal cu:";
		cit >> aer.nrProduse;
		aer.pretProdus = new float[aer.nrProduse];
		for (int i = 0; i < aer.nrProduse; i++) {
			cout << "Produsul " << i + 1 << " are pretul de:";
			cit >> aer.pretProdus[i];
		}
		return cit;
	}
	friend ostream& operator<<(ostream& afi, const Aeroport& aer) {
		afi << "Aeroportul: " << aer.numarAeroporturi << " " << aer.numeAeroport << " are in cadrul acestuia un numar de: " << aer.nrProduse << " produse fiecare cu pretul de: ";
		for (int i = 0; i < aer.nrProduse; i++) {
			afi << aer.pretProdus[i] << " ";
		}
		return afi;
	}
	friend ifstream& operator>>(ifstream& cit, Aeroport& aer) {
		cit >> aer.numeAeroport;
		cit >> aer.numarInitial;
		/*cit >> aer.getNrAeroport();*/
		cit >> aer.nrProduse;
		aer.pretProdus = new float[aer.nrProduse];
		for (int i = 0; i < aer.nrProduse; i++) {
			cit >> aer.pretProdus[i];
		}
		return cit;
	}
	friend ofstream& operator<<(ofstream& afi, const Aeroport& aer) {
		afi << aer.numeAeroport << endl;
		afi << aer.numarInitial << endl;
		afi << aer.nrProduse << endl;
		for (int i = 0; i < aer.nrProduse; i++) {
			afi << aer.pretProdus[i] << " ";
		}
		afi << endl;
		afi << aer.numarAeroporturi<< endl;
		return afi;
	}
	friend float pretMediu(const Aeroport& aer);
	friend void afisarePreturi(const Aeroport& aer);
};

float pretMediu(const Aeroport& aer) {
	float total = 0;
	for (int i = 0; i < aer.nrProduse; i++) {
		total = total + aer.pretProdus[i];
	}
	return total / aer.nrProduse;
}

void afisarePreturi(const Aeroport& aer) {
	string aux = "";
	for (int i = 0; i < aer.nrProduse; i++) {
		/*aux = aux + " " + to_string(aer.pretProdus);*/
		cout << aer.pretProdus[i] << " ";
	}
	cout << endl;
}

int Aeroport::numarInitial = 45000;

class CompanieAeriana {
private:
	string nume;
	int numarAeronave;
	float valoareNetaM;
	static float TVA;
	const string codCompanie;
	bool companieComericala;
	string* modelAeronava;

public:


	CompanieAeriana() : codCompanie("E3F108") {
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
	CompanieAeriana(const CompanieAeriana& c) :codCompanie(c.codCompanie) {
		this->nume = c.nume;
		this->numarAeronave = c.numarAeronave;
		this->valoareNetaM = c.valoareNetaM;
		this->companieComericala = c.companieComericala;
		this->modelAeronava = new string[numarAeronave];
		for (int i = 0; i < numarAeronave; i++) {
			this->modelAeronava[i] = c.modelAeronava[i];
		}
	}
	~CompanieAeriana() {
		if (numarAeronave > 0) {
			delete[]this->modelAeronava;
		}
	}
	void afisareCompanie() {
		cout << "Compania " << codCompanie << " " << nume << " are o valoare neta de " << valoareNetaM << "si un numare de: " << numarAeronave << " aeronave ";
		for (int i = 0; i < numarAeronave; i++) {
			cout << modelAeronava[i] << " ";
		}
		cout << endl;
	}
	static float getInitializareTVA() {
		return TVA;
	}
	string getNume() {
		return nume;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	int getNumarAeronave() {
		return numarAeronave;
	}
	void setNumarAeronave(int numarAeronave) {
		this->numarAeronave = numarAeronave;
	}
	float getValoareNetaM() {
		return valoareNetaM;
	}
	void setValoareNetaM(float valoareNetaM) {
		this->valoareNetaM = valoareNetaM;
	}

	string getCodCompanie() {
		return codCompanie;
	}
	bool getCompanieComericala() {
		return companieComericala;
	}
	void setCompanieComerciala(bool companieComerciala) {
		this->companieComericala = companieComerciala;
	}
	string* getModelAeronava() {
		return modelAeronava;
	}
	void setModelAeronava(string* modelAeronava, int numarAeronave) {
		if (this->numarAeronave > 0) {
			delete[]this->modelAeronava;
			this->modelAeronava = new string[numarAeronave];
			for (int i = 0; i < numarAeronave; i++) {
				this->modelAeronava[i] = modelAeronava[i];
			}
		}
	}
	CompanieAeriana operator=(const CompanieAeriana& com) {
		this->nume = com.nume;
		this->valoareNetaM = com.valoareNetaM;
		this->companieComericala = com.companieComericala;
		if (this->numarAeronave > 0) { delete[]this->modelAeronava; }
		this->numarAeronave = com.numarAeronave;
		this->modelAeronava = new string[numarAeronave];
		for (int i = 0; i < numarAeronave; i++) {
			modelAeronava[i] = com.modelAeronava[i];
		}
		return *this;
	}
	string operator[](int i) {
		if (i >= 0 && i < this->numarAeronave) {
			return modelAeronava[i];
		}
	}
	CompanieAeriana operator-(const CompanieAeriana& com) {
		CompanieAeriana aux;
		aux.valoareNetaM = this->valoareNetaM - com.valoareNetaM;
		aux.numarAeronave = this->numarAeronave - com.numarAeronave;
		return aux;
	}
	friend ostream& operator<<(ostream& companie, const CompanieAeriana& com) {
		companie << "Compania aeriana: " << com.nume << " ";
		companie << "cu valoarea neta de " << com.valoareNetaM << " milioane de euro ";
		companie << "si codul companiei: " << com.codCompanie;
		companie << " prezinta un TVA de " << com.TVA << "." << endl;
		companie << "Compania are:" << com.numarAeronave << " aeronave, modelele: ";
		for (int i = 0; i < com.numarAeronave; i++) {
			companie << com.modelAeronava[i] << " ";
		}
		cout << endl;
		return companie;
	}
	friend istream& operator>>(istream& citire, CompanieAeriana& com) {
		cout << "Numele companiei este:" << endl;
		citire >> com.nume;
		cout << "Are valoarea neta in milioane de:" << endl;
		citire >> com.valoareNetaM;
		if (com.numarAeronave != NULL) delete[]com.modelAeronava;
		cout << "Are un numar de aeronave egal cu " << endl;
		citire >> com.numarAeronave;
		com.modelAeronava = new string[com.numarAeronave];
		for (int i = 0; i < com.numarAeronave; i++) {
			cout << "Modelul " << i + 1;
			citire >> com.modelAeronava[i];
		}
		return citire;
	}
	friend float valoareAbsolutaM(const CompanieAeriana& com);
	friend string sirModele(const CompanieAeriana& com);
};

class Aerodrom {
private:
	string denumire;
	float suprafata;
	Avion avion;
	/*Avion* avion;
	int nrAvioane;*/
public:
	Aerodrom() {
		this->suprafata = 1000;
		this->denumire= "AERO DROM";
		string* turbine = new string[3]{ "Boost34","Turbo22","XLR8" };
		Avion avion1("Boeing566",3,turbine);
		this->avion = avion1;
		/*this->nrAvioane = 2;
		Avion  avion1("WLR87");
		Avion avion2;
		this->avion = new Avion[nrAvioane];
		this->avion[0] = avion1;
		this->avion[1] = avion2;*/
	}
	Aerodrom(const Aerodrom& aer) {
		this->denumire = aer.denumire;
		this->suprafata = aer.suprafata;
		this->avion = aer.avion;
	}
	~Aerodrom() {

	}
	Aerodrom operator+(const Aerodrom& aer) {
		this->suprafata += aer.suprafata;
		return *this;
	}

	friend istream& operator>>(istream& citire, Aerodrom& aer) {
		cout << "Denumirea aerodromului ";
		citire >> aer.denumire;
		cout << "Suprafata: ";
		citire >> aer.suprafata;
		cout<< "Datele Avionului: ";
		citire >> aer.avion;
		return citire;
	}

	friend ostream& operator<<(ostream& afisare, const Aerodrom& aer) {
		afisare << " Aerodromul " << aer.denumire;
		afisare << " are o suprafata de: " << aer.suprafata;
		afisare << " m2 si are in componenta sa avionul "<<aer.avion;
		/*for (int i = 0; i < aer.nrAvioane; i++) {
			afisare << aer.avion[0]<< " --- ";
		}*/
		return afisare;
	}
	string getDenumire() {
		return this->denumire;
	}
	void setDenumire(string denumire) {
		this->denumire = denumire;
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}
	Avion getAvion() {
		return this->avion;
	}
	void setAvion(Avion avion) {
		this->avion = avion;
	}
	/*int getNrAvioane() {
		return this->nrAvioane;
	}
	void setNrAvioane(int nrAvioane) {
		Avion avion7;
		int aux = this->nrAvioane;
		this->nrAvioane = nrAvioane;
		if (this->nrAvioane != aux) {
			Avion* auxav = this->avion;
			delete[]this->avion;
			if (aux < this->nrAvioane);
			this->avion = new Avion[this->nrAvioane];
			for (int i = 0; i < aux; i++) {
				this->avion[i] = auxav[i];
			}
			for (int i = aux; i < this->nrAvioane; i++) {
				this->avion[i] = avion7;
			}
			if (aux > this->nrAvioane) {
				this->avion = new Avion[this->nrAvioane];
				for (int i = 0; i < this->nrAvioane; i++) {
					this->avion[i] = auxav[i];
				}
			}
		}
	}*/

	
};
float valoareAbsolutaM(const CompanieAeriana& com) {
	return (com.TVA * com.valoareNetaM / 100) + com.valoareNetaM;
}

string sirModele(const CompanieAeriana& com) {
	string aux = "";
	for (int i = 0; i < com.numarAeronave; i++) {
		aux = aux + " " + com.modelAeronava[i];
	}
	return aux;
}

float CompanieAeriana::TVA = 9;

void main() {
	int numarAvioane = 0;
	cout << "Numarul de avioane inregistrate in vector " << endl;
	cin >> numarAvioane;
	Avion* vector = new Avion[numarAvioane];
	for (int i = 0; i < numarAvioane; i++) {
		cin >> vector[i];
	}
	for (int i = 0; i < numarAvioane; i++) {
		cout << vector[i] << endl;
	}
	const int nrLinii = 2;
	const int nrColoane = 2;
	Avion avioane[nrLinii][nrColoane];
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			cout << "Avionul de pe pozitia " << i + 1 << " " << j + 1 << endl;
			cin >> avioane[i][j];
		}
	}
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane; j++) {
			cout << avioane[i][j] << " ";
		}
		cout << endl;
	}

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

	cout << endl;

	cout << avion1.getInitializareNrAvioane() << endl;
	avion1.setModel("Mecredes Air");
	cout << avion1.getModel() << endl;
	avion1.setNrTurbine(2);
	cout << avion1.getNrTurbine() << endl;
	avion1.setNumeTurbine(numeTurbine, 3);
	for (int i = 0; i < 3; i++) {
		cout << avion1.getNumeTurbine()[i] << endl;
	}
	cout << medieTurbinePeAvion(avion3) << endl;
	cout << getSirNumeTurbine(avion1) << endl;

	cout << endl;
	avion1 = avion2;
	avion1.afisareAvion();
	Avion avion5 = avion1 + avion2;
	avion5.afisareAvion();
	cout << (avion5 > avion1) << endl;
	cout << avion1 << endl;

	cout << endl;
	cout << endl;

	int numarAeroporturi = 0;
	cout << "Numarul de aeroporturi in vector:" << endl;
	cin >> numarAeroporturi;
	Aeroport* vectorAer = new Aeroport[numarAeroporturi];
	for (int i = 0; i < numarAeroporturi; i++) {
		cin >> vectorAer[i];
	}
	for (int i = 0; i < numarAeroporturi; i++) {
		cout << vectorAer[i] << endl;
	}

	Aeroport aeroport1;
	aeroport1.afisareAeroport();

	Aeroport aeroport2("Henri Coanda");
	aeroport2.afisareAeroport();

	float* pretProdus = new float[3];
	pretProdus[0] = 5.3;
	pretProdus[1] = 2.23;
	pretProdus[2] = 5.99;

	Aeroport aeroport3("King Fahd", 3, pretProdus);
	aeroport3.afisareAeroport();

	cout << endl;

	cout << aeroport1.getInitializareNumarInitial() << endl;
	aeroport1.setNumeAeroport("Cluj Airport");
	cout << aeroport1.getNumeAeroport() << endl;
	aeroport1.setNrProduse(3);
	cout << aeroport1.getNrProduse() << endl;
	aeroport1.setPretProduse(pretProdus, 3);
	for (int i = 0; i < 3; i++) {
		cout << aeroport1.getPretProduse()[i] << endl;
	}
	cout << pretMediu(aeroport1) << endl;
	afisarePreturi(aeroport1);

	cout << endl;
	aeroport3 = aeroport1;
	aeroport3.afisareAeroport();
	Aeroport aeroport4;
	aeroport4++;
	aeroport4.afisareAeroport();
	Aeroport aeroport5;
	cin >> aeroport5;
	aeroport5.afisareAeroport();
	Aeroport aeroport6("Andalusia", 3, pretProdus);
	Aeroport aeroport7("Wiz Airport", 3, pretProdus);
	aeroport6 += aeroport7;
	aeroport6.afisareAeroport();

	cout << endl;
	cout << endl;

	int numarCompanii = 0;
	cout << "Numarul de companii din vector este:" << endl;
	cin >> numarCompanii;
	CompanieAeriana* vectorCom = new CompanieAeriana[numarCompanii];
	for (int i = 0; i < numarCompanii; i++) {
		cin >> vectorCom[i];
	}
	for (int i = 0; i < numarCompanii; i++) {
		cout << vectorCom[i];
	}

	CompanieAeriana companie1;
	companie1.afisareCompanie();

	CompanieAeriana companie2(130);
	companie2.afisareCompanie();

	string* modelAeronava = new string[2];
	modelAeronava[0] = "Traveler Air 23";
	modelAeronava[1] = "Boeing 45";

	CompanieAeriana companie3("Turkish Airlines", 2, 980, true, modelAeronava);
	companie3.afisareCompanie();

	cout << endl;

	cout << companie1.getInitializareTVA() << endl;
	companie1.setNume("Qatar AIRWAYS");
	cout << companie1.getNume() << endl;
	companie1.setNumarAeronave(6);
	cout << companie1.getNumarAeronave() << endl;
	companie1.setValoareNetaM(100.5);
	cout << companie1.getValoareNetaM() << endl;
	companie1.setModelAeronava(modelAeronava, 2);
	for (int i = 0; i < 2; i++) {
		cout << companie1.getModelAeronava()[i] << endl;
	}
	cout << valoareAbsolutaM(companie1) << endl;
	cout << sirModele(companie2) << endl;

	cout << endl;
	cout << companie3[1] << endl;
	CompanieAeriana companie4;
	companie4 = companie3;
	companie4.afisareCompanie();
	companie4 = companie2 - companie3;
	companie4.afisareCompanie();
	cout << companie3;

cout << endl;
cout << endl;

Aerodrom aerodrom1;
Aerodrom aerodrom2;
Avion avion10;
cin >> aerodrom1;
cout << aerodrom1<<endl;
aerodrom1.setDenumire("Buckingham");
cout << aerodrom1.getDenumire() << endl;
aerodrom1.setSuprafata(1250);
cout << aerodrom1.getSuprafata()<<endl;
aerodrom1.setAvion(avion10);
cout << aerodrom1.getAvion()<<endl;
cout << (aerodrom1 + aerodrom2);
//aerodrom1.setNrAvioane(4);
//cout << aerodrom1;

cout << endl;
cout << endl;

Avion avion17("Boeing_727");
Avion avion18;
ofstream afi("avioane.txt", ios::out);
afi << avion17;
afi.close();
ifstream cit("avioane.txt", ios::in);
cit >> avion18;
cit.close();
cout << avion18<<endl;
avion18.afisareFisBin();
Avion avion19;
cout<<avion19.getNrTurbine()<<endl;
avion19.citireFisBin();
//Avion avion19("Aircraft_777");
//Avion avion20("AIRTIME");
////fstream f("avi.dat", ios::binary | ios::out);
////f.write((char*)&avion19, sizeof(Avion));
////f.close();
//fstream g("avi.dat", ios::binary | ios::in);
//g.read((char*)&avion20, sizeof(Avion));
//g.close();
//cout << avion20;

Aeroport aeroport10("Bergamo");
Aeroport aeroport8("Feyenord");
ofstream af("aeroport.txt", ios::out);
af << aeroport10;
af.close();
ifstream ci("aeroport.txt", ios::in);
ci >> aeroport8;
ci.close();
cout << aeroport8<<endl;
aeroport8.afiFisBin();
Aeroport aeroport9;
cout << aeroport9.getNrProduse() << endl;
aeroport9.citireFisBin();

}