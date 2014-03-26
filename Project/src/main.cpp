#include "lib/All.h"

int main(int argc, char **argv){
	FeatureMatcher *matcher = new FeatureMatcher(argv[1], argv[2]);
	matcher -> drawFeatures();
	delete matcher;

	waitKey(0);
	return 0;
}