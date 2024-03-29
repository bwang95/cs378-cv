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

FeatureMatcherData::FeatureMatcherData(Mat *image):
	img(image), descriptors(), keypoints() {}

void FeatureMatcherData::downsize(int downSize) {
	Mat tmp = *img;
	int downsize = downSize;
	// long pxls = tmp.rows * tmp.cols;
	// cout<<pxls<<endl;
	// if(pxls >= 12000000)
	// 	downsize = 3;
	// else
	// if(pxls >= 8000000)
	// 	downsize = 2;
	// else
	// 	return;

	Mat dst;
	for (int i = 0; i < downsize; i++) {
		pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
		tmp = dst;
	}
	*img = dst;
}

void FeatureMatcherData::calcKeyPoints() {
	int minHessian = 200;

	SiftFeatureDetector detector( minHessian );
	detector.detect( *img, keypoints );
}

void FeatureMatcherData::setImg(Mat *image){
	img = image;
}

void FeatureMatcherData::calcDescriptors() {
	SiftDescriptorExtractor extractor;
	extractor.compute( *img, keypoints, descriptors );
}

void FeatureMatcherData::run(int downSize) {
	downsize(downSize);
	calcKeyPoints();
	calcDescriptors();
}
