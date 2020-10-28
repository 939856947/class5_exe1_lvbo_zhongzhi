#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())//isopened����Ƿ���ȷ����������������1
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);//get���������Ƶ��fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		Mat dispMat_gray;//��ɫͼ��ת���ɻҶ�ͼ  
		cv::Mat zhongzhi;
		cv::Mat junzhi;
		cv::Mat Gaussian;
		cv::Mat bianyuan_x;
		cv::Mat bianyuan_y;
		cv::Mat Canny_result;
		cv::Mat bianyuan_x_c;
		cv::Mat bianyuan_y_c;
		bool rSucess = cap.read(frame);//��ȡ��Ƶ�ĵ�ǰ֡
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);//��ʾ��ǰ֡
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
		//cv::imshow(" zhongzhi", zhongzhi);//��ֵ�˲�
		//cv::imshow(" junzhi", junzhi);//��ֵ�˲�
		//cv::imshow(" Gaussian", Gaussian);//��˹�˲�
		cv::imshow(" bianyuan_x", bianyuan_x);//��Ե��ȡ
		cv::imshow(" bianyuan_y", bianyuan_y);
		cv::imshow(" bianyuan_y_c", bianyuan_y_c);
		cv::imshow(" bianyuan_x_c", bianyuan_x_c);

		cv::imshow("  Canny_result", Canny_result);
		waitKey(60);
	}


}