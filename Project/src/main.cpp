#include "lib/All.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>

using namespace std;

#define NUM_THREADS 4

struct ImageData{
	string path;
	int goodmatches;
};

bool compFunction (ImageData i,ImageData j) {return (i.goodmatches<j.goodmatches);}

vector<ImageData> images;
Direct dir;
char *path;

void *computeMatches(void *threadid){
	ImageData temp;
	long id = (long) threadid;
	int min,max,size,diff;
	size = dir.getSize(); 	
	min = id * size/NUM_THREADS - 1;
	max = min + size/NUM_THREADS - 1;
	cout<<"Thread: "<<id<<endl;
	if(id == (NUM_THREADS-1))
		max = size-1;
	cout<<"max: "<<max<<"\t min: "<<min<<endl;
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
   		pthread_t rc;
   		for(int i=0; i < NUM_THREADS; i++ ){
  	  		cout << "main() : creating thread, " << i << endl;
    		rc = pthread_create(&threads[i], NULL,computeMatches, (void *)i);
      		if (rc){
        		cout << "Error:unable to create thread," << rc << endl;
     		exit(-1);
    		}
   		}

   	for(int i = 0;i<NUM_THREADS;i++)
   		pthread_join(threads[i], NULL);

	for(int i = 0;i<dir.getSize();i++)
	{
		 cout<<images[i].goodmatches<<endl;
		 cout<<images[i].path<<endl;
	}

	// std::sort(images.begin(),images.end(),compFunction);
	// int l;
	// for(int i = 0;i<TOP_NUM;i++)
	// {
	// 	l = images.size()-i-1;
	// 	cout<<images[l].goodmatches<<endl;
	// 	cout<<images[l].path<<endl;
	// }
}

	pthread_exit(NULL);
	waitKey(0);
	return 0;
}
