#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	Directory *dir = new Directory("ImgDB");
	int size = dir->getSize();
	cout << "Number of files in directory: " << size << endl;
	//getSize retrieves the number of objects in the directory
	//makeList() creates the list pointer array and returns true if successful
	if (dir->makeList()) {
		for (int i = 0; i < size; i++)
			cout << dir->list[i] << " ";
	} else
		cout << "Could not open directory." << endl;
	cout << endl;

	if (argc < 3) {
		cout << "Project <img1> <img2> (optional: downsize)" << endl;
		return 1;
	}
	FeatureMatcher *matcher = new FeatureMatcher(argv[1], argv[2]);
	if (argc >= 4)
		matcher -> setDownsize(atoi(argv[3]));
	matcher -> drawFeatures();

	waitKey(0);
	return 0;
}
