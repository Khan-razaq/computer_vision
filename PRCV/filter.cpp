#include "filter.h"

int customGrayFilter(cv::Mat &src, cv::Mat &dst){
	dst.create(src.rows, src.cols, src.type());
    for(int row=0;row<src.rows;row++){
        for(int col=0;col<src.cols;col++){
            cv::Vec3b pixel = src.at<cv::Vec3b>(row,col);
            uchar newGray = (pixel[0] + pixel[1] + pixel[2])/3;
            dst.at<cv::Vec3b>(row,col) = cv::Vec3b(newGray,newGray,newGray);
        }
    }
	return 0;
}

int grayFilter(cv::Mat &src, cv::Mat &dst){
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    return 0;
}
