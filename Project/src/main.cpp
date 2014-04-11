#include "lib/All.h"
#include <iostream>
#include <string>

using namespace std;

struct ImageData{
	string path;
	int goodmatches;
	int min_num;
//	FeatureMatcher matched;
};

int main(int argc, char **argv) {

	vector<ImageData> topImages;
	vector<ImageData> definiteImages;
	bool isMin;
	ImageData temp;
	int TOP_NUM = 4;

	if (argc < 3) { //if not enough arguments
		cout << "Project <img> <directory> (optional: downsize)" << endl;
		return 1;
	}

	Directory dir(argv[2]);
	if (dir.getSize() == 0)
		cout << "Directory not found or empty" << endl;
	else 
	{	
		cout << "Computing matches."<<endl;
		for (int i = 0; i < dir.getSize(); i++) 
		{
			isMin = false;
			dir.list[i] = argv[2] + dir.list[i];  //appends file dir list to img name

			//cout << "Comparing " << argv[1] << " and " << dir.list[i] << " #" << i + 1 << endl;
			if (string(argv[1]) != dir.list[i]) 
			{

				FeatureMatcher matcher(argv[1], dir.list[i].c_str());
				if (argc >= 4)	//changes default downsize
					matcher.setDownsize(atoi(argv[3]));

				temp.path = dir.list[i];
//				temp.matched = matcher;
				temp.goodmatches = matcher.drawFeatures(false);  //set to false to not draw
				temp.min_num = matcher.getMinNum();
				//cout << temp.goodmatches << " matches" << endl;

				//Top matches algorithm
				vector<ImageData>::iterator it;
				if(topImages.size() == 0)
					topImages.push_back(temp);
				else
				{
					it = topImages.begin();
					int i = 0;
					if(temp.min_num>0)
						definiteImages.push_back(temp);

					while(topImages[i].goodmatches < temp.goodmatches  && i <= TOP_NUM && it < topImages.end())
					{
						it++;i++;
					}

					if(topImages.size()<TOP_NUM)
						topImages.insert(it,temp);
					else
					if(topImages.size() == TOP_NUM && i>0)
					{
						topImages.insert(it,temp);
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

			FeatureMatcher matcher(argv[1], topImages[i].path.c_str());
			matcher.drawFeatures(true);
			waitKey(0);
		}

		cout << "\n\n Matches with minimum distances. (Accurate points)" <<endl;
		for(int i = 0;i<topImages.size();i++)
		{
			cout<<"Number of Min Matches: "<< topImages[i].min_num<<endl;
			cout<<"File Name: " << topImages[i].path<<endl<<endl;

			FeatureMatcher matcher(argv[1], topImages[i].path.c_str());
			matcher.drawFeatures(true);
			waitKey(0);
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
