// Copyright © 2019-2020 Dmitriy Lukovenko. All rights reserved.
// Contacts: <mludima23@gmail.com>
// License: http://opensource.org/licenses/MIT

#pragma once

#include "String.h"

namespace ion
{
	class Vector2
	{
	public:
		float x;
		float y;

		inline Vector2() : x(0.0f), y(0.0f) { }

		inline Vector2(const float& x_, const float& y_) : x(x_), y(y_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y);
		}

		inline Vector2 normalize() const
		{
			float invLength = 1.0f / getLength();
			return *this * invLength;
		}

		inline const std::string toString() const
		{
			return format("Vector2 (%f; %f)", x, y);
		}

		inline Vector2 operator*(const float& a) const
		{
			return Vector2(x * a, y * a);
		}

		inline Vector2 operator-(const Vector2& a) const
		{
			return Vector2(x - a.x, y - a.y);
		}

		inline Vector2 operator-(const float& a) const
		{
			return Vector2(x - a, y - a);
		}

		inline Vector2 operator+(const Vector2& a) const
		{
			return Vector2(x + a.x, y + a.y);
		}

		inline Vector2 operator+(const float& a) const
		{
			return Vector2(x + a, y + a);
		}

		inline Vector2 operator/(const float& a) const
		{
			return Vector2(x / a, y / a);
		}
	};

	class Vector3
	{
	public:
		float x;
		float y;
		float z;

		inline Vector3() : x(0.0f), y(0.0f), z(0.0f) { }

		inline Vector3(const float& x_, const float& y_, const float& z_) : x(x_), y(y_), z(z_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z);
		}

		inline Vector3 normalize() const
		{
			float invLength = 1.0f / getLength();
			return *this * invLength;
		}

		inline float dot(const Vector3& a) const
		{
			return x * a.x + y * a.y + z * a.z;
		}

		inline Vector3 cross(const Vector3& a) const
		{
			return Vector3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
		}

		inline const std::string toString() const
		{
			return format("Vector2 (%f; %f; %f)", x, y, z);
		}

		inline Vector3 operator*(const float& a) const
		{
			return Vector3(x * a, y * a, z * a);
		}

		inline Vector3 operator-(const Vector3& a) const
		{
			return Vector3(x - a.x, y - a.y, z - a.z);
		}

		inline Vector3 operator-(const float& a) const
		{
			return Vector3(x - a, y - a, z - a);
		}

		inline Vector3 operator+(const Vector3& a) const
		{
			return Vector3(x + a.x, y + a.y, z + a.z);
		}

		inline Vector3 operator+(const float& a) const
		{
			return Vector3(x + a, y + a, z + a);
		}

		inline Vector3 operator/(const float& a) const
		{
			return Vector3(x / a, y / a, z / a);
		}
	};

	class Vector4
	{
	public:
		float x;
		float y;
		float z;
		float w;

		inline Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }

		inline Vector4(const float& x_, const float& y_, const float& z_, const float& w_) : x(x_), y(y_), z(z_), w(w_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z + w * w);
		}

		inline const std::string toString() const
		{
			return format("Vector2 (%f; %f; %f; %f)", x, y, z, w);
		}

		inline Vector4 operator*(const float& a) const
		{
			return Vector4(x * a, y * a, z * a, w * a);
		}

		inline Vector4 operator-(const Vector4& a) const
		{
			return Vector4(x - a.x, y - a.y, z - a.z, w - a.w);
		}

		inline Vector4 operator-(const float& a) const
		{
			return Vector4(x - a, y - a, z - a, w - a);
		}

		inline Vector4 operator+(const Vector4& a) const
		{
			return Vector4(x + a.x, y + a.y, z + a.z, w + a.w);
		}

		inline Vector4 operator+(const float& a) const
		{
			return Vector4(x + a, y + a, z + a, w + a);
		}

		inline Vector4 operator/(const float& a) const
		{
			return Vector4(x / a, y / a, z / a, w / a);
		}
	};
}
