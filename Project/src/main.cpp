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
	FeatureMatcher *matcher = new FeatureMatcher(argv[1], argv[2]);
	if(argc >= 4)
		matcher -> setDownsize(atoi(argv[3]));
	matcher -> drawFeatures(false,false);	//set to false to not draw, and false to not print out each keypoint
	cout<< matcher->getMatchSize()<<endl;
	waitKey(0);
	return 0;
}
