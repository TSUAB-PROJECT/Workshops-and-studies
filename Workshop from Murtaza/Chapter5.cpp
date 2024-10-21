#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////// Image /////////
 
//Mat matrix_king, matrix_queen, img_warp_king, img_warp_queen;
void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	float width = 250, height = 350;
	Point2f src_king[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst_king[4] = { {0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height} };
	Point2f src_queen[4] = { {63,320},{340,278},{85,638},{403,576} };
	Point2f dst_queen[4] = { {0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height} };
	
	Mat matrix_king = getPerspectiveTransform(src_king, dst_king);
	Mat img_warp_king;
	warpPerspective(img, img_warp_king, matrix_king, Point(width, height));
	
	Mat matrix_queen = getPerspectiveTransform(src_queen, dst_queen);
	Mat img_warp_queen;
	warpPerspective(img, img_warp_queen, matrix_queen, Point(width, height));
	
	for (int i = 0; i < 4; ++i) {
		circle(img, src_king[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src_queen[i], 10, Scalar(0, 0, 255), FILLED);
	}
	imshow("Image", img);
	imshow("Image warp king", img_warp_king);
	imshow("Image warp queen", img_warp_queen);
	waitKey(0);
}
