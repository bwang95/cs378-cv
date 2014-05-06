#include "lib/dbDescriptors.h"

dbDescriptors::dbDescriptors()
{
	FileStorage fs("dbDescriptors.yml", FileStorage::WRITE);
	Direct dir;
	Mat img;

	for(int i = 0;i<dir.getSize();i++){
		img = imread(dir.list[i], CV_LOAD_IMAGE_GRAYSCALE);
		FeatureMatcherData *data = new FeatureMatcherData(&img);
		data->run(3);
		fs<<"Path"<<dir.list[i];
		fs<<"Descriptor"<<data->descriptors;

		delete data;
	}

	fs.release();
}
