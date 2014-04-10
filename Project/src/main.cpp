#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

struct ImageData{
	string path;
	int goodmatches;
//	FeatureMatcher matched;
};

int main(int argc, char **argv) {

	vector<ImageData> topImages;
	ImageData temp;
	int TOP_NUM = 4;

	if (argc < 3) { //not enough arguments
		cout << "Project <img> <directory> (optional: downsize)" << endl;
		return 1;
	}

	Directory dir(argv[2]);
	if (dir.getSize() == 0)
		cout << "Directory not found or empty" << endl;
	else {
		for (int i = 0; i < dir.getSize(); i++) {
			dir.list[i] = argv[2] + dir.list[i];  //appends file dir list to img name

			cout << "Comparing " << argv[1] << " and " << dir.list[i] << " #" << i + 1 << endl;
			if (string(argv[1]) == dir.list[i]) 
				cout << "Same file" << endl;
			else {

				FeatureMatcher matcher(argv[1], dir.list[i].c_str());
				if (argc >= 4)	//changes default downsize
					matcher.setDownsize(atoi(argv[3]));

				temp.path = dir.list[i];
//				temp.matched = matcher;
				temp.goodmatches = matcher.drawFeatures(false, false);  //set to false to not draw,
																	//and false to not print out each keypoint
				cout << temp.goodmatches << " matches" << endl;

				if(topImages.size() == 0)
					topImages.push_back(temp);
				else
				if(topImages.size() < TOP_NUM)
				{
					vector<ImageData>::iterator it = topImages.begin();
					int i = 0;
					while(temp.goodmatches < topImages[i].goodmatches && it < topImages.end())
					{
						it++;i++;
					}
					topImages.insert(it,temp);
				}
				else
				{
					if(topImages.back().goodmatches < temp.goodmatches)
					{
						topImages.push_back(temp);
						topImages.erase(topImages.begin());
					}
				}
				
				
			}

		}

		cout << "\n\n Top Matches" <<endl;
		for(int i = 0;i<topImages.size();i++)
		{
			cout<<"Number of Matches: "<< topImages[i].goodmatches<<endl;
			cout<<"File Name: " << topImages[i].path<<endl<<endl;

		}

		// // cout << "\n\nMost Matches: " << max << endl;
		// // cout << "File name: " << maxImg << endl;
		// // FeatureMatcher matcher(argv[1], maxImg.c_str());
		// matcher.drawFeatures(true, false);
		// delete matcher;
	}
	waitKey(0);
	return 0;
}
