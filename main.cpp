#include <iostream>
#include "convolution.hpp"

// Library
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
int main()
{
  cv::Mat img = cv::imread("Images.png",  cv::IMREAD_GRAYSCALE);
  if (!img.data)
  {
    std::cout << "Could not find the image!!!\n";
    return 0;
  }
  cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1 ,0,
                                            -1, 4, -1,
                                            0, -1, 0);
  std::cout << kernel << std::endl;
  convolution obj(kernel, 1, type::Zero, 1);

  cv::Mat resImg = obj(img);

  cv::imwrite("convImg.jpg", resImg);
  return 0;
}
