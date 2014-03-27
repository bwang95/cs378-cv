#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){

	//Directory *dir = new Directory("");
	//getSize retrieves the number of objects in the directory
	//makeList() creates the list pointer array and returns true if successful

	if(argc < 3){
		cout << "Project <img> <directory> (optional: downsize)" << endl;
		return 1;
	}
	
	Directory *dir = new Directory(argv[2]);
	if(!dir->makeList())
		cout<<"Directory not found"<<endl;
	else
	{
	for(int i = 0; i < dir->getSize()-2;i++)
	{	
		dir->list[i]= argv[2] + dir->list[i];
		char *file = (char *)alloca(dir->list[i].size() + 1);
		memcpy(file, dir->list[i].c_str(), dir->list[i].size() + 1);

		cout<<file<<" and "<<argv[1]<<endl;
		
		FeatureMatcher *matcher = new FeatureMatcher(argv[1], file);
		if(argc >= 4)
			matcher -> setDownsize(atoi(argv[3]));
		matcher -> drawFeatures(false,false);	//set to false to not draw, and false to not print out each keypoint
		cout<< matcher->getMatchSize()<<endl;
		
	
	}
	cout<<dir->getSize();
	}
	waitKey(0);
	return 0;
}
