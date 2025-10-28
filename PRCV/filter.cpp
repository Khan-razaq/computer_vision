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

int sepiaToneFilter(cv::Mat &src, cv::Mat &dst){
    dst.create(src.rows, src.cols, src.type());
    for(int row=0;row<src.rows;row++){
        for(int col=0;col<src.cols;col++){
            cv::Vec3b pixel = src.at<cv::Vec3b>(row,col);
            float newBlue = pixel[0]*0.131 + pixel[1]*0.534 + pixel[2]*0.272;
            float newGreen = pixel[0]*0.168 + pixel[1]*0.686 + pixel[2]*0.349;
            float newRed = pixel[0]*0.189 + pixel[1]*0.769 + pixel[2]*0.393;
            //use cv::saturate_cast to go between float to uchar 
            if(newBlue>255){
                newBlue = 255;
            }
            if(newGreen>255){
                newGreen = 255;
            }
            if(newRed>255){
                newRed = 255;
            }
            dst.at<cv::Vec3b>(row,col) = cv::Vec3b(newBlue,newGreen,newRed);
        }
    }
    return 0;
}
