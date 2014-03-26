#ifndef FEATURE_MATCH_DATA_H
#define FEATURE_MATCH_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"


class FeatureMatcherData {
public:
	Mat *img, *descriptors;
	vector<KeyPoint> *keypoints;

	FeatureMatcherData(){}

	FeatureMatcherData(Mat *img, Mat *descriptors, vector<KeyPoint> *keypoints) {
		this -> img = img;
		this -> descriptors = descriptors;
		this -> keypoints = keypoints;
	}
	~FeatureMatcherData() {
		delete img;
		delete descriptors;
		delete keypoints;
	}

	void downsize(int downSize) {
		Mat tmp = *img;
		for (int i = 0; i < downSize; i++) {
			pyrDown(tmp, *img, Size(tmp.cols / 2, tmp.rows / 2));
			tmp = *img;
		}
	}

	void calcKeyPoints() {
		int minHessian = 400;
		SurfFeatureDetector detector( minHessian );
		detector.detect( *img, *keypoints );
	}

	void calcDescriptors() {
		SurfDescriptorExtractor extractor;
		extractor.compute( *img, *keypoints, *descriptors );
	}

	void run(int downSize = 3) {
		downsize(downSize);
		calcKeyPoints();
		calcDescriptors();
	}
};

#endif