#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	// FeatureMatcher matcher;
	string maxImg;
	int max = 0;

	if (argc < 3) { //not enough arguments
		cout << "Project <img> <directory> (optional: downsize)" << endl;
		return 1;
	}

	//Directory *dir = new Directory("");
	//getSize retrieves the number of objects in the directory
	//makeList() creates the list pointer array and returns true if successful
	Directory dir(argv[2]);
	// cout << dir.getSize() << endl;
	if (dir.getSize() == 0)
		cout << "Directory not found or empty" << endl;
	else {
		for (int i = 0; i < dir.getSize(); i++) {
			dir.list[i] = argv[2] + dir.list[i];  //appends file dir list to img name

			cout << "Comparing " << argv[1] << " and " << dir.list[i] << " #" << i + 1 << endl;
			if (string(argv[1]) == dir.list[i]) {
				cout << "Same file" << endl;
			} else {

				FeatureMatcher matcher(argv[1], dir.list[i].c_str());
				if (argc >= 4)
					matcher.setDownsize(atoi(argv[3]));

				int matchSize = matcher.drawFeatures(false, false);  //set to false to not draw,
				//and false to not print out each keypoint
				if (max < matchSize) {
					max = matchSize;
					maxImg = dir.list[i];
				}
				cout << matchSize << " matches" << endl;
				// delete matcher;
			}

		}

		cout << "\n\nMost Matches: " << max << endl;
		cout << "File name: " << maxImg << endl;
		FeatureMatcher matcher(argv[1], maxImg.c_str());
		matcher.drawFeatures(true, false);
		// delete matcher;
	}
	waitKey(0);
	return 0;
}
