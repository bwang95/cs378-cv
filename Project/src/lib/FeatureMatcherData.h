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

using namespace cv;
using namespace std;

class FeatureMatcherData {
public:
	Mat img, descriptors;
	vector<KeyPoint> keypoints;

	FeatureMatcherData() {}
	FeatureMatcherData(Mat img);
	~FeatureMatcherData();
	void downsize(int downSize);
	void calcKeyPoints();
	void calcDescriptors();
	void run(int downSize = 3);
};

#endif