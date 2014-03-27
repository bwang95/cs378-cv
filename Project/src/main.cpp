#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
	
	FeatureMatcher *matcher;
	char* maxImg;
	int max = 0;

	if(argc < 3){	//not enough arguments
		cout << "Project <img> <directory> (optional: downsize)" << endl;
		return 1;
	}
	
	//Directory *dir = new Directory("");
        //getSize retrieves the number of objects in the directory
        //makeList() creates the list pointer array and returns true if successful
	Directory *dir = new Directory(argv[2]);
	if(!dir->makeList())
		cout<<"Directory not found"<<endl;
	else
	{
	for(int i = 0; i < dir->getSize()-2;i++)
	{	
		dir->list[i]= argv[2] + dir->list[i];	//appends file dir list to img name
		char *file = (char *)alloca(dir->list[i].size() + 1);	//converts to char*
		memcpy(file, dir->list[i].c_str(), dir->list[i].size() + 1);

		cout<<"Comparing "<<argv[1]<<" and "<<file<<" #"<<i+1<<endl; 
		if(strcmp(argv[1],file) == 0){
		cout<<"Same file"<<endl;
		}	
		else{

		matcher = new FeatureMatcher(argv[1], file);
		if(argc >= 4)
			matcher -> setDownsize(atoi(argv[3]));
		
		matcher -> drawFeatures(false,false);	//set to false to not draw, 
							//and false to not print out each keypoint
		if(max<matcher->getMatchSize())
		{
			max = matcher->getMatchSize();
			maxImg = file;
		}
		cout<< matcher->getMatchSize()<<" matches"<<endl;
		}
	
	}

	cout<<"\n\nMost Matches: "<<max<<endl;
	cout<<"File name: "<<maxImg<<endl;
	matcher = new FeatureMatcher(argv[1],maxImg);
	matcher->drawFeatures(true,false);
	}
	waitKey(0);
	return 0;
}
