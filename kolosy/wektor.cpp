#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Wektor {
	protected:
		int* crds;
		int dim;
	public:
		Wektor(int dim){
			this->dim = dim;
			this->crds = (int*) malloc(sizeof(int) * this->dim);
		};
		Wektor(){};
		~Wektor(){
			free(this->crds);
		};
		
		void wypisz (void);
		
		void ustaw(int n, int v){
			this->crds[n] = v;
		};
		
		void wypelnij_losowymi( void ){
			srand (time(NULL));
			for (int i=0; i < this->dim; i++){
				this->crds[i] = (rand() % 20) - 10;
			}
		};
		
		friend int iloczyn_skalarny(Wektor a, Wektor b);
};

void Wektor::wypisz( void ){
	int i;
	cout << "Wektor (";
	for (i=0; i < this->dim-1; i++){
		cout << this->crds[i] << ",";
	}
	cout << this->crds[i+1] << ")" << endl;
}

int iloczyn_skalarny(Wektor a, Wektor b){
	int i, sum = 0;
	for (i=0; i < a.dim; i++){
		sum += a.crds[i]*b.crds[i];
	}
	return sum;
}

class NowyWektor : public Wektor{
	protected: 
		char* name;
	public:
		NowyWektor(char* name, int dim){
			this->name = name;
			this->dim = dim;
			this->crds = (int*) malloc(sizeof(int) * this->dim);
		};
		~NowyWektor(){
			free(this->crds);
		};
		
		void zmien_nazwe( char* name ){
			this->name = name;
		};
		void zmien_wymiar( int dim ){
			this->dim = dim;
			this->crds = (int*) realloc((void* )this->crds, sizeof(int)*dim);
		};
		
		void wypisz( void );
};

void NowyWektor::wypisz( void ){
	int i;
	cout << "Wektor " << this->name << " (";
	for (i=0; i < this->dim-1; i++){
		cout << this->crds[i] << ",";
	}
	cout << this->crds[i+1] << ")" << endl;
}


int main(){
	Wektor* v = new Wektor(8);
	v->wypelnij_losowymi();
	v->wypisz();
	
	NowyWektor* nv = new NowyWektor((char*)"Speed", 3);
	nv->wypelnij_losowymi();
	nv->wypisz();
	
	nv->zmien_nazwe((char*)"Pytonga");
	nv->wypisz();
	return 0;
}


