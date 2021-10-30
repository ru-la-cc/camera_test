#pragma warning(disable:4819)

#include <windows.h>
#include <tchar.h>
#include <opencv2/opencv.hpp>

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpCmdLine, int nShowCmd)
{
	cv::VideoCapture video;
	video.open(0); // ← カメラどれ？
	if (!video.isOpened()) {
		::MessageBox(NULL, _T("開けんわ"), _T("残念"), MB_ICONERROR | MB_OK);
	}

	cv::Mat image;
	int key;
	double property;
	while (video.isOpened()) {
		video >> image;
		cv::imshow("Camera", image);
		key = cv::waitKey(1);
		if (key == 27) { // ESC
			break;
		}
		property = cv::getWindowProperty("Camera", cv::WND_PROP_VISIBLE);
		if (property == 0) break; // ウィドウ閉じられてたら終わらせる
	}

	return 0;
}
