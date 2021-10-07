#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//Bu fonksyion kırmızı renkleri ayırır
void piksel()
{
    string wName = "Piksel";
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders6_Piksel/visne.jpg");
    Mat cImg = img.clone();
    uchar red, green, blue, bw;

    MatIterator_<Vec3b> it;
    bool grayScale = true;
    bw = 0;

    for (it = cImg.begin<Vec3b>(); it != cImg.end<Vec3b>(); ++it)
    {
        blue = (*it)[0];
        green = (*it)[1];
        red = (*it)[2];

        if (red > 110 && green < 70 && blue < 70)
        {
            if (grayScale)
            {
                bw = (red + green + blue) / 3;
            }
            (*it)[0] = bw;
            (*it)[1] = bw;
            (*it)[2] = bw;
        }
        else
        {
            (*it)[0] = 255;
            (*it)[1] = 255;
            (*it)[2] = 255;
        }
    }
    imshow("Original", img);
    imshow(wName, cImg);
    waitKey(0);
    destroyWindow(wName);
}

//Bu fonksiyon kırmızı yerleri beyaza boyar
void piksel2()
{
    string wName = "Piksel";
    Mat img = imread("/home/berkan/CLionProjects/OpenCV/Ders6_Piksel/visne.jpg");
    Mat cImg = img.clone();
    uchar red, green, blue;

    MatIterator_<Vec3b> it;
    bool grayScale = true;

    for (it = cImg.begin<Vec3b>(); it != cImg.end<Vec3b>(); ++it)
    {
        blue = (*it)[0];
        green = (*it)[1];
        red = (*it)[2];

        if (red > 50 && green < 70 && blue < 70)
        {
            (*it)[0] = 255;
            (*it)[1] = 255;
            (*it)[2] = 255;
        }
    }
    imshow("Original", img);
    imshow(wName, cImg);
    waitKey(0);
    destroyWindow(wName);
}

int main()
{
    piksel2();
    return 0;
}
