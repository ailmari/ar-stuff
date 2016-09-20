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
	videoStream.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	videoStream.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	
	// Set up window
	namedWindow("test", 1);
		
	// MAIN LOOP
	Mat bgr;
	Mat gray;
	Mat dst;
	
	Timer timer = Timer();
	
	int frameCounter = 0;
	
	double videoStreams[100];
	double preProcesses[100];
	double imageShows[100];
	double totalTimes[100];
	
	while (true) {
		timer.reset();
		
		frameCounter = (frameCounter + 1) % 100;
		
		// Grab raw image from videostream
		videoStream >> bgr;
		timer.update();
		videoStreams[frameCounter] = timer.getDelta();
		
		// Preprocess
		cvtColor(bgr, gray, CV_BGR2GREY);
		cvAdaptiveThreshold(gray, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 3, 1);
		timer.update();
		preProcesses[frameCounter] = timer.getDelta();
		
		// Show image on screen
		imshow("test", dst);
		timer.update();
		imageShows[frameCounter] = timer.getDelta();
		
		totalTimes[frameCounter] = timer.getTotal();

		if (waitKey(1) == 27) {
			break;
		}
	}
	
	// Count execution times
	double sumVideoStreams = 0;
	double sumPreProcesses = 0;
	double sumImageShows = 0;
	double sumTotalTimes = 0;
	
	double avgVideoStreams;
	double avgPreProcesses;
	double avgImageShows;
	double avgTotalTimes;
	
	for (int i = 0; i < 100; i++) {
		sumVideoStreams += videoStreams[i];
		sumPreProcesses += preProcesses[i];
		sumImageShows += imageShows[i];
		sumTotalTimes += totalTimes[i];
		
		avgVideoStreams = sumVideoStreams / 100.0;
		avgPreProcesses = sumPreProcesses / 100.0;
		avgImageShows = sumImageShows / 100.0;
		avgTotalTimes = sumTotalTimes / 100.0;
	}
	
	// Print execution times
	cout << avgVideoStreams << "s - read videostream" << endl;
	cout << avgPreProcesses << "s - preprocessing" << endl;
	cout << avgImageShows << "s - show image" << endl;
	cout << avgTotalTimes << "s - total time" << endl;
	cout << 1.0 / avgTotalTimes << " fps" << endl << endl;
	
	return 0;
}