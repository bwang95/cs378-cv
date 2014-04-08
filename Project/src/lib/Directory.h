#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
class Directory {
public:
	vector<string> list;
	Directory(string);
	int getSize();
};

#endif
