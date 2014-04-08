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

FeatureMatcherData::FeatureMatcherData(Mat *img) {
	this -> img = img;
	keypoints = new vector<KeyPoint>();
	descriptors = new Mat();
}

FeatureMatcherData::~FeatureMatcherData() {
	// delete img;
	delete descriptors;
	delete keypoints;
}

void FeatureMatcherData::downsize(int downSize) {
	Mat *tmp = img;
	for (int i = 0; i < downSize; i++)
		pyrDown(*tmp, *img, Size(tmp -> cols / 2, tmp -> rows / 2));

}

void FeatureMatcherData::calcKeyPoints() {
	int minHessian = 400;
	SurfFeatureDetector detector( minHessian );
	detector.detect( *img, *keypoints );
}

void FeatureMatcherData::calcDescriptors() {
	SurfDescriptorExtractor extractor;
	extractor.compute( *img, *keypoints, *descriptors );
}

void FeatureMatcherData::run(int downSize) {
	downsize(downSize);
	calcKeyPoints();
	calcDescriptors();
}
