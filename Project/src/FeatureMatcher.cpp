#include "lib/FeatureMatcher.h"
#include "lib/FeatureMatcherData.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"

using namespace std;
using namespace cv;

FeatureMatcher::FeatureMatcher(const char *img1, const char *img2):
	img_1(imread(img1, CV_LOAD_IMAGE_GRAYSCALE)),
	img_2(imread(img2, CV_LOAD_IMAGE_GRAYSCALE)),
	downsize(3) {
	if ( !img_1.data || !img_2.data ) {
		std::cout << " --(!) Error reading images " << std::endl;
		return;
	}
	data_1 = new FeatureMatcherData(&img_1);
	data_2 = new FeatureMatcherData(&img_2);

	run();
}

FeatureMatcher::~FeatureMatcher() {
	delete data_1;
	delete data_2;
}

void FeatureMatcher::setDownsize(int downsize) {
	this -> downsize = downsize;
}

int FeatureMatcher::run() {
	data_1 -> run(downsize);
	data_2 -> run(downsize);
}

void FeatureMatcher::setCompareImage(const char *name){
	img_2 = imread(name, CV_LOAD_IMAGE_GRAYSCALE);
	data_2 -> setImg(&img_2);
	data_2 -> run(downsize);
}

vector<DMatch> FeatureMatcher::matchFeatures() {
	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match( data_1 -> descriptors, data_2 -> descriptors, matches );


	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for ( int i = 0; i < data_1 -> descriptors.rows; i++ ) {
		double dist = matches[i].distance;
		if ( dist < min_dist ) min_dist = dist;
		if ( dist > max_dist ) max_dist = dist;
	}

	std::vector< DMatch > good_matches;

	for ( int i = 0; i < data_1 -> descriptors.rows; i++ ) {
		if ( matches[i].distance <= max(1.6* min_dist, 0.02) ) {
			good_matches.push_back(matches[i]);
		}
	}

	return good_matches;
}
int FeatureMatcher::drawFeatures(bool draw) {
	vector<DMatch> good_matches = matchFeatures();

	Mat img_matches;
	drawMatches( img_1, data_1 -> keypoints, img_2, data_2 -> keypoints,
	             good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
	             vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	
	//-- Show detected matches
	if (draw)               // Draws if true
		imshow( "Good Matches", img_matches );

	// 	for ( int i = 0; i < good_matches.size(); i++ )
	// 		printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx );
	return good_matches.size();
}
