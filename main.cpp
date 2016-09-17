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
list<string> get_file_names(string directory)
{
	DIR *p_direct;
	struct dirent *p_entry;
	list<string> fileNames;
	
	if ((p_direct = opendir (directory.c_str())) != nullptr)
	{
		while ((p_entry = readdir (p_direct)) != nullptr)
		{
			fileNames.push_back(p_entry->d_name);
		}
		closedir(p_direct);
	}
	else
		cerr<<"Could not open directory";
	
	fileNames.remove(".");
	fileNames.remove("..");
	
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
Student read_data(string fileName)
{
	fstream inFile(fileName, ios::in);

	Student s;
	string trash;
	inFile>>trash;
	inFile>>s.name;
	inFile>>trash;
	inFile>>s.major;
	inFile>>trash;
	inFile>>s.age;
	inFile>>trash;
	inFile>>s.gpa;

	inFile.close();
	
	return s;
}


//^^^^^^^^^^^^^^^^^^^^

int main()
{
	list<string> fileNames = get_file_names("Students");
	//Print the names of the files found in the directory here.
	//vvvvvvvvvvvvvvvvvvvv
	list<string> fileNames2=fileNames;
	while(!fileNames.empty())
	{
		cout<<fileNames.front()<<endl;
		fileNames.pop_front();
	}

	
	
	//^^^^^^^^^^^^^^^^^^^^
	
	vector<Student> roster;
	
	//Read all of the student data files into the vector of Students.
	//vvvvvvvvvvvvvvvvvvvv
	for(int i=0;i<fileNames2.size();i++)	
	{
		roster.push_back(read_data(fileNames2.front()));
		fileNames2.pop_front();
	}
	
	
	//^^^^^^^^^^^^^^^^^^^^
	/*	while(!fileNames2.empty())
	{
		cout<<fileNames2.front()<<endl;
		fileNames2.pop_front();
	}
	*/
	
	return 0;
}
