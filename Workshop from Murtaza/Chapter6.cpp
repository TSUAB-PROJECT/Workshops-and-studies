#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////// Color Detection /////////

void ColorDetection(const string& path) {
	Mat img = imread(path);
	Mat img_hsv;
	cvtColor(img, img_hsv, COLOR_BGR2HSV);
	namedWindow("Trackbars", (640, 200));
	//int hmin = 0, smin = 110, vmin = 153;
	//int hmax = 19, smax = 240, vmax = 255;
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		Mat mask;
		inRange(img_hsv, lower, upper, mask);
		imshow("Image", img);
		imshow("Image HSV", img_hsv);
		imshow("Image Mask", mask);
		waitKey(1);
	}
}
void main() {
	//ColorDetection("Resources/lambo.png");
	ColorDetection("Resources/shapes.png");

}
