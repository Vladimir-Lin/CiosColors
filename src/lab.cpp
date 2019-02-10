#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

Lab:: Lab(double l,double A,double B)
{
  L = l ;
  a = A ;
  b = B ;
}

Lab:: Lab(void)
{
  L = 0 ;
  a = 0 ;
  b = 0 ;
}

Lab:: Lab(const Lab & lab)
{
  L = lab . L ;
  a = lab . a ;
  b = lab . b ;
}

Lab:: Lab(const RGBA & rgba)
{
  setRgba ( rgba ) ;
}

Lab:: Lab(const RGBA64 & rgba)
{
  setRgba64 ( rgba ) ;
}

Lab:: Lab(const DoubleRGBA & rgba)
{
  setDouble ( rgba ) ;
}

Lab:: Lab(const LUV & luv)
{
//  setDouble ( DoubleRGBA ( luv ) ) ;
}

Lab:: Lab(const YUV & yuv)
{
//  setDouble ( DoubleRGBA ( yuv ) ) ;
}

Lab:: Lab(const YIQ & yiq)
{
//  setDouble ( DoubleRGBA ( yiq ) ) ;
}

Lab:: Lab(const XYZ & xyz)
{
  setXYZ ( xyz ) ;
}

Lab:: Lab(const uint32_t pixel)
{
}

Lab:: Lab(const uint64_t pixel)
{
}

Lab::~Lab(void)
{
}

double Lab::Forward(double p) const
{ // ( 6 / 29 ) ^ 3 ~ 0.008856
  if ( p > 0.008856 ) return pow     ( p , 1.0 /  3.0 ) ;
  return ( p * ( 841.0 / 108.0 ) ) + (     4.0 / 29.0 ) ;
}

double Lab::Backward(double p) const
{ // 3 * ( 6 / 29 ) * ( 6 / 29 ) = 3 * 36 / 841 = 108 / 841
  if ( p > ( 6.0 / 29.0 ) ) return p * p * p        ;
  return ( p - ( 4.0 / 29.0 ) ) * ( 108.0 / 841.0 ) ;
}

Lab & Lab::setXYZ(const XYZ & xyz)
{
  // L = ( 116 * Forward(Y) ) - 16
  // a = 500 * [ Forward(X) - Forward(Y) ]
  // b = 200 * [ Forward(Y) - Forward(Z) ]
  double X = Forward ( xyz . X /0.95047 ) ; // 0.95047
  double Y = Forward ( xyz . Y          ) ; // 1.00000
  double Z = Forward ( xyz . Z /1.08883 ) ; // 1.08883
  L = ( 116 * Y ) - 16                    ;
  a = 500 * ( X - Y )                     ;
  b = 200 * ( Y - Z )                     ;
  return (*this)                          ;
}

XYZ Lab::toXYZ(void) const
{
  XYZ xyz                            ;
  double Y = ( L + 16.0 ) / 116.0    ;
  double X = Y + ( a / 500.0 )       ;
  double Z = Y - ( b / 200.0 )       ;
  xyz . X = Backward ( X ) * 0.95047 ;
  xyz . Y = Backward ( Y )           ;
  xyz . Z = Backward ( Z ) * 1.08883 ;
  return xyz                         ;
}

Lab & Lab::setRgba(const RGBA & rgba)
{
  setXYZ ( XYZ ( rgba ) ) ;
  return (*this)          ;
}

RGBA Lab::toRGBA(void) const
{
  XYZ xyz = toXYZ ( )     ;
  return xyz . toRGBA ( ) ;
}

Lab & Lab::setRgba64(const RGBA64 & rgba)
{
  setXYZ ( XYZ ( rgba ) ) ;
  return (*this)          ;
}

RGBA64 Lab::toRGBA64(void) const
{
  XYZ xyz = toXYZ ( )       ;
  return xyz . toRGBA64 ( ) ;
}

Lab & Lab::setDouble(const RGBA & rgba)
{
  setXYZ ( XYZ ( rgba ) ) ;
  return (*this)          ;
}

DoubleRGBA Lab::toDouble(void) const
{
  XYZ xyz = toXYZ ( )       ;
  return xyz . toDouble ( ) ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
