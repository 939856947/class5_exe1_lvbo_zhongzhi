#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())//isopened检查是否正确开启正常开启返回1
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);//get函数获得视频的fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		Mat dispMat_gray;//彩色图像转化成灰度图  
		cv::Mat zhongzhi;
		cv::Mat junzhi;
		cv::Mat Gaussian;
		cv::Mat bianyuan_x;
		cv::Mat bianyuan_y;
		cv::Mat Canny_result;
		cv::Mat bianyuan_x_c;
		cv::Mat bianyuan_y_c;
		bool rSucess = cap.read(frame);//获取视频的当前帧
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);//显示当前帧
		}
		cvtColor(frame, dispMat_gray, COLOR_BGR2GRAY);
		medianBlur(frame, zhongzhi,5);
		blur(frame, junzhi, Size(5, 5));
		GaussianBlur(frame, Gaussian, Size(7, 7),7,7);
		Sobel(dispMat_gray, bianyuan_x, -1, 1, 0, 3);
		Sobel(dispMat_gray, bianyuan_y, -1, 0, 1, 3);
		Canny(bianyuan_x, bianyuan_x_c, 100, 255, 3);
		Canny(bianyuan_y, bianyuan_y_c, 100, 255, 3);
		Canny(dispMat_gray, Canny_result, 100, 255, 3);
		//cv::imshow(" zhongzhi", zhongzhi);//中值滤波
		//cv::imshow(" junzhi", junzhi);//均值滤波
		//cv::imshow(" Gaussian", Gaussian);//高斯滤波
		cv::imshow(" bianyuan_x", bianyuan_x);//边缘提取
		cv::imshow(" bianyuan_y", bianyuan_y);
		cv::imshow(" bianyuan_y_c", bianyuan_y_c);
		cv::imshow(" bianyuan_x_c", bianyuan_x_c);

		cv::imshow("  Canny_result", Canny_result);
		waitKey(60);
	}


}