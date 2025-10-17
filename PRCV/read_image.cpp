#include <iostream>
#include <filesystem>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    string image_path=samples::findFile("images/kabah.jpeg");
    Mat image = imread(image_path, IMREAD_COLOR);
    if (image.empty()) {
        cerr << "Error: Could not open or find the image." << image_path << endl;
        return -1;
    }
    imshow("Image Window", image);
    waitKey(0);
}
