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

		Vector2() : x(0.0f), y(0.0f) { }

		Vector2(const float x_, const float y_) : x(x_), y(y_) { }

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

		inline Vector2 operator*(const float rhs) const
		{
			return Vector2(x * rhs, y * rhs);
		}

		inline Vector2 operator-(const Vector2& rhs) const
		{
			return Vector2(x - rhs.x, y - rhs.y);
		}

		inline Vector2 operator-(const float rhs) const
		{
			return Vector2(x - rhs, y - rhs);
		}

		inline Vector2 operator+(const Vector2& rhs) const
		{
			return Vector2(x + rhs.x, y + rhs.y);
		}

		inline Vector2 operator+(const float rhs) const
		{
			return Vector2(x + rhs, y + rhs);
		}

		inline Vector2 operator/(const float rhs) const
		{
			return Vector2(x / rhs, y / rhs);
		}
	};

	class Vector3
	{
	public:

		float x;
		float y;
		float z;

		Vector3() : x(0.0f), y(0.0f), z(0.0f) { }

		Vector3(const float x_, const float y_, const float z_) : x(x_), y(y_), z(z_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z);
		}

		inline Vector3 normalize() const
		{
			float invLength = 1.0f / getLength();
			return *this * invLength;
		}

		inline float dot(const Vector3& rhs) const
		{
			return x * rhs.x + y * rhs.y + z * rhs.z;
		}

		inline Vector3 cross(const Vector3& rhs) const
		{
			return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
		}

		inline const std::string toString() const
		{
			return format("Vector2 (%f; %f; %f)", x, y, z);
		}

		inline Vector3 operator*(const float rhs) const
		{
			return Vector3(x * rhs, y * rhs, z * rhs);
		}

		inline Vector3 operator-(const Vector3& rhs) const
		{
			return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		inline Vector3 operator-(const float rhs) const
		{
			return Vector3(x - rhs, y - rhs, z - rhs);
		}

		inline Vector3 operator+(const Vector3& rhs) const
		{
			return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		inline Vector3 operator+(const float rhs) const
		{
			return Vector3(x + rhs, y + rhs, z + rhs);
		}

		inline Vector3 operator/(const float rhs) const
		{
			return Vector3(x / rhs, y / rhs, z / rhs);
		}
	};

	class Vector4
	{
	public:

		float x;
		float y;
		float z;
		float w;

		Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }

		Vector4(const float x_, const float y_, const float z_, const float w_) : x(x_), y(y_), z(z_), w(w_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z + w * w);
		}

		inline const std::string toString() const
		{
			return format("Vector2 (%f; %f; %f; %f)", x, y, z, w);
		}

		inline Vector4 operator*(const float rhs) const
		{
			return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
		}

		inline Vector4 operator-(const Vector4& rhs) const
		{
			return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		inline Vector4 operator-(const float rhs) const
		{
			return Vector4(x - rhs, y - rhs, z - rhs, w - rhs);
		}

		inline Vector4 operator+(const Vector4& rhs) const
		{
			return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		inline Vector4 operator+(const float rhs) const
		{
			return Vector4(x + rhs, y + rhs, z + rhs, w + rhs);
		}

		inline Vector4 operator/(const float rhs) const
		{
			return Vector4(x / rhs, y / rhs, z / rhs, w / rhs);
		}
	};
}
