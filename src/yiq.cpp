#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

YIQ:: YIQ(double y,double i,double q)
{
  Y = y ;
  I = i ;
  Q = q ;
}

YIQ:: YIQ(void)
{
  Y = 0 ;
  I = 0 ;
  Q = 0 ;
}

YIQ:: YIQ(const YIQ & yiq)
{
  Y = yiq . Y ;
  I = yiq . I ;
  Q = yiq . Q ;
}

YIQ::YIQ (const uint32_t pixel)
{
}

YIQ::~YIQ(void)
{
}

YIQ & YIQ::operator = (const YIQ & yiq)
{
  Y = yiq . Y    ;
  I = yiq . I    ;
  Q = yiq . Q    ;
  return (*this) ;
}

YIQ & YIQ::setDouble(DoubleRGBA & rgba)
{
  double R = rgba . R                                           ;
  double G = rgba . G                                           ;
  double B = rgba . B                                           ;
  Y = (  0.299000 * R ) + (  0.587000 * G ) + (  0.114000 * B ) ;
  I = (  0.595716 * R ) + ( -0.274453 * G ) + ( -0.321263 * B ) ;
  Q = (  0.211456 * R ) + ( -0.522591 * G ) + (  0.311135 * B ) ;
  return (*this)                                                ;
}

DoubleRGBA YIQ::toDouble(void)
{
  DoubleRGBA D                                  ;
  D . R = Y + (  0.9563 * I ) + (  0.6210 * Q ) ;
  D . G = Y + ( -0.2721 * I ) + ( -0.6474 * Q ) ;
  D . B = Y + ( -1.1070 * I ) + (  1.7046 * Q ) ;
  D . A = 1.0                                   ;
  return D                                      ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
