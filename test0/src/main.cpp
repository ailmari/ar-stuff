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
		
	// Main loop
	Mat rawBGR;
	Timer timer = Timer();
	int frameCounter = 0;
	double videoStreams[100];
	double imageShows[100];
	double totalTimes[100];
	
	while (true) {
		timer.reset();
		frameCounter = (frameCounter + 1) % 100;
		
		videoStream >> rawBGR;
		timer.update();
		videoStreams[frameCounter] = timer.getDelta();
		
		imshow("test", rawBGR);
		timer.update();
		imageShows[frameCounter] = timer.getDelta();
		
		totalTimes[frameCounter] = timer.getTotal();

		if (waitKey(1) == 27) {
			break;
		}
	}
	
	// Count execution times
	double sumVideoStreams = 0;
	double sumImageShows = 0;
	double sumTotalTimes = 0;
	double avgVideoStreams;
	double avgImageShows;
	double avgTotalTimes;
	for (int i = 0; i < 100; i++) {
		sumVideoStreams += videoStreams[i];
		sumImageShows += imageShows[i];
		sumTotalTimes += totalTimes[i];
		
		avgVideoStreams = sumVideoStreams / 100.0;
		avgImageShows = sumImageShows / 100.0;
		avgTotalTimes = sumTotalTimes / 100.0;
	}
	cout << avgVideoStreams << "s - read videostream" << endl;
	cout << avgImageShows << "s - show image" << endl;
	cout << avgTotalTimes << "s - total time" << endl;
	cout << 1.0 / avgTotalTimes << " fps" << endl << endl;
	
	return 0;
}