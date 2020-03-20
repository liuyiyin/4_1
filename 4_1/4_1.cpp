// 4_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("D:\\coin.png");
	cv::Mat src;
	cv::Mat fushi;
	cv::Mat pengzhang;
	cv::Mat kai;
	cv::Mat bi;

	threshold(srcMat, src, 100, 255, THRESH_BINARY);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	erode(src, fushi, kernel);
	dilate(src, pengzhang, kernel);
	morphologyEx(src, kai, 2, kernel);
	morphologyEx(src, bi, 3, kernel);

	imshow("腐蚀", fushi);
	imshow("膨胀", pengzhang);
	imshow("开运算", kai);
	imshow("闭运算", bi);
	waitKey(0);
	return 0;
}

