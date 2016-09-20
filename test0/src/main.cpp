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

	// Grab and show picture
	Mat rawBGR;
	Timer timer = Timer();
	while (true) {
		timer.reset();		
		videostream.read(rawBGR);
		timer.update();
		cout << t.getDelta() << "s - read videostream" << endl;
		imshow("test", rawBGR);
		timer.update();
		cout << t.getDelta() << "s - show image" << endl;

		if (waitKey(10) == 27) {
			break;
		}
	}
	
	return 0;
}