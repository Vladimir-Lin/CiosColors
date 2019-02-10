#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

XYZ:: XYZ(double x,double y,double z)
{
  X = x ;
  Y = y ;
  Z = z ;
}

XYZ:: XYZ(void)
{
  X = 0 ;
  Y = 0 ;
  Z = 0 ;
}

XYZ:: XYZ(const XYZ & xyz)
{
  X = xyz . X ;
  Y = xyz . Y ;
  Z = xyz . Z ;
}

XYZ:: XYZ(const RGBA & rgba)
{
  setRgba ( rgba ) ;
}

XYZ:: XYZ(const RGBA64 & rgba)
{
  setRgba64 ( rgba ) ;
}

XYZ:: XYZ(const DoubleRGBA & rgba)
{
  setDouble ( rgba ) ;
}

XYZ:: XYZ(const Lab & lab)
{
  (*this) = lab . toXYZ ( ) ;
}

XYZ::~XYZ(void)
{
}

XYZ & XYZ::operator = (const XYZ & xyz)
{
  X = xyz . X    ;
  Y = xyz . Y    ;
  Z = xyz . Z    ;
  return (*this) ;
}

XYZ & XYZ::setRgba(const RGBA & rgba)
{
  DoubleRGBA D = rgba    ;
  return setDouble ( D ) ;
}

XYZ & XYZ::setRgba64(const RGBA64 & rgba)
{
  DoubleRGBA D ( rgba )  ;
  return setDouble ( D ) ;
}

XYZ & XYZ::setDouble(const DoubleRGBA & rgba)
{
  double R = Gamma( rgba . R )                         ;
  double G = Gamma( rgba . G )                         ;
  double B = Gamma( rgba . B )                         ;
  X = ( 0.4124 * R ) + ( 0.3576 * G ) + ( 0.1805 * B ) ;
  Y = ( 0.2126 * R ) + ( 0.7152 * G ) + ( 0.0722 * B ) ;
  Z = ( 0.0193 * R ) + ( 0.1192 * G ) + ( 0.9505 * B ) ;
  return (*this)                                       ;
}

RGBA XYZ::toRGBA(void) const
{
  DoubleRGBA D = toDouble ( ) ;
  return D . toRGBA ( )       ;
}

RGBA64 XYZ::toRGBA64(void) const
{
  DoubleRGBA D = toDouble ( ) ;
  return D . toRGBA64     ( ) ;
}

DoubleRGBA XYZ::toDouble(void) const
{
  DoubleRGBA D                                                ;
  double     R                                                ;
  double     G                                                ;
  double     B                                                ;
  R     = (  3.2406 * X ) + ( -1.5372 * Y ) + ( -0.4986 * Z ) ;
  G     = ( -0.9689 * X ) + (  1.8758 * Y ) + (  0.0415 * Z ) ;
  B     = (  0.0557 * X ) + ( -0.2040 * Y ) + (  1.0570 * Z ) ;
  D . R = invertGamma ( R )                                   ;
  D . G = invertGamma ( G )                                   ;
  D . B = invertGamma ( B )                                   ;
  D . A = 1.0                                                 ;
  return D                                                    ;
}

double XYZ::Gamma(double v) const
{
  double g                                                 ;
  if ( v > 0.04045 ) g = pow ( (v + 0.055) / 1.055 , 2.4 ) ;
                else g = v / 12.92                         ;
  return g                                                 ;
}

double XYZ::invertGamma(double r) const
{
  double g                                                        ;
  if ( r > 0.0031308) g = ( 1.055 * pow ( r , 1.0/2.4 ) ) - 0.055 ;
                 else g = 12.92 * r                               ;
  return g                                                        ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
