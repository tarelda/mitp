#include <string>
#include <vector>
#include <iostream> 
using namespace std;
int main() { 
	vector <string> v(7);
	for( int i=0; i<3; i++ ) 
		cin >> v[i];
	cout << "Rozmiar:" << v.size() << endl; 
	v.push_back("Dupa"); 
	cout << "Rozmiar:" << v.size() << endl << endl;
	vector<string>::iterator i;
	for( i=v.begin(); i!=v.end(); i++ )
		cout << *i << endl;
		
	v.swap(v.begin());
	return 0;
}