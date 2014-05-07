#include "lib/All.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include <algorithm>

using namespace std;

#define NUM_THREADS 4	//defines the number of threads used in the program
#define TOP_NUM 5	//defines the top results produced at the end

struct ImageData{	//stores image data
	string path;
	int goodmatches;
};

bool compFunction (ImageData i,ImageData j) {return (i.goodmatches<j.goodmatches);}	//comparator function for sort

vector<ImageData> images;
Direct dir;
char *path;

int find(string str,string list[]){	//finds a string in an string array
	for(int i = 0;i<TOP_NUM;i++)
		if(list[i] == str)
			return i;
	return -1;
}

//returns the most common directory
string TopVote(string list[]){
	string paths[TOP_NUM];
	int pathcounts[TOP_NUM];
	int found,currentIndex = 0;
	string temp;

	for(int i = 0;i<TOP_NUM;i++){ 	//initializing arrays
		paths[i] = "";
		pathcounts[i] = 0;
	}

	for(int i = 0;i<TOP_NUM;i++){	//creates string count
		temp = list[i];
		found = temp.find_last_of("/\\");
		temp = temp.substr(0,found);		//splits paths from file
		found = find(temp,paths);
		if(found >= 0)
			pathcounts[found]++;
		else
		{
			paths[currentIndex] = temp;
			pathcounts[currentIndex]++;
			currentIndex++;
		}
	}
	//Uncomment below to debug TOPVOTE
	// for(int i = 0;i<TOP_NUM;i++){ 	
	// 	cout<<paths[i]<<"\t"<<pathcounts[i]<<endl;
	// }
	// cout<<endl;

	int max = -1;
	for(int i = 0;i < currentIndex;i++)	//finds max in array
		if(max<pathcounts[i])
		{
			max = pathcounts[i];
			temp = paths[i];
		}
	
	return temp.substr(temp.find_last_of("/\\")+1,temp.length() -1);	
}

//pthread function 
void *computeMatches(void *threadid){
	ImageData temp;
	long id = (long) threadid;
	int min,max,size;
	size = dir.getSize(); 	
	min = id * (size/NUM_THREADS);
	max = min + size/NUM_THREADS - 1;
	//cout<<"Thread: "<<id<<endl;
	if(id == (NUM_THREADS-1))
		max = size-1;
	//cout<<"id: "<<id<<" max: "<<max<<"\t min: "<<min<<endl;
	FeatureMatcher matcher(path, dir.list[min].c_str());
	temp.path = dir.list[min];
	temp.goodmatches = matcher.drawFeatures(false);
	images.push_back(temp);
	for (int i = min + 1; i <= max; i++) 
	{
		//cout << "Comparing " << path << " and " << dir.list[i] << " #" << i << endl;
		matcher.setCompareImage(dir.list[i].c_str());
		temp.path = dir.list[i];
		temp.goodmatches = matcher.drawFeatures(false);  //set to false to not draw
		images.push_back(temp);
	}

	pthread_exit(NULL);
}

int main(int argc, char **argv) {

	path = argv[1];
	if (argc < 2) { //if not enough arguments
		cout << "Project <img> (optional:directory)" << endl;
		return 1;
	}

	if (dir.getSize() == 0){
		cout << "Directory not found or empty" << endl;
		return 1;
	}
	
	cout << "Computing matches."<<endl;
		
	pthread_t threads[NUM_THREADS];
   	pthread_t rc;
   	for(int i=0; i < NUM_THREADS; i++ ){
  		//cout << "main() : creating thread, " << i << endl;
    	rc = pthread_create(&threads[i], NULL,computeMatches, (void *)i);
    	if (rc){
       		cout << "Error:unable to create thread," << rc << endl;
     		exit(-1);
    		}
   	}

   	for(int i = 0;i<NUM_THREADS;i++)
   		pthread_join(threads[i], NULL);

	//Sorting and Ranking 
   	string TOP[TOP_NUM];
	std::sort(images.begin(),images.end(),compFunction);
	int l;
	for(int i = 0;i<TOP_NUM;i++)
	{
		l = images.size()-i-1;
		cout<<"#"<<i+1<<" "<<images[l].path<<endl;
		cout<<"GoodMatches: "<<images[l].goodmatches<<endl;
		FeatureMatcher matcher(path, images[l].path.c_str());
		matcher.drawFeatures(true);
		waitKey(0);
		TOP[i] = images[l].path;
		
	}
	
	cout<< "The Top Vote is : " << TopVote(TOP)<<endl;

	//pthread_exit(NULL);
	return 0;
}
