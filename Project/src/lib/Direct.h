#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
class Direct {
public:
	vector<string> list;
	Direct(string);
	Direct();
	int getSize();
};

#endif
