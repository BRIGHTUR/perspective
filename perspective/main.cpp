#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("lena.jpg", 1);
	if (srcMat.empty()) return -1;
	const Point2f src_pt[] = {
								Point2f(150,150),
								Point2f(150,300),
								Point2f(350,300),
								Point2f(350,150)};
	const Point2f dst_pt[] = {
								Point2f(200,150),
								Point2f(200,300),
								Point2f(340,270),
								Point2f(340,180)};
	Mat perspective_matrix = getPerspectiveTransform(src_pt, dst_pt);
	warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}