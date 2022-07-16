#ifndef CONVOLUTION_H
#define CONVOLUTION_H

// Library
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

enum class type
{
  Zero = 0,
  Const
};

struct paddingElem
{
  type padding;
  int value;
};

template <typename T>
class convolution
{
  public:
    convolution(const cv::Mat&, int, type, int) noexcept;
    //~convolution();

    cv::Mat operator()(const cv::Mat& img) noexcept;
  private:
  int m_stride;
  paddingElem m_pad;
  cv::Mat m_kernel;
};

#include "convolution.hpp"
#endif
