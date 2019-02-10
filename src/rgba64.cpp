#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

RGBA64:: RGBA64(uint16_t r,uint16_t g,uint16_t b,uint16_t a)
{
  R = r ;
  G = g ;
  B = b ;
  A = a ;
}

RGBA64:: RGBA64(void)
{
  R =     0 ;
  G =     0 ;
  B =     0 ;
  A = 65535 ;
}

RGBA64:: RGBA64(const RGBA64 & rgba)
{
  R = rgba . R ;
  G = rgba . G ;
  B = rgba . B ;
  A = rgba . A ;
}

RGBA64:: RGBA64(const RGBA & rgba)
{
  R = rgba . R ; R <<= 8 ;
  G = rgba . G ; G <<= 8 ;
  B = rgba . B ; B <<= 8 ;
  A = rgba . A ; A <<= 8 ;
}

RGBA64:: RGBA64(const DoubleRGBA & rgba)
{
  R = uint16_t ( rgba . R * 65535 ) ;
  G = uint16_t ( rgba . G * 65535 ) ;
  B = uint16_t ( rgba . B * 65535 ) ;
  A = uint16_t ( rgba . A * 65535 ) ;
}

RGBA64::~RGBA64(void)
{
}

RGBA64 & RGBA64::operator = (const RGBA64 & rgba)
{
  R = rgba . R   ;
  G = rgba . G   ;
  B = rgba . B   ;
  A = rgba . A   ;
  return (*this) ;
}

RGBA64 & RGBA64::operator = (const RGBA & rgba)
{
  R = rgba . R ; R <<= 8 ;
  G = rgba . G ; G <<= 8 ;
  B = rgba . B ; B <<= 8 ;
  A = rgba . A ; A <<= 8 ;
  return (*this)         ;
}

RGBA64 & RGBA64::operator = (const DoubleRGBA & rgba)
{
  R = uint16_t ( rgba . R * 65535 ) ;
  G = uint16_t ( rgba . G * 65535 ) ;
  B = uint16_t ( rgba . B * 65535 ) ;
  A = uint16_t ( rgba . A * 65535 ) ;
  return (*this)                    ;
}

RGBA64 & RGBA64::setR(uint16_t r)
{
  R = r          ;
  return (*this) ;
}

RGBA64 & RGBA64::setG(uint16_t g)
{
  G = g          ;
  return (*this) ;
}

RGBA64 & RGBA64::setB(uint16_t b)
{
  B = b          ;
  return (*this) ;
}

RGBA64 & RGBA64::setA(uint16_t a)
{
  A = a          ;
  return (*this) ;
}

RGBA64 & RGBA64::setComponent(char C,uint16_t v)
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

uint16_t RGBA64::Value(char C)
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

uint64_t RGBA64::Pixel(void)
{
  uint64_t V        ;
  V  = A ; V <<= 16 ;
  V |= R ; V <<= 16 ;
  V |= G ; V <<= 16 ;
  V |= B            ;
  return V          ;
}

RGBA64 & RGBA64::setPixel(uint64_t v)
{
  B = (uint16_t) ( v & 0xFFFF ) ; v >>= 16 ;
  G = (uint16_t) ( v & 0xFFFF ) ; v >>= 16 ;
  R = (uint16_t) ( v & 0xFFFF ) ; v >>= 16 ;
  A = (uint16_t) ( v & 0xFFFF )            ;
  return (*this)                           ;
}

RGBA RGBA64::toRGBA(void) const
{
  return RGBA ( *this ) ;
}

DoubleRGBA RGBA64::toDouble(void) const
{
  return DoubleRGBA ( *this ) ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
