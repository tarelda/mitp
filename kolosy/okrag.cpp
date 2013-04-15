#include <iostream>

using namespace std;

class Okrag{
	protected:
		int r;
	public:
		Okrag(){
			this->ustaw(0);
		};
		Okrag(int r){
			this->ustaw(r);
		};
		
		int getR() const{
			return r;
		};
		
		void wypisz();
		void ustaw(int r){
			this->r = r;
		};
};

ostream& operator<< (ostream& o, const Okrag& ok){
	o << "Okrag o promieniu: " << ok.getR();
	return o;
}

void Okrag::wypisz(){
	cout << "Okrag o promieniu: " << this->r << endl; 
}

class Walec : public Okrag{
	protected:
		int h;
	public:
		Walec(){
			this->ustaw(0, 0);
		};
		Walec(int r, int h){
			this->ustaw(r, h);
		};
		
		void ustaw(int r, int h){
			this->r = r;
			this->h = h;
		};
		void wypisz();
};

void Walec::wypisz(){
	cout << "Walec o promieniu podstawy: " << this->r  << " i wysokosci: " << this->h << endl;
}

int main(){
	Okrag* o = new Okrag(12);
	o->wypisz();
	cout << o << endl;
	return 0;
}