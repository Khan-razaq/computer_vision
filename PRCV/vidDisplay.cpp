#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(){
    cv::VideoCapture cap(0);
    if(!cap.isOpened()){
    	cerr << "Error: Could not open the camera" << endl;
    	return -1;
    }
    cv::Mat frame;
    cv::Mat flipped_frame;
    
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
    	cv::imshow("Video Window", flipped_frame);
    	char key = cv::waitKey(30);
    	
    	if(key == 'q'){
    		break;
    	}
    	else if(key == 's'){
    		cv::imwrite("screenshot.jpg", flipped_frame);
    		cout << "Image saved!" << endl;
    	}

    }
    cap.release();
    cv::destroyAllWindows();
    
    return 0;
}
