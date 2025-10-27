#include <iostream>
#include <opencv2/opencv.hpp>

#include "filter.h"

using namespace std;

bool grayFlag;
bool customGrayFlag;

int main(){
    cv::VideoCapture cap(0);
    if(!cap.isOpened()){
    	cerr << "Error: Could not open the camera" << endl;
    	return -1;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
	//cap.set(cv::CAP_PROP_FPS, 30);
	
	cv::Mat frame, flipped_frame, display_frame, custom_gray;
	int mode = 0;
    while(true){
    	cap >> frame;
    	if(frame.empty()){
		    cerr << "Error: Empty frame" << endl;
		    break;
		}
		
		cv::flip(frame, flipped_frame, 1);
		switch(mode) {
            case 1:
                grayFilter(flipped_frame, display_frame);
                break;
            case 2:
                customGrayFilter(flipped_frame, custom_gray);
                display_frame = custom_gray;
                break;
            default:
                display_frame = flipped_frame;
        }
        
        cv::imshow("Video Window", display_frame);
        
        char key = cv::waitKey(30);
        if(key == 'q') break;
        else if(key == 'g') mode = 1;
        else if(key == 'h') mode = 2;
        else if(key == 'o') mode = 0;
    }
    
    return 0;
}