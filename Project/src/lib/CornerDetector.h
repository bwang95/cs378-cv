#ifndef CORNER_DETECT_H
#define CORNER_DETECT_H

int detectCorners(double qualityLevel = 0.1, double minDistance = 50, int blockSize = 3, bool useHarrisDetector = false, double k = 0.04);

#endif //CORNER_DETECT_H