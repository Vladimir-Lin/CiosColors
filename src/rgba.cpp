#include "colors.hpp"
#include "stdlib.h"
#include "math.h"

#pragma pack(push,1)


#pragma pack(pop)

#ifndef DONT_USE_NAMESPACE
namespace COLORS_NAMESPACE {
#endif

RGBA:: RGBA(uint8_t r,uint8_t g,uint8_t b,uint8_t a)
{
  R = r ;
  G = g ;
  B = b ;
  A = a ;
}

RGBA:: RGBA(void)
{
  R =   0 ;
  G =   0 ;
  B =   0 ;
  A = 255 ;
}

RGBA:: RGBA(const RGBA & rgba)
{
  R = rgba . R ;
  G = rgba . G ;
  B = rgba . B ;
  A = rgba . A ;
}

RGBA:: RGBA(const RGBA64 & rgba)
{
  R = uint8_t ( rgba . R >> 8 ) ;
  G = uint8_t ( rgba . G >> 8 ) ;
  B = uint8_t ( rgba . B >> 8 ) ;
  A = uint8_t ( rgba . A >> 8 ) ;
}

RGBA:: RGBA(const DoubleRGBA & rgba)
{
  R = uint8_t ( rgba . R * 255 ) ;
  G = uint8_t ( rgba . G * 255 ) ;
  B = uint8_t ( rgba . B * 255 ) ;
  A = uint8_t ( rgba . A * 255 ) ;
}

RGBA:: RGBA(const XYZ & xyz)
{
  (*this) = xyz . toRGBA ( ) ;
}

RGBA:: RGBA(const Lab & lab)
{
  (*this) = lab . toRGBA ( ) ;
}

RGBA:: RGBA(const uint32_t pixel)
{
  setPixel ( pixel ) ;
}

RGBA:: RGBA(const uint64_t pixel)
{
  setPixel ( pixel ) ;
}

RGBA::~RGBA(void)
{
}

RGBA & RGBA::operator = (const RGBA & rgba)
{
  R = rgba . R   ;
  G = rgba . G   ;
  B = rgba . B   ;
  A = rgba . A   ;
  return (*this) ;
}

RGBA & RGBA::operator = (const RGBA64 & rgba)
{
  R = uint8_t ( rgba . R >> 8 ) ;
  G = uint8_t ( rgba . G >> 8 ) ;
  B = uint8_t ( rgba . B >> 8 ) ;
  A = uint8_t ( rgba . A >> 8 ) ;
  return      ( *this         ) ;
}

RGBA & RGBA::operator = (const DoubleRGBA & rgba)
{
  R = uint8_t ( rgba . R * 255 ) ;
  G = uint8_t ( rgba . G * 255 ) ;
  B = uint8_t ( rgba . B * 255 ) ;
  A = uint8_t ( rgba . A * 255 ) ;
  return      ( *this          ) ;
}

RGBA & RGBA::operator = (const XYZ & xyz)
{
  (*this) = xyz . toRGBA ( ) ;
  return ( *this )           ;
}

RGBA & RGBA::operator = (const Lab & lab)
{
  (*this) = lab . toRGBA ( ) ;
  return ( *this )           ;
}

RGBA & RGBA::setR(uint8_t r)
{
  R = r          ;
  return (*this) ;
}

RGBA & RGBA::setG(uint8_t g)
{
  G = g          ;
  return (*this) ;
}

RGBA & RGBA::setB(uint8_t b)
{
  B = b          ;
  return (*this) ;
}

RGBA & RGBA::setA(uint8_t a)
{
  A = a          ;
  return (*this) ;
}

RGBA & RGBA::setComponent(char C,uint8_t v)
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

uint8_t RGBA::Value(char C)
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

uint32_t RGBA::toPixel(void)
{
  uint32_t V       ;
  V  = A ; V <<= 8 ;
  V |= R ; V <<= 8 ;
  V |= G ; V <<= 8 ;
  V |= B           ;
  return V         ;
}

RGBA & RGBA::setPixel(uint32_t v)
{
  B = (uint8_t) ( v & 0xFF ) ; v >>= 8 ;
  G = (uint8_t) ( v & 0xFF ) ; v >>= 8 ;
  R = (uint8_t) ( v & 0xFF ) ; v >>= 8 ;
  A = (uint8_t) ( v & 0xFF )           ;
  return (*this)                       ;
}

RGBA & RGBA::setPixel(uint64_t v)
{
  B = (uint8_t) ( ( v & 0xFFFF ) >> 8 ) ; v >>= 16 ;
  G = (uint8_t) ( ( v & 0xFFFF ) >> 8 ) ; v >>= 16 ;
  R = (uint8_t) ( ( v & 0xFFFF ) >> 8 ) ; v >>= 16 ;
  A = (uint8_t) ( ( v & 0xFFFF ) >> 8 )            ;
  return (*this)                                   ;
}

RGBA64 RGBA::toRGBA64(void) const
{
  return RGBA64 ( *this ) ;
}

DoubleRGBA RGBA::toDouble(void) const
{
  return DoubleRGBA ( *this ) ;
}

#ifndef DONT_USE_NAMESPACE
}
#endif
