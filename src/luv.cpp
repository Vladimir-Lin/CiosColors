#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

LUV:: LUV(double l,double u,double v)
{
  L = l ;
  U = u ;
  V = v ;
}

LUV:: LUV(void)
{
  L = 0 ;
  U = 0 ;
  V = 0 ;
}

LUV:: LUV(const LUV & luv)
{
  L = luv . L ;
  U = luv . U ;
  V = luv . V ;
}

LUV::~LUV(void)
{
}

LUV & LUV::operator = (const LUV & luv)
{
  L = luv . L    ;
  U = luv . U    ;
  V = luv . V    ;
  return (*this) ;
}

LUV & LUV::setXYZ(const XYZ & xyz)
{
  double X = xyz . X                             ; // 0.95047
  double Y = xyz . Y                             ; // 1.00000 , Yd = Y / Yn
  double Z = xyz . Z                             ; // 1.08883
  double S                                       ;
  double u                                       ;
  double v                                       ;
  double un                                      ;
  double vn                                      ;
  if ( Y > 0.008856 )                            { // ( 116 * ( Yd ^ (1/3) ) ) - 16
    L = ( 116.0 * pow ( Y , 1.0 / 3.0 ) ) - 16.0 ;
  } else                                         {
    L = ( 24389.0 / 27.0 ) * Y                   ; // Yd * ( ( 29 / 3 ) ^ 3 )
  }                                              ;
  S  = X + ( 15.0 * Y ) + ( 3 * Z )              ;
  if ( ColorSpace::Equal ( S , 0 ) )             {
    U = 0.0                                      ;
    V = 0.0                                      ;
  } else                                         {
    u  = ( 4 * X ) / S                           ; // u = 4X / ( X + 15Y + 3Z)
    v  = ( 9 * Y ) / S                           ; // v = 9Y / ( X + 15Y + 3Z)
    S  = 0.95047 + 15.0 + ( 3 * 1.08883 )        ;
    un = ( 4 * 0.95047 ) / S                     ;
    vn =   4             / S                     ;
    S  = 13.0 * L                                ;
    U  = S    * ( u - un )                       ;
    V  = S    * ( v - vn )                       ;
  }                                              ;
  return (*this)                                 ;
}

XYZ LUV::toXYZ(void) const
{
  XYZ xyz                                                                ;
  double S = 13 * L                                                      ;
  double u = ( U / S )                                                   ;
  double v = ( V / S )                                                   ;
  double un                                                              ;
  double vn                                                              ;
  S  = 0.95047 + 15.0 + ( 3 * 1.08883 )                                  ;
  un = ( 4 * 0.95047 ) / S                                               ;
  vn =   4             / S                                               ;
  u += un                                                                ;
  v += vn                                                                ;
  if ( L > 8.0 ) xyz . Y = pow ( (L + 16.0) / 116.0 , 3.0 )              ;
            else xyz . Y = L * ( 27.0 / 24389.0           )              ;
  xyz . X = xyz . Y * 2.25 * u / v                                       ;
  xyz . Z = xyz . Y * (12.0 - ( 3.0 * u ) - ( 20.0 * v ) ) / ( 4.0 * v ) ;
  return xyz                                                             ;
}


#ifndef DONT_USE_NAMESPACE
}
#endif
