#include "timer.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	// Open video stream
	VideoCapture videoStream(0);
	if (!videoStream.isOpened())
	{
		cout << "Sorry, camera not found" << endl;
		return 1;
	}
	videoStream.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	videoStream.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
		
	// MAIN LOOP
	Mat bgr, hsv, bw;
	
	vector<vector<Point> > contours;
	vector<vector<Point> > corners;
	Scalar color = Scalar(0, 255, 0);
	
	Timer timer = Timer();
	int frameCounter = 0;
	double totalTimes[100];
	
	while (true)
	{
		timer.reset();
		frameCounter = (frameCounter + 1) % 100;
		
		// Grab BGR image from video stream
		videoStream >> bgr;

		// Preprocess
		cvtColor(bgr, hsv, CV_BGR2HSV);
		inRange(hsv, Scalar(45, 200, 100), Scalar(75, 255, 255), bw); // TODO: eti parhaat HSV arvot
		findContours(bw, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); // TODO: testaa eri parametrit
		corners.resize(contours.size());
		for (int i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), corners[i], 3, true);
		}
		fillPoly(bgr, corners, Scalar(255, 0, 255));
		
		// Show image on screen
		imshow("test", bgr);
		timer.update();
		totalTimes[frameCounter] = timer.getTotal();

		if (waitKey(1) == 27)
		{
			break;
		}
	}
	
	// Execution times
	double sumTotalTimes = 0;
	double avgTotalTimes;
	for (int i = 0; i < 100; i++)
	{
		sumTotalTimes += totalTimes[i];
	}
	avgTotalTimes = sumTotalTimes / 100.0;
	cout << avgTotalTimes << "s - total time" << endl;
	cout << 1.0 / avgTotalTimes << " fps" << endl << endl;

	return 0;
}