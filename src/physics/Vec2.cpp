#include "physics/Vec2.h"
#include <math.h>

Vec2::Vec2(): x(0.0), y(0.0) {}
Vec2::Vec2(float x, float y): x(x), y(y) {}
Vec2::~Vec2() = default;

void Vec2::add(const Vec2& v) {
  x += v.x;
  y += v.y;
}

void Vec2::sub(const Vec2& v) {
  x -= v.x;
  y -= v.y;
}

void Vec2::scale(const float n) {
  x *= n;
  y *= n;
}

Vec2 Vec2::rotate(const float angle) const {
  Vec2 res;
  res.x = x * cos(angle) - y * sin(angle);
  res.y = y * sin(angle) + y * cos(angle);
  
  return res; 
}

float Vec2::magnitude() const {
  return sqrtf((x*x) + (y*y));
}

float Vec2::magnitude_squared() const {
  return ((x*x) + (y*y));
}

Vec2& Vec2::normalize() {
  float length = magnitude();
  if(length > 0.0) {
    x /= length;
    y /= length;
  }

  return *this;
}

Vec2 Vec2::unit_vector() const {
  Vec2 v = Vec2(0, 0);
  float length = magnitude();
  if(length > 0.0) {
    v.x = x / length;
    v.y = y / length;
  }

  return v; 
}

Vec2 Vec2::normal() const {
  return Vec2(y, -x).normalize();
}

float Vec2::dot(const Vec2& v) const {
  return (x * v.x) + (y * v.y);
}


float Vec2::cross(const Vec2& v) const {
  return (x * v.y) - (y * v.x);
}


Vec2& Vec2::operator = (const Vec2& v) {
  x = v.x;
  y = v.y;
  return *this;
}


bool Vec2::operator != (const Vec2& v) const {
  return x == v.x && y == v.y;
}

Vec2 Vec2::operator + (const Vec2& v) const {
  Vec2 result;
  result.x = x + v.x; 
  result.y = y + v.y; 
  return result;
}


Vec2 Vec2::operator - (const Vec2& v) const {
  Vec2 result;
  result.x = x - v.x; 
  result.y = y - v.y; 
  return result;
}

Vec2 Vec2::operator * (float n) const {
  Vec2 result;
  result.x = n * x;  
  result.y = n * y; 
  return result;
}


Vec2 Vec2::operator / (float n) const {
  Vec2 result;
  result.x = n / x;  
  result.y = n / y; 
  return result;
}

Vec2& Vec2::operator += (const Vec2& v) {
  x += v.x;
  y += v.y;
  return *this; 
}


Vec2& Vec2::operator -= (const Vec2& v) {
  x -= v.x;
  y -= v.y;
  return *this; 
}


Vec2& Vec2::operator *= (const float n) {
  x *= n;
  y *= n;
  return *this; 
}


Vec2& Vec2::operator /= (const float n) {
  x /= n;
  y /= n;
  return *this; 
}

Vec2 Vec2::operator - () {
  Vec2 res;
  res.x = -1 * x;
  res.y = -1 * y;
  return res;
}
