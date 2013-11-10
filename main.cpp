/**
    Opencv example code: read an image from a source and write it to a file
    Enrique Marin
    88enrique@gmail.com
*/

#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(){

    // Variables
    VideoCapture capture;
    VideoWriter writer;
    Mat frame;

    // Read from source
    capture.open(0);
    //capture.open("../Videos/chessboard-1.avi");

    // Check if the source was opened correctly
    if (!capture.isOpened()){
        cout << "Cannot open video device or file!" << endl;
        return -1;
    }

    // Read first frame (needed to configure VideoWriter)
    capture.read(frame);
    if (frame.empty()){
        printf("VideoCapture failed getting the first frame!\n");
        return -1;
    }

    // Open a video file for writing and check
    writer.open("./video.avi", CV_FOURCC('D','I','V','X'), 15, frame.size(), true);
    if( !writer.isOpened() ) {
        printf("VideoWriter failed to open!\n");
        return -1;
    }

    // Read the video
    while(true){

        // Read new frame
        capture.read(frame);
        if (frame.empty())
            break;

        // Write frame to a file
        writer.write(frame);

        // Show frame
        imshow("video", frame);

        if ((cvWaitKey(10) & 255) == 27) break;
    }

    // Release memory
    capture.release();
    frame.release();

    return 0;
}
