#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include "lib/Directory.h"
#include <iostream>
#include <fstream>
using namespace std;

Directory::Directory(string dir) {
	DIR *d = opendir(dir.c_str());
	int i = 0;
	struct dirent *de = NULL;
	while (de = readdir(d)) {
		string name = de->d_name;
		if (name != "." && name != "..")
			list.push_back(dir+name);
	}
	closedir(d);
}

Directory::Directory(){
	ifstream infile;
	infile.open("FileIndex.txt", ifstream::in);

	string temp;
	while(infile){
		infile >> temp;
		list.push_back(temp);
		cout<<temp<<endl;
	}
}

int Directory::getSize() {
	return list.size();
}
