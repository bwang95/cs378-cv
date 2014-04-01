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
    int size;
public:
    string *list;
    const char *direct;
    Directory(string);
    ~Directory();
    bool makeList();
    int getSize() {return size;}
};

#endif
