#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <stdio.h>
#include "lib/Directory.h"
using namespace std;

Directory::Directory(string dir)
{
  de = NULL;
  d = NULL;
  direct = dir;
  size = getListSize();
  list = new string[size];
}

bool Directory::getList(string *arg)
{
  if(size == -1)
  {
    list[0]="Couldn't open directory";
    arg=list;
    return(false);
  }

  arg=list;
  return(true);

}

int Directory::getListSize()
{
  d=opendir(direct.c_str());
  if(d == NULL)
    return -1;

  // Loop while not NULL
  int i = 0;
  while(de = readdir(d))
  {
    list[i++]=de->d_name;
  }
  closedir(d);
  return(i);
}
