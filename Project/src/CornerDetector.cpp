#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "lib/CornerDetector.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

/// Global variables
Mat src, src_gray;

int maxCorners = 23;
int maxTrackbar = 100;

// RNG rng(12345);
char *source_window = "Image";

/**
 * @function goodFeaturesToTrack_Demo.cpp
 * @brief Apply Shi-Tomasi corner detector
 */
int detectCorners(double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k) {
	if ( maxCorners < 1 )
		maxCorners = 1;

	/// Parameters for Shi-Tomasi algorithm
	vector<Point2f> corners;
	// double qualityLevel = 0.1;
	// double minDistance = 50;
	// int blockSize = 3;
	// bool useHarrisDetector = false;
	// double k = 0.04;

	/// Copy the source image
	Mat copy;
	copy = src.clone();

	/// Apply corner detection
	goodFeaturesToTrack( src_gray,
	                     corners,
	                     maxCorners,
	                     qualityLevel,
	                     minDistance,
	                     Mat(),
	                     blockSize,
	                     useHarrisDetector,
	                     k );


	/// Draw corners detected
	cout << "** Number of corners detected: " << corners.size() << endl;
	return corners.size();
	// int r = 25;
	// for ( int i = 0; i < corners.size(); i++ ) {
	//  circle( copy, corners[i], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
	//                                      rng.uniform(0, 255)), -1, 8, 0 );
	// }

	/// Show what you got
}

// /**
//  * @function main
//  */
// int displayCorners( int argc, char **argv ) {
// 	/// Load source image and convert it to gray
// 	src = imread( argv[1], 1 );
// 	cvtColor( src, src_gray, CV_BGR2GRAY );

// 	/// Create Window
// 	namedWindow( source_window, CV_WINDOW_NORMAL );

// 	/// Create Trackbar to set the number of corners
// 	createTrackbar( "Max  corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo );

// 	imshow( source_window, src );

// 	goodFeaturesToTrack_Demo( 0, 0 );

// 	waitKey(0);
// 	return (0);
// }