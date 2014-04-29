#include "lib/All.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 4

struct ImageData{
	string path;
	int goodmatches;
};

vector<ImageData> images;
Direct dir;
char *path;

void *computeMatches(void *threadid){
	ImageData temp;
	long id = (long) threadid;
	int min,max,size,diff;
	size = dir.getSize(); 	
	min = id * NUM_THREADS;
	max = min + size/NUM_THREADS - 1;
	cout<<"Thread: "<<id<<endl;
	if(size % NUM_THREADS != 0 && id == (NUM_THREADS-1))
		max = size-1;
	FeatureMatcher matcher(path, dir.list[min].c_str());
	for (int i = min + 1; i < max; i++) 
	{
		//cout << "Comparing " << argv[1] << " and " << dir.list[i] << " #" << i + 1 << endl;
		matcher.setCompareImage(dir.list[i].c_str());

		temp.path = dir.list[i];
		temp.goodmatches = matcher.drawFeatures(false);  //set to false to not draw
		images.push_back(temp);
	}

	pthread_exit(NULL);
}

int main(int argc, char **argv) {

	int TOP_NUM = 4;	//limit the # of top results
	path = argv[1];
	if (argc < 2) { //if not enough arguments
		cout << "Project <img> (optional:directory)" << endl;
		return 1;
	}

	if (dir.getSize() == 0)
		cout << "Directory not found or empty" << endl;
	else 
	{	
		cout << "Computing matches."<<endl;
		
		pthread_t threads[NUM_THREADS];
   		int rc;
   		for(int i=0; i < NUM_THREADS; i++ ){
  	  		cout << "main() : creating thread, " << i << endl;
    		rc = pthread_create(&threads[i], NULL,computeMatches, (void *)i);
      		if (rc){
        		cout << "Error:unable to create thread," << rc << endl;
     		exit(-1);
    		}
   		}

   		pthread_exit(NULL);

		// cout << "\n\n Top Matches" <<endl;
		// for(int i = 0;i<topImages.size();i++)
		// {
		// 	cout<<"Number of Matches: "<< topImages[i].goodmatches<<endl;
		// 	cout<<"File Name: " << topImages[i].path<<endl<<endl;

		// 	FeatureMatcher matcher(argv[1], topImages[i].path.c_str());
		// 	matcher.drawFeatures(true);
		// 	waitKey(0);
		// }
	}
	waitKey(0);
	return 0;
}
