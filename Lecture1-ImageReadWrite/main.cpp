#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void ImageRead()
{
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders1-GoruntuOkumaYazma/okyanus.jpg");

    if (img.data)
    {
        namedWindow("Okyanus");
        imshow("Okyanus", img);
        waitKey(0);
        destroyAllWindows();
    }
    else
    {
        cout << "Image not opened" << endl;
    }
}

int main()
{
    ImageRead();
    return 0;
}
