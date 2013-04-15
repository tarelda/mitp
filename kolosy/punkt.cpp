#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Punkt{
	protected:
		float x;
		float y;
	public:
		Punkt( void ){ 
			this->x = 0;
			this->y = 0;
		};
		Punkt(float x, float y);
		
		void ustaw(float x, float y);
		void wypisz( void );
		
		float getX( void );
		float getY( void );
		
		friend ostream& operator<< (ostream& outputStream, Punkt& p){
			outputStream << "(" << p.getX() << "," << p.getY() << ")";
			return outputStream;  
		};
};


Punkt::Punkt(float x, float y){
	this->x = x;
	this->y = y;
}

void Punkt::ustaw(float x, float y){
	this->x = x;
	this->y = y;
}

void Punkt::wypisz( void ){
	cout << "(" << this->getX() << "," << this->getY() << ")";
}

float Punkt::getX( void ){
	return this->x;
}

float Punkt::getY( void ){
	return this->y;
}

class Pieciokat{
	protected:
		Punkt* p1;
		Punkt* p2;
		Punkt* p3;
		Punkt* p4;
		Punkt* p5;
		
	public:
		void wypisz( void );
		void ustaw(Punkt* p1, Punkt* p2, Punkt* p3, Punkt* p4, Punkt* p5){
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
			this->p4 = p4;
			this->p5 = p5;
		};
		
		
		float obwod( void ){
			float xd = this->p1->getX() - this->p2->getX();
			float xy = this->p1->getY() - this->p2->getY();
			return ((float) 5.0)*sqrt(pow(xd, (float) 2.0) + pow(xy, (float) 2.0));
		};
		
		friend ostream& operator<< (ostream& outputStream, Pieciokat& p){
			outputStream << "Jestem pieciokatem i skladam sie z nastepujacych punktow:" << endl;
			outputStream << p.p1 << p.p2 << p.p3 << p.p4 << p.p5;
			return outputStream;  
		};
};

void Pieciokat::wypisz ( void ){
	cin << "Jestem pieciokatem i skladam sie z nastepujacych punktow:" << endl;
	this->p1->wypisz();
	this->p2->wypisz();
	this->p3->wypisz();
	this->p4->wypisz();
	this->p5->wypisz();
}

class KolorowyPieciokat : public Pieciokat{
	protected:
		char* kolor;
	public:
		void wypisz( void );
		void ustaw(char* kolor, Punkt* p1, Punkt* p2, Punkt* p3, Punkt* p4, Punkt* p5){
			this->kolor = kolor;
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
			this->p4 = p4;
			this->p5 = p5;
		};

		friend ostream& operator<< (ostream& outputStream, KolorowyPieciokat& p){
				outputStream << "Jestem pieciokatem o kolorze " << p.kolor << " i skladam sie z nastepujacych punktow:" << endl;
				outputStream << p.p1 << p.p2 << p.p3 << p.p4 << p.p5;
				return outputStream;  
		};
};

void KolorowyPieciokat::wypisz( void ){
	cout << "Jestem pieciokatem o kolorze " << this->kolor << " i skladam sie z nastepujacych punktow:" << endl;
	cout << this->p1 << this->p2 << this->p3 << this->p4 << this->p5;
}


int main(){
	Punkt* p1 = new Punkt(1.0, 2.0);
	p1->wypisz();
	cout << p1 << endl;

	return 0;
}
