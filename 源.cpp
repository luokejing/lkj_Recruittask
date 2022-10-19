#include"stdio.h"
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
vector<vector<int>> myColors{ {50,77,43,255,46,255},
							 {120,120,43,255,46,255} };
Mat imgHSV, mask,mask2;
int hmin1=120,hmax1=121,smin1=43,smax1=255,vmin1=46,vmax1=255;
int hmin2 = 50, hmax2 = 77, smin2 = 43, smax2 = 255, vmin2 = 46, vmax2 = 255;
int main()
{
	Mat img = imread("C:\\tag.png");
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		//调试颜色
		//namedWindow("Trackbar", (640, 640));
		//createTrackbar("Hue Min","Trackbars",&hmin,179);
		//createTrackbar("Hue Max","Trackbars",&hmax,179);
		//createTrackbar("Sat Min","Trackbars",&smin,255);
		//createTrackbar("Sat Max","Trackbars",&smax,255);
		//createTrackbar("Val Min","Trackbars",&vmin,255);
		//createTrackbar("Val Max","Trackbars",&vmax,255);
		//while (true) {
		    Scalar lower1(hmin1, smin1, vmin1);
			Scalar upper1(hmax1, smax1, vmax1);
		    inRange(imgHSV, lower1, upper1, mask);
			Scalar lower2(hmin2, smin2, vmin2);
			Scalar upper2(hmax2, smax2, vmax2);
			inRange(imgHSV, lower2, upper2, mask2);
            namedWindow("text");
			imshow("text", img);
			imshow("Image HSV", imgHSV);
			imshow("Image Mask", mask);
			imshow("Image Mask2", mask2);
			waitKey(0);
			return(0);
		//}
}
