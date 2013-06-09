#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm>
#include <cstdlib>
#include <cstring>

class FileSort{
	private:
		std::vector<std::string> v;
		std::fstream file;
	protected:
		void openStream(std::string filename);
		void closeStream();
		void fillVector();

	public:
		FileSort(std::string filename);
		void sort();
		void qsort();

		friend std::ostream& operator<< (std::ostream& out, FileSort* fs);
};

void FileSort::fillVector(){
	std::string tmp;
	getline(file, tmp);
	do { 
		v.push_back(tmp);
		getline(file, tmp);
	} while ( tmp.length() != 0 );
}

void FileSort::openStream(std::string filename){
	file.open(filename.c_str());
	if(!file.is_open())
		exit(0);
}

void FileSort::closeStream(){
	file.close();
}

FileSort::FileSort(std::string filename){
	openStream(filename);
	fillVector();
}

int stringCompare(const void* v1, const void* v2){
	const std::string* s1 = reinterpret_cast<const std::string*>(v1);
	const std::string* s2 = reinterpret_cast<const std::string*>(v2);
	return strcmp(s1->c_str(), s2->c_str());
}

void FileSort::qsort(){
	std::qsort(reinterpret_cast<void*>(&(v.front())), v.size(), sizeof(std::string*), stringCompare);
}

void FileSort::sort(){
	std::sort(v.begin(), v.end());
}

std::ostream& operator<< (std::ostream& out,  FileSort* fs){
	std::vector<std::string>::iterator el = (fs->v).begin();
	out << "[ " ;
	for (; el != (fs->v).end(); el++){
		out << "\"" << *el << "\"" << ((el+1 != (fs->v).end()) ? ", ":" ");
	}
	out << "]";
	return out;
}

int main(){
	std::string in;

	std::cout << "Please, type the filename: " << std:: endl;
	std::cin >> in;

	FileSort fs(in);
	std::cout << "Before sorting: " << (&fs) << std::endl;
	std::cout << "Please choose sorting method (qs - c qsort, s - c++ sort)" << std::endl;
	std::cin >> in;
	if(in == "qs")
		fs.qsort();
	else if(in == "s")
		fs.sort();
	std::cout << "After sorting: " << (&fs) << std::endl;
	return 0;
}