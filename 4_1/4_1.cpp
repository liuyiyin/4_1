// 4_1.cpp : �������̨Ӧ�ó������ڵ㡣
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

	imshow("��ʴ", fushi);
	imshow("����", pengzhang);
	imshow("������", kai);
	imshow("������", bi);
	waitKey(0);
	return 0;
}

