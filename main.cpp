#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <dirent.h>
#include <stdlib.h>

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
			if (p_entry->d_name[0] != '.') fileNames.push_back(p_entry->d_name);
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
	Student() {}
	//Student(string n, string m, int a, float g) : name(n), major(m), age(a), gpa(g) {}
};

//Create a function to read a file into a Student.
//vvvvvvvvvvvvvvvvvvvv

Student read_data(string fileName) {
	fstream inFile(fileName, ios::in);
	Student s;
	string line;
	int index;
	getline(inFile, line);
	s.name = line.substr(line.find(": ") + 2, line.size() - (line.find(": ") + 2));
	getline(inFile, line);
        s.major = line.substr(line.find(": ") + 2, line.size() - (line.find(": ") + 2));
	getline(inFile, line);
        s.age = atoi(line.substr(line.find(": ") + 2, line.size() - (line.find(": ") + 2)).c_str());
	getline(inFile, line);
        s.gpa = atof(line.substr(line.find(": ") + 2, line.size() - (line.find(": ") + 2)).c_str());
	inFile.close();
	return s;
	//return Student("hello", "hello", 45, 56.7);
}


//^^^^^^^^^^^^^^^^^^^^

int main()
{
	list<string> fileNames = get_file_names("Students");
	//Print the names of the files found in the directory here.
	//vvvvvvvvvvvvvvvvvvvv

	list<string>::iterator i;

	for (i = fileNames.begin(); i != fileNames.end(); i++) cout << *i << endl;

	//^^^^^^^^^^^^^^^^^^^^

	vector<Student> roster;

	//Read all of the student data files into the vector of Students.
	//vvvvvvvvvvvvvvvvvvvv

	for (i = fileNames.begin(); i != fileNames.end(); i++) roster.push_back(read_data((string("Students/") + *i)));

	//^^^^^^^^^^^^^^^^^^^^

	return 0;
}
