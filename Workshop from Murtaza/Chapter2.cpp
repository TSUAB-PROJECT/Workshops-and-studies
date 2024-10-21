#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  basic functions  //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat img_gray, img_blur, img_canny, img_dil, img_erode;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	GaussianBlur(img, img_blur, Size(7, 7), 150, 0);
	Canny(img_blur, img_canny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(img_canny, img_dil, kernel);
	erode(img_dil, img_erode, kernel);
	imshow("Image", img);
	imshow("Image Gray", img_gray);
	imshow("Image Blur", img_blur);
	imshow("Image Canny", img_canny);
	imshow("Image Dilation", img_dil);
	imshow("Image Erode", img_erode);
	waitKey(0);

}