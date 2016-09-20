#include <opencv2/opencv.hpp>
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
	while (true) {
		Mat rawBGR;
		videostream.read(rawBGR);
		imshow("test"), rawBGR);

		if (waitKey(10) == 27) {
			break;
		}
	}
	
	return 0;
}
