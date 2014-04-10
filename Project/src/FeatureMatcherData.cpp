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
	Mat dst;
	for (int i = 0; i < downSize; i++) {
		pyrDown(tmp, dst, Size(tmp.cols / 2, tmp.rows / 2));
		tmp = dst;
	}
	*img = dst;
}

void FeatureMatcherData::calcKeyPoints() {
<<<<<<< HEAD
	int minHessian = 800;
=======
	int minHessian = 500;
>>>>>>> b95292d7d25fc2b1435b5377dfc9b3772361bb31
	SiftFeatureDetector detector( minHessian );
	detector.detect( *img, keypoints );
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
