#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include "lib/Directory.h"
#include <iostream>
using namespace std;

Directory::Directory(string dir)
{
  de = NULL;
  d = NULL;
  direct = dir.c_str();
  size = getListSize();
  list = new string[size];
}

bool Directory::makeList()
{
  d = NULL;
  de = NULL;  
  if(size == 0)
    return(false);

  d = opendir(direct);
  int i = 0;
  while(de = readdir(d))
	list[i++] = de->d_name;

  return(true);

}

int Directory::getListSize()
{
  d=opendir(direct);
  if(d == NULL)
    return 0;

  // Loop while not NULL
  int i = 0;
  while(de = readdir(d))
 	i++;
 
  closedir(d);
  return(i);
}
