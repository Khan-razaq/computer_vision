#ifndef FILTER_H
#define FILTER_H

#include <opencv2/opencv.hpp>

int customGrayFilter(cv::Mat &src, cv::Mat &dst);
int grayFilter(cv::Mat &src, cv::Mat &dst);

#endif