#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Drow Shapes and Text  //////////////////////

void main() {
	// Blank Image
	
	Mat img(512,512,CV_8UC3,Scalar(255,255,255));
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), 10);
	circle(img, Point(256, 256), 100, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 0, 0), 3);
	rectangle(img, Point(200, 226), Point(300, 286), Scalar(0, 0, 0), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(0, 0, 0), 2);
	putText(img, "Polina Zenkova", Point(150, 262), FONT_HERSHEY_DUPLEX, 0.85, Scalar(255, 255, 255), 2);
	imshow("Image", img);
	
	waitKey(0);

}