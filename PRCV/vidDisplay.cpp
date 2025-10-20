#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

bool grayFlag;

int main(){
    cv::VideoCapture cap(0);
    if(!cap.isOpened()){
    	cerr << "Error: Could not open the camera" << endl;
    	return -1;
    }
    cv::Mat frame;
    cv::Mat flipped_frame;
    cv::Mat gray_frame;
    cv::Mat display_frame;
    
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
	//cap.set(cv::CAP_PROP_FPS, 30);
	
    while(true){
    	cap >> frame;
    	if(frame.empty()){
		    cerr << "Error: Empty frame" << endl;
		    break;
		}
		
		cv::flip(frame, flipped_frame, 1);
		if(grayFlag){
			cvtColor(flipped_frame, gray_frame, cv::COLOR_RGB2GRAY);
			display_frame = gray_frame;
		}
		else{
			display_frame = flipped_frame;
    	}
    	cv::imshow("Video Window", display_frame);
    	
    	char key = cv::waitKey(30);
    	
    	if(key == 'q'){
    		cout << "Quitting" << endl;
    		break;
    	}
    	else if(key == 's'){
    		cv::imwrite("screenshot.jpg", display_frame);
    		cout << "Screenshot taken!" << endl;
    	}
    	else if(key == 'g'){
    		grayFlag = true;
    	}
    	else if(key == 'o'){
    		grayFlag = false;
    	}
    }
    cap.release();
    cv::destroyAllWindows();
    
    return 0;
}
