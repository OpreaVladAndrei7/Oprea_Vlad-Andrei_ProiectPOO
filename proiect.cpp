#include < iostream>
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

	Avion(const Avion& a) : nrAvioane(nrInitialAvioane++) {
		this->model = a.model;
		this->nrTurbine = a.nrTurbine;
		this->numeTurbine = new string[nrTurbine];
		for (int i = 0; i < nrTurbine; i++) {
			this->numeTurbine[i] = a.numeTurbine[i];
		}
	};
	~Avion(){
		if (nrTurbine > 0) {
			delete[]this->numeTurbine;
			}
	}

	void afisareAvion() {
		cout<<"Avionul: "<<nrAvioane<<" "<< model << " are un numar de " << nrTurbine << " turbine cu denumirile: ";
		for (int i = 0; i < nrTurbine; i++)
		{cout << numeTurbine[i] << " "; 
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
	void setNumeTurbine( string *numeTurbine,int nrTurbine){
		if (this->nrTurbine >0) {
			delete[]this->numeTurbine;
			this->numeTurbine = new string[nrTurbine];
			for (int i = 0; i < nrTurbine; i++) {
				this->numeTurbine[i] = numeTurbine[i];
			}
		}
	}
	Avion operator=(const Avion& av){
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
		return* this;
	}
	Avion operator+(const Avion& av) {
		Avion aux;
		aux.nrTurbine = this->nrTurbine + av.nrTurbine;
		aux.numeTurbine = new string[aux.nrTurbine];
		for (int i = 0; i < this->nrTurbine; i++) {
			aux.numeTurbine[i] = this->numeTurbine[i];
		}
		for (int i = this->nrTurbine; i < aux.nrTurbine; i++) {
			aux.numeTurbine[i] = av.numeTurbine[i- this->nrTurbine];
		}
		return aux;
	}
	bool operator>(const Avion& av) {
		return (this->nrTurbine > av.nrTurbine);
	}
	friend ostream& operator<<(ostream& avion, const Avion& a) {
		avion << a.model<<" ";
		avion << a.nrAvioane<<" ";
		avion << a.nrInitialAvioane<<" ";
		avion << a.nrTurbine<<" ";
		for (int i = 0; i < a.nrTurbine; i++) {
			avion << a.numeTurbine[i]<<" ";
		}
		return avion;
	}
	friend float medieTurbinePeAvion(const Avion &avi);
	friend string getSirNumeTurbine(const Avion& avi);
};

float medieTurbinePeAvion(const Avion& avi) {
	return avi.nrTurbine / avi.nrAvioane;
}

string getSirNumeTurbine(const Avion& avi) {
	string aux = "";
	for (int i = 0; i < avi.nrTurbine; i++) {
		aux = aux +" "+avi.numeTurbine[i];
		
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
	Aeroport(const Aeroport& ae): numarAeroporturi(numarInitial++) {
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
		cout << "Aeroportul: "<<numarAeroporturi <<" "<< numeAeroport << " are in cadrul acestuia un numar de: " << nrProduse << " produse fiecare cu pretul de: ";
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
	int getNrAeroport() const{
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
		float *vector = new float[this->nrProduse];
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
			cout <<"Produsul " << i + 1<<" are pretul de:";
			cit >> aer.pretProdus[i];
		}
		return cit;
	}
	friend float pretMediu(const Aeroport& aer);
	friend void afisarePreturi(const Aeroport& aer);
};

float pretMediu(const Aeroport& aer) {
	float total=0;
	for (int i = 0; i < aer.nrProduse; i++) {
		total = total + aer.pretProdus[i];
	}
	return total/aer.nrProduse;
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
	CompanieAeriana(const CompanieAeriana& c):codCompanie(c.codCompanie) {
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
		cout << "Compania " <<codCompanie<<" "<< nume << " are o valoare neta de " << valoareNetaM << "si un numare de: " << numarAeronave << " aeronave ";
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
	CompanieAeriana operator-(const CompanieAeriana & com) {
			CompanieAeriana aux;
			aux.valoareNetaM = this->valoareNetaM - com.valoareNetaM;
			aux.numarAeronave = this->numarAeronave - com.numarAeronave;
			return aux;
	}
	friend ostream& operator<<(ostream& companie, const CompanieAeriana& com) {
		companie <<"Compania aeriana: " <<com.nume<<" ";
		companie << "cu valoarea neta de " << com.valoareNetaM << " milioane de euro ";
		companie << "si codul companiei: "<<com.codCompanie;
		companie << " prezinta un TVA de " << com.TVA<<"."<<endl;
		companie << "Compania are:" << com.numarAeronave << " aeronave, modelele: ";
		for (int i = 0; i < com.numarAeronave; i++) {
			companie << com.modelAeronava[i] << " ";
		}
		cout << endl;
		return companie;
	}
	friend float valoareAbsolutaM(const CompanieAeriana& com);
	friend string sirModele(const CompanieAeriana& com);
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

	cout<<avion1.getInitializareNrAvioane()<<endl;
	avion1.setModel("Mecredes Air");
	cout<<avion1.getModel()<<endl;
	avion1.setNrTurbine(2);
	cout<<avion1.getNrTurbine()<<endl;
	avion1.setNumeTurbine(numeTurbine, 3);
	for (int i = 0; i < 3; i++) {
		cout << avion1.getNumeTurbine()[i] << endl;
	}
	cout << medieTurbinePeAvion(avion3)<<endl;
	cout << getSirNumeTurbine(avion1) << endl;

	cout << endl;
	avion1 = avion2;
	avion1.afisareAvion();
	Avion avion5 = avion1 + avion2;
	avion5.afisareAvion();
	cout <<(avion5 > avion1)<<endl;
	cout << avion1<<endl;
	
	cout << endl;
	cout << endl;

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

	cout << aeroport1.getInitializareNumarInitial()<<endl;
	aeroport1.setNumeAeroport("Cluj Airport");
	cout<<aeroport1.getNumeAeroport()<< endl;
	aeroport1.setNrProduse(3);
	cout << aeroport1.getNrProduse() << endl;
	aeroport1.setPretProduse(pretProdus, 3);
	for (int i = 0; i < 3; i++) {
		cout << aeroport1.getPretProduse()[i] << endl;
	}
	cout<<pretMediu(aeroport1)<<endl;
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
	cout<<companie1.getNume() << endl;
	companie1.setNumarAeronave(6);
	cout << companie1.getNumarAeronave() << endl;
	companie1.setValoareNetaM(100.5);
	cout << companie1.getValoareNetaM()<<endl;
	companie1.setModelAeronava(modelAeronava, 2);
	for (int i = 0; i < 2; i++) {
		cout << companie1.getModelAeronava()[i] << endl;
	}
	cout << valoareAbsolutaM(companie1)<<endl;
	cout << sirModele(companie2) << endl;

	cout << endl;
	cout<<companie3[1]<<endl;
	CompanieAeriana companie4;
	companie4 = companie3;
	companie4.afisareCompanie();
	companie4 = companie2 - companie3;
	companie4.afisareCompanie();
	cout << companie3;

}