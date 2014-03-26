#ifndef FEATURE_DETECT_H
#define FEATURE_DETECT_H

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

void readme();
std::vector<KeyPoint>* detectCommonFeatures(char *img1, char *img2, vector<KeyPoint> *keypoints);

#endif //FEATURE_DETECT_H