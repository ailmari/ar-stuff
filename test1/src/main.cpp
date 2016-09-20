#include "timer.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	// Open video stream
	VideoCapture videostream(0);
	
	if (!videostream.isOpened()) {
		cout << "Sorry, camera not found" << endl;
		return 1;
		}
	
	double videoWidth = videostream.get(CV_CAP_PROP_FRAME_WIDTH);
	double videoHeight = videostream.get(CV_CAP_PROP_FRAME_HEIGHT);

	// Grab and show picture
	Mat rawBGR;
	Timer timer = Timer();
	
	while (true) {
		timer.reset();
		
		videostream >> rawBGR;
		timer.update();
		cout << timer.getDelta() << "s - read videostream" << endl;
		
		imshow("test", rawBGR);
		timer.update();
		cout << timer.getDelta() << "s - show image" << endl;
		
		cout << timer.getTotal() << "s - total time" << endl << endl;

		if (waitKey(1) == 27) {
			cout << videoHeight << " x " << videoWidth << endl;
			break;
		}
	}
	
	return 0;
}