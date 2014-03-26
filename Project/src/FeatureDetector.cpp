#include "lib/FeatureDetector.h"

using namespace cv;
using namespace std;

/** @function main */
vector<KeyPoint>* detectCommonFeatures(char *img1, char *img2, vector<KeyPoint> *keypoints) {

	Mat img_1 = imread( img1, CV_LOAD_IMAGE_GRAYSCALE );
	Mat img_2 = imread( img2, CV_LOAD_IMAGE_GRAYSCALE );

	if ( !img_1.data || !img_2.data ) {
		std::cout << " --(!) Error reading images " << std::endl;
		return keypoints;
	}

	//-- Step 1: Detect the keypoints using SURF Detector
	int minHessian = 400;

	SurfFeatureDetector detector( minHessian );

	detector.detect( img_1, keypoints[0] );
	detector.detect( img_2, keypoints[1] );

	return keypoints;
}

/** @function readme */
void readme() {
	std::cout << " Usage: ./SURF_detector <img1> <img2>" << std::endl;
}