#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <dirent.h>

using namespace std;

/* What does this function return?
 * Does it return anything we don't want?
 * How can we make that better?
 */
list<string> get_file_names(string directory){
	DIR *p_direct;
	struct dirent *p_entry;
	list<string> fileNames;
	
	if ((p_direct = opendir (directory.c_str())) != nullptr){
		while ((p_entry = readdir (p_direct)) != nullptr){
			fileNames.push_back(p_entry->d_name);
		}
		closedir(p_direct);
	}
	else
		cerr<<"Could not open directory";
	
	//_______________________
	
	return fileNames;
}

struct Student {
	string name;
	string major;
	int age;
	float gpa;
};

//Create a function to read a file into a Student.
//vvvvvvvvvvvvvvvvvvvv



//^^^^^^^^^^^^^^^^^^^^

int main()
{
	list<string> fileNames = get_file_names("Students");
	//Print the names of the files found in the directory here.
	//vvvvvvvvvvvvvvvvvvvv
	while (!fileNames.empty()) {
	cout << fileNames.front() << endl;
	fileNames.pop_front();
	
	
	//^^^^^^^^^^^^^^^^^^^^
	
	vector<Student> roster;
	
	//Read all of the student data files into the vector of Students.
	//vvvvvvvvvvvvvvvvvvvv
	
	
	
	//^^^^^^^^^^^^^^^^^^^^
	
	return 0;
}
