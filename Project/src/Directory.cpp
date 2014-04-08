#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include "lib/Directory.h"
#include <iostream>
using namespace std;

Directory::Directory(string dir) {
	DIR *d = opendir(dir.c_str());
	int i = 0;
	struct dirent *de = NULL;
	while (de = readdir(d)) {
		string name = de->d_name;
		if (name != "." && name != "..")
			list.push_back(de -> d_name);
	}
	closedir(d);
}

int Directory::getSize() {
	return list.size();
}
