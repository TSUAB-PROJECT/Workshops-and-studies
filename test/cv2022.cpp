#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat img(400, 500, CV_8UC3); // создаем изображение
	string text = " Hello World!";
	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_COMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, text, textOrg, fontFace, fontScale, color);
	imshow("My World", img);

	waitKey(0);
	return 0;
}