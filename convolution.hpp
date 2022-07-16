
// Library
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

template <typename T>
convolution<T>::convolution(const cv::Mat& kernel, int stride, type padding, int value) noexcept
	: m_kernel(kernel.clone())
  	, m_stride(stride)
  	, m_pad {padding, value}
{
}

//convolution::~convolution() {};
template <typename T>
cv::Mat convolution<T>::operator()(const cv::Mat& img) noexcept
{
  cv::Mat padded;
  padded = cv::Mat::zeros(img.rows + 1, img.cols + 1, CV_8UC1);
  img.copyTo(padded(cv::Rect(1, 1, img.cols, img.rows)));
  cv::Mat convImg = padded.clone();

  for(int i = 0; i < padded.rows; ++i)
  {
    for(int j = 0; j < padded.cols; ++j)
    {
      int sum = 0;
      for(int p = 0; p < m_kernel.rows; ++p)
      {
        for(int q = 0; q < m_kernel.cols; ++q)
        {
          sum += m_kernel.at<uchar>(p, q) * padded.at<uchar>(i + p, j + q);
        }
      }
      convImg.at<uchar>(i, j) = sum;
    }
  }
  return convImg;
}
