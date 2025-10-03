#include<iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(){
    cv::Mat image = cv::imread("images/kabah.jpeg", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image." << std::endl;
        return -1;
    }
    cv::imshow("Image Window", image);
    cv::waitKey(0);
}