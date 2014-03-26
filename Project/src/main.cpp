#include "lib/All.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
//	Directory *dir = new Directory("../");
//        cout<<"Number of files in directory: "<<dir->getSize()<<endl;
/*	string *list = new string[dir->getSize()];
	dir->>getList(list);	
	for(int i = 0; i<dir->getSize();i++)
		cout<<list[i]<<" ";
	cout<<endl;
*/
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
