#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

DoubleRGBA:: DoubleRGBA(double r,double g,double b,double a)
{
  R = r ;
  G = g ;
  B = b ;
  A = a ;
}

DoubleRGBA:: DoubleRGBA(void)
{
  R = 0.0 ;
  G = 0.0 ;
  B = 0.0 ;
  A = 1.0 ;
}

DoubleRGBA:: DoubleRGBA(const DoubleRGBA & rgba)
{
  R = rgba . R ;
  G = rgba . G ;
  B = rgba . B ;
  A = rgba . A ;
}

DoubleRGBA:: DoubleRGBA(const RGBA & rgba)
{
  R = rgba . R ; R /= 255 ;
  G = rgba . G ; G /= 255 ;
  B = rgba . B ; B /= 255 ;
  A = rgba . A ; A /= 255 ;
}

DoubleRGBA:: DoubleRGBA(const RGBA64 & rgba)
{
  R = rgba . R ; R /= 65535 ;
  G = rgba . G ; G /= 65535 ;
  B = rgba . B ; B /= 65535 ;
  A = rgba . A ; A /= 65535 ;
}

DoubleRGBA::~DoubleRGBA(void)
{
}

DoubleRGBA & DoubleRGBA::operator = (const DoubleRGBA & rgba)
{
  R = rgba . R   ;
  G = rgba . G   ;
  B = rgba . B   ;
  A = rgba . A   ;
  return (*this) ;
}

DoubleRGBA & DoubleRGBA::operator = (const RGBA & rgba)
{
  R = rgba . R ; R /= 255 ;
  G = rgba . G ; G /= 255 ;
  B = rgba . B ; B /= 255 ;
  A = rgba . A ; A /= 255 ;
  return (*this)          ;
}

DoubleRGBA & DoubleRGBA::operator = (const RGBA64 & rgba)
{
  R = rgba . R ; R /= 65535 ;
  G = rgba . G ; G /= 65535 ;
  B = rgba . B ; B /= 65535 ;
  A = rgba . A ; A /= 65535 ;
  return (*this)            ;
}

DoubleRGBA & DoubleRGBA::setR(double r)
{
  R = r          ;
  return (*this) ;
}

DoubleRGBA & DoubleRGBA::setG(double g)
{
  G = g          ;
  return (*this) ;
}

DoubleRGBA & DoubleRGBA::setB(double b)
{
  B = b          ;
  return (*this) ;
}

DoubleRGBA & DoubleRGBA::setA(double a)
{
  A = a          ;
  return (*this) ;
}

DoubleRGBA & DoubleRGBA::setComponent(char C,double v)
{
  if ( ( C >= 'A' ) && ( C <= 'Z' ) ) {
    C += 'a' - 'A'                    ;
  }                                   ;
  if ( 'r' == C ) R = v               ;
  if ( 'g' == C ) G = v               ;
  if ( 'b' == C ) B = v               ;
  if ( 'a' == C ) A = v               ;
  return (*this)                      ;
}

double DoubleRGBA::Value(char C)
{
  if ( ( C >= 'A' ) && ( C <= 'Z' ) ) {
    C += 'a' - 'A'                    ;
  }                                   ;
  if ( 'r' == C ) return R            ;
  if ( 'g' == C ) return G            ;
  if ( 'b' == C ) return B            ;
  if ( 'a' == C ) return A            ;
  return 0                            ;
}

RGBA DoubleRGBA::toRGBA(void) const
{
  return RGBA ( *this ) ;
}

RGBA64 DoubleRGBA::toRGBA64(void) const
{
  return RGBA ( *this ) ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
