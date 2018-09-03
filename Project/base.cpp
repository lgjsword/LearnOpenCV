#include "base.h"
using namespace cv;

void imageDisplay(void)
{
	Mat srcImage = imread("test.png");
	imshow("ԭʼͼƬ", srcImage);
	waitKey();
}

void imageCorr(void)
{
	Mat srcImage = imread("test.png");
	imshow("ԭͼ", srcImage);
	//��ʴ
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);

	imshow("��ʴЧ��", dstImage);

	waitKey();
}

void imageFilter(void)
{
	Mat srcImage = imread("test.png");
	imshow("ԭͼ", srcImage);
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	imshow("��ֵ�˲�Ч��", dstImage);
	waitKey();

}

void imageCanny(void)
{
	Mat srcImage = imread("test.png");
	imshow("ԭͼ", srcImage);

	Mat edge, grayImage;

	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	blur(grayImage, edge, Size(3, 3));

	Canny(edge, edge, 3, 9, 3);

	imshow(" ��Ե���", edge);

	waitKey();
}

void videoAcq(void)
{
	VideoCapture capture(0);
	while (1) {
		Mat frame;
		capture >> frame;
		imshow("video", frame);
		waitKey(10);
	}

}