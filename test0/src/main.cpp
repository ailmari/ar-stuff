#include "timer.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	// Open video stream
	VideoCapture videoStream(0);
	
	if (!videoStream.isOpened()) {
		cout << "Sorry, camera not found" << endl;
		return 1;
		}

	// Grab and show picture
	Mat rawBGR;
	Timer timer = Timer();
	int frameCounter = 0;
	double videoStreams[100];
	double imageShows[100];
	double totalTimes[100];
	
	while (true) {
		timer.reset();
		frameCounter = ++frameCounter % 100;
		
		videoStream >> rawBGR;
		timer.update();
		videoStreams[frameCounter] = timer.getDelta();
		//cout << timer.getDelta() << "s - read videostream" << endl;
		
		imshow("test", rawBGR);
		timer.update();
		imageShows[frameCounter] = timer.getDelta();
		//cout << timer.getDelta() << "s - show image" << endl;
		
		totalTimes[frameCounter] = timer.getTotal();
		//cout << timer.getTotal() << "s - total time" << endl << endl;

		if (waitKey(1) == 27) {
			break;
		}
	}
	
	double sumVideoStreams = 0;
	double sumImageShows = 0;
	double sumTotalTimes = 0;
	for (int i = 0; i < 100; i++) {
		double sumVideoStreams =+ videoStreams[i];
		double sumImageShows =+ imageShows[i];
		double sumTotalTimes =+ totalTimes[i];
		
		avgVideoStreams = sumVideoStreams / 100;
		avgImageShows = sumImageShows / 100;
		avgTotalTimes = sumTotalTimes / 100;
	}
	return 0;
}