#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void matris()
{
    string wName = "Matris";
    namedWindow(wName);
    Mat image(480, 640, CV_8UC3);
    randu(image, Scalar(0, 0, 0), Scalar(255, 255, 255));
    imshow(wName, image);
    waitKey(500);

    Mat redROI(image, Rect(40, 20, image.cols-80, image.rows-40));
    redROI = Scalar(0, 0, 255);
    imshow(wName, image);

    Mat cRedROI = redROI.clone();
    waitKey(500);
    Mat greenROI(redROI, Rect(40, 20, redROI.cols-80, redROI.rows-40));
    greenROI = Scalar(0, 255, 0);
    imshow(wName, greenROI);
    waitKey(500);

    Mat blueROI(greenROI, Rect(40, 20, greenROI.cols-80, greenROI.rows-40));
    blueROI = Scalar(255, 0, 0);
    imshow(wName, blueROI);
    Mat cBlueROI;
    blueROI.copyTo(cBlueROI);
    waitKey(500);

    image.rowRange(125, 165).setTo(Scalar(255, 255, 0));
    image.colRange(195, 240).setTo(Scalar(0, 255, 255));
    imshow(wName, image);
    waitKey(0);
    destroyAllWindows();

    imshow("RedROI", redROI);
    imshow("Clone of RedROI", cRedROI);
    waitKey(0);
    destroyAllWindows();

    imshow("Blue ROI", blueROI);
    imshow("Clone of BlueROI", cBlueROI);
    waitKey(0);
    destroyAllWindows();
}

int main() {
    matris();
    return 0;
}
