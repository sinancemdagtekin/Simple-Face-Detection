#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	string path = "Resources/video.mp4";
	VideoCapture cap(path);

	Mat img;

	//load the Haar Cascade
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	//to check if it is loaded properly
	if (faceCascade.empty()) { cout << "xml file not loaded" << endl; }

	while (true) {

		cap.read(img);

		//detect the faces and store them
		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		//iterate the faces which detected

		for (int i = 0; i < faces.size(); i++) {

			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
		}

		cv::imshow("Image", img);

		cv::waitKey(10);//to wait 10 milisecond for each image

	}
}
