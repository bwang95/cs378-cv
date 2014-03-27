#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>

using namespace std;
class Directory 
{
    struct dirent *de;
    DIR *d;
    int getListSize();
public:
    string *list;
    int size;
    const char *direct;
    Directory(string);
    bool getList();
    int getSize() {return size;}
};

#endif
