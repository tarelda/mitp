#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class Parent { 
	public:
		Parent( char* fname ){ 
			this->being_badass = 1;
			this->fname = fname;
		}
		void introduce( void );
		char* getFName( void );
		bool isBadass( void ) { return this->being_badass;} 
		Parent operator+(Parent second) {
			cout << "Child making" << endl;
		};
	
	private:
		char* fname;
		bool being_badass;
};

char* Parent::getFName( void ){
	return this->fname;
}

void Parent::introduce( void ){
	cout << "I'm parent :) And my name is " << this->fname << endl;
}


class Child {
	public:
		Child(Parent* p1, Parent* p2){
			this->parent1 = p1;
			this->parent2 = p2;
		};
		void introduce( void );
	
	private:
		Parent* parent1;
		Parent* parent2;
};

void Child::introduce( void ){
	cout << "I'm " << this->parent1->getFName() << " and " << this->parent2->getFName() << " child!" << endl;
	if(this->parent1->isBadass() && this->parent1->isBadass()){
		cout << " And my parents are badass ;) " << endl;
	}
}

int main( void ){
	Parent* p1 = new Parent( (char*) "Rebecca");
	Parent* p2 = new Parent( (char*) "Michael");
	
	p1->introduce();
	p2->introduce();
	
	(*p1)+(*p2);
	
	Child c = Child(p1,p2); 
	c.introduce();
	return 0;
}