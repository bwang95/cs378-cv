#include "lib/All.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	if(argc < 3){
		cout << "Project <img1> <img2> (optional: downsize)" << endl;
		return 1;
	}
	FeatureMatcher *matcher = new FeatureMatcher(argv[1], argv[2]);
	if(argc >= 4)
		matcher -> setDownsize(atoi(argv[3]));
	matcher -> drawFeatures();

	waitKey(0);
	return 0;
}