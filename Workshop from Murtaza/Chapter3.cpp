#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Resize and Crop  //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat img_resize;
	cout << img.size() << endl;
	resize(img, img_resize, Size(),0.5,0.5);
	Rect roi(200, 100, 300, 350);
	Mat img_crop = img(roi);
	imshow("Image", img);
	imshow("Image Resize", img_resize);
	imshow("Image Crop", img_crop);
	waitKey(0);

}