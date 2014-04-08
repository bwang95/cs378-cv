#ifndef FEATURE_MATCH_H
#define FEATURE_MATCH_H

#include "FeatureMatcherData.h"
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

class FeatureMatcher {
	FeatureMatcherData *data_1, *data_2;
	Mat img_1, img_2;
	int downsize;
	int goodmatches;
public:
	FeatureMatcher(char *img1, char *img2);
	~FeatureMatcher();
	int run();
	vector<DMatch> matchFeatures();
	void drawFeatures(bool,bool);
	void setDownsize(int downsize);
	int getMatchSize(){return goodmatches;}
	
};

#endif //FEATURE_MATCH_H
