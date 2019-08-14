#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <windows.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	int i = 0;
	VideoCapture cap;
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	if (!cap.open(0))
		return 0;

	for (;;)
	{
		if (i == 0) {
			Mat frame;
			namedWindow("Reference", 1);
			cap >> frame;
			if (frame.empty()) break; // end of video stream

			Mat img(650, 600, CV_16UC3, Scalar(0, 50000, 50000)); //create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

			if (img.empty()) //check whether the image is loaded or not
			{
				cout << "ERROR : Image cannot be loaded..!!" << endl;
				//system("pause"); //wait for a key press
				return -1;
			}
			img = frame;

			vector<int> compression_params; //vector that stores the compression parameters of the image

			compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

			compression_params.push_back(98); //specify the compression quality

			bool bSuccess = imwrite("D:/Reference.jpg", img, compression_params); //write the image to file

			imshow("Reference", frame);
			if (waitKey(1) == 27) //esc
			{
				i++;
				destroyWindow("Reference");

			}
		}

		if (i == 1) {
			Sleep(100);
			Mat frame2;
			namedWindow("NewImage", 2);
			cap >> frame2;
			if (frame2.empty()) break; // end of video stream

			Mat img2(650, 600, CV_16UC3, Scalar(0, 50000, 50000)); //create an image ( 3 channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned for Blue, Green and Red plane respectively. )

			if (img2.empty()) //check whether the image is loaded or not
			{
				cout << "ERROR : Image cannot be loaded..!!" << endl;
				//system("pause"); //wait for a key press
				return -1;
			}
			img2 = frame2;

			vector<int> compression_params; //vector that stores the compression parameters of the image

			compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

			compression_params.push_back(98); //specify the compression quality

			bool bSuccess = imwrite("D:/NewImage.jpg", img2, compression_params); //write the image to file

			imshow("NewImage", frame2);
			if (waitKey(1) == 17) //ctrl
			{
				i = 1;
				break;
			}
		}

	}


	// the camera will be closed automatically upon exit
	// cap.close();

	return 0;
}