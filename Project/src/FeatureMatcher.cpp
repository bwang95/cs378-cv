/*
 * @file SURF_FlannMatcher
 * @brief SURF detector + descriptor + FLANN Matcher
 * @author A. Huaman
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/FeatureMatcher.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"

using namespace cv;

Mat tmp, tmp2, img_1, img_2;

/**
 * @function main
 * @brief Main function
 */
int matchFeatures( int argc, char **argv ) {
	if ( argc != 4 ) {
		readme();
		return -1;
	}

	Mat img1 = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
	Mat img2 = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE );

	int downSize = atoi(argv[3]);

	if ( !img1.data || !img2.data ) {
		std::cout << " --(!) Error reading images " << std::endl;
		return -1;
	}
	//-- Down Sizing the images since they are too large
	img_1 = img1;
	img_2 = img2;
	tmp = img1;
	tmp2 = img2;
	int i;
	for ( i = 0; i < downSize; i++) {
		pyrDown(tmp, img_1, Size(tmp.cols / 2, tmp.rows / 2));
		pyrDown(tmp2, img_2, Size(tmp2.cols / 2, tmp2.rows / 2));
		tmp = img_1;
		tmp2 = img_2;
	}
	//-- Step 1: Detect the keypoints using SURF Detector
	int minHessian = 400;

	SurfFeatureDetector detector( minHessian );

	std::vector<KeyPoint> keypoints_1, keypoints_2;

	detector.detect( img_1, keypoints_1 );
	detector.detect( img_2, keypoints_2 );

	//-- Step 2: Calculate descriptors (feature vectors)
	SurfDescriptorExtractor extractor;

	Mat descriptors_1, descriptors_2;

	extractor.compute( img_1, keypoints_1, descriptors_1 );
	extractor.compute( img_2, keypoints_2, descriptors_2 );

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match( descriptors_1, descriptors_2, matches );

	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for ( int i = 0; i < descriptors_1.rows; i++ ) {
		double dist = matches[i].distance;
		if ( dist < min_dist ) min_dist = dist;
		if ( dist > max_dist ) max_dist = dist;
	}

	printf("-- Max dist : %f \n", max_dist );
	printf("-- Min dist : %f \n", min_dist );

	//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
	//-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
	//-- small)
	//-- PS.- radiusMatch can also be used here.
	std::vector< DMatch > good_matches;

	for ( int i = 0; i < descriptors_1.rows; i++ ) {
		if ( matches[i].distance <= max(2 * min_dist, 0.02) ) {
			good_matches.push_back( matches[i]);
		}
	}

	//-- Draw only "good" matches
	Mat img_matches;
	drawMatches( img_1, keypoints_1, img_2, keypoints_2,
	             good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
	             vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	//-- Show detected matches
	// imshow( "Good Matches", img_matches );

	for ( int i = 0; i < (int)good_matches.size(); i++ ) {
		printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx );
	}

	// waitKey(0);

	return 0;
}

/**
 * @function readme
 */
void readme() {
	std::cout << " Usage: ./SURF_FlannMatcher <img1> <img2> <reduce picture by 2^x>" << std::endl;
}
