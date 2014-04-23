 #include "FeatureMatcherData.h"
 #include "opencv2/opencv.hpp"
 #include "Direct.h"

using namespace cv;

int main(int argc, char **argv){

	FileStorage fs("dbDescriptors.yml", FileStorage::WRITE);
	Direct dir(argv[1]);
	Mat img;

	for(int i = 0;i<dir.getSize();i++){
		img = imread(dir.list[i], CV_LOAD_IMAGE_GRAYSCALE);
		FeatureMatcherData *data = new FeatureMatcherData(&img);
		fs<<"Path"<<dir.list[i];
		fs<<"Descriptor"<<data->descriptors;

		delete data;
	}

	fs.release();
	return 0;
}
