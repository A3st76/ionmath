// Copyright © 2020 Dmitriy Lukovenko. All rights reserved.
// Contacts: <mludima23@gmail.com>
// License: http://opensource.org/licenses/MIT

#pragma once

#include "Matrix.h"
#include "Vector.h"

namespace ion
{
	class Quaternion
	{
	public:
		float x;
		float y;
		float z;
		float w;

		inline Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }

		inline Quaternion(const float& x_, const float& y_, const float& z_, const float& w_) : x(x_), y(y_), z(z_), w(w_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z + w * w);
		}

		inline Quaternion normalize() const
		{
			float invLength = 1 / getLength();
			return *this * invLength;
		}

		inline Matrix4 toMat4() const
		{
			Matrix4 mat;
			mat.identity();

			mat[0] = 1.0f - 2 * y * y - 2 * z * z;
			mat[1] = 2 * x * y + 2 * z * w;
			mat[2] = 2 * x * z - 2 * y * w;
			mat[4] = 2 * x * y - 2 * z * w;
			mat[5] = 1.0f - 2 * x * x - 2 * z * z;
			mat[6] = 2 * y * z + 2 * x * w;
			mat[8] = 2 * x * z + 2 * y * w;
			mat[9] = 2 * y * z - 2 * x * w;
			mat[10] = 1.0f - 2 * x * x - 2 * y * y;

			return mat;
		}

		inline const std::string toString() const
		{
			return format("Quaternion (%f; %f; %f; %f)", x, y, z, w);
		}

		inline static Quaternion angleAxis(const float& angle, const Vector3& axis)
		{
			Vector3 normAxis = axis.normalize();
			float rot = std::sinf(angle / 2);
			return Quaternion(normAxis.x * rot, normAxis.y * rot, normAxis.z * rot, std::cosf(angle / 2));
		}

		inline Quaternion operator*(const float& a) const
		{
			return Quaternion(x * a, y * a, z * a, w * a);
		}

		inline Quaternion operator*(const Quaternion& a) const
		{
			Quaternion quat;
			quat.x = w * a.x + x * a.w + y * a.z - z * a.y;
			quat.y = w * a.y - x * a.z + y * a.w + z * a.x;
			quat.z = w * a.z + x * a.y - y * a.x + z * a.w;
			quat.w = w * a.w - x * a.x - y * a.y - z * a.z;
			return quat;
		}
	};
}
