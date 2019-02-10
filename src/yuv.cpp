#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

YUV:: YUV(double y,double u,double v)
{
  Y = y ;
  U = u ;
  V = v ;
}

YUV:: YUV(void)
{
  Y = 0 ;
  U = 0 ;
  V = 0 ;
}

YUV:: YUV(const YUV & yuv)
{
  Y = yuv . Y ;
  U = yuv . U ;
  V = yuv . V ;
}

YUV::~YUV(void)
{
}

YUV & YUV::operator = (const YUV & yuv)
{
  Y = yuv . Y    ;
  U = yuv . U    ;
  V = yuv . V    ;
  return (*this) ;
}

YUV & YUV::setDouble(DoubleRGBA & rgba)
{
  double R = rgba . R                                        ;
  double G = rgba . G                                        ;
  double B = rgba . B                                        ;
  Y = (  0.29900 * R ) + (  0.58700 * G ) + (  0.11400 * B ) ;
  U = ( -0.14713 * R ) + ( -0.28886 * G ) + (  0.43600 * B ) ;
  V = (  0.61500 * R ) + ( -0.51499 * G ) + ( -0.10001 * B ) ;
  return (*this)                                             ;
}

DoubleRGBA YUV::toDouble(void)
{
  DoubleRGBA D                                    ;
  D . R = Y                    + (  1.13983 * V ) ; // R = Y + 1.13983 * V
  D . G = Y + ( -0.39465 * U ) + ( -0.58060 * V ) ; // G = Y - 0.39465 * U - 0.58060 * V
  D . B = Y + (  2.03211 * U )                    ; // B = Y + 2.03211 * U
  D . A = 1.0                                     ;
  return D                                        ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
