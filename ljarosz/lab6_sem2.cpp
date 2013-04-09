#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;


class Child {
	public:
		Child(Parent* parent1, Parent* parent2){
			this->parent1 = parent1;
			this->parent2 = parent2;
		};
		void introduce( void );
	
	private:
		int being_badass;
		Parent* parent1;
		Parent* parent2;
};

void Child::introduce( void ){
	cout << "I'm " << this->parent1->getFName() << " and " << this->parent2->getFName() << " child!" << endl;
	if(this->being_badass){
		cout << " And Imma badass" << endl;
	}
	if(this->parent1->being_badass && this->parent1->being_badass){
		cout << " And my parents are badass ;) " << endl;
	}
}

class Parent { 
	public:
		Parent( char* fname ){ 
			this->being_badass = 1;
			this->fname = fname;
		};		
		void introduce( void );
		char* getFName( void );
		int being_badass;
		Child* operator+(Parent* second);
		
		
	private:
		char* fname;
};

char* Parent::getFName( void ){
	return this->fname;
}

void Parent::introduce( void ){
	cout << "I'm parent :) And my name is " << this->fname << endl;
}



Child* Parent::operator+ (Parent* second){
	return new Child(this, second);
}


int main( void ){
	Parent* p1 = new Parent( (char*) "Rebecca");
	Parent* p2 = new Parent( (char*) "Michael");
	
	p1->introduce();
	p2->introduce();

	Child* c = p1 + p2; 
	
	c->introduce();
	return 0;
}