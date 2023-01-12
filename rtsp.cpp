#include <iostream>
#include <functional>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv) {
    setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS","rtsp_transport;udp",10);
    cv::VideoCapture *stream = new cv::VideoCapture ("rtsp://192.168.50.117:8554/live?resolution=1920x960");
    stream->set(cv::CAP_PROP_BUFFERSIZE,3);
    //stream->set(cv::CAP_PROP_FPS, 30);
    if (!stream->isOpened()) return -1;
    cv::Mat frame;
    while (true) {

        if (!stream->read(frame)) return -1;
        flip(frame, frame, 1);
        cv::imshow("rtsp_stream", frame);
        cv::waitKey(2);
    }

    return 1;
}
