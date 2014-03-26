#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "lib/Display.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void newWindow(char *img) {
	Mat image = imread(img, 1);
	if (!image.data) {
		cout << "Error reading image!" << endl;
		return;
	}
	namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	imshow("Display Image", image);
}