#pragma once

class Vec2 {
  public:
    float x; 
    float y;

    Vec2();
    Vec2(float x, float y);
    ~Vec2();

    void add(const Vec2& v);
    void sub(const Vec2& v);
    void scale(const float n);
    Vec2 rotate(const float angle) const;
    
    float magnitude() const;
    float magnitude_squared() const;

    Vec2& normalize();
    Vec2 unit_vector() const;
    Vec2 normal() const;

    float dot(const Vec2& v) const;
    float cross(const Vec2& v) const;

    Vec2& operator = (const Vec2& v);
    bool operator == (const Vec2& v) const;
    bool operator != (const Vec2& v) const;

    Vec2 operator + (const Vec2& v) const;
    Vec2 operator - (const Vec2& v) const;
    Vec2 operator * (const float n) const;
    Vec2 operator / (const float n) const;
    Vec2 operator - ();

    Vec2& operator += (const Vec2& v);
    Vec2& operator -= (const Vec2& v);
    Vec2& operator *= (const float n);
    Vec2& operator /= (const float n);  

};
