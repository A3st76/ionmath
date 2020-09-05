// Copyright © 2020 Dmitriy Lukovenko. All rights reserved.
// Contacts: <mludima23@gmail.com>
// License: http://opensource.org/licenses/MIT

#pragma once

#include "Matrix.h"
#include "Vector.h"

namespace ion
{
	class Quat
	{
	public:

		float x;
		float y;
		float z;
		float w;

		Quat() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }

		Quat(const float x_, const float y_, const float z_, const float w_) : x(x_), y(y_), z(z_), w(w_) { }

		inline float getLength() const
		{
			return std::sqrtf(x * x + y * y + z * z + w * w);
		}

		inline Quat normalize() const
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
			return format("Quat (%f; %f; %f; %f)", x, y, z, w);
		}

		inline static Quat angleAxis(const float angle, const Vector3& axis)
		{
			Vector3 normAxis = axis.normalize();
			float rot = std::sinf(angle / 2);
			return Quat(normAxis.x * rot, normAxis.y * rot, normAxis.z * rot, std::cosf(angle / 2));
		}

		inline Quat operator*(const float rhs) const
		{
			return Quat(x * rhs, y * rhs, z * rhs, w * rhs);
		}

		inline Quat operator*(const Quat& rhs) const
		{
			Quat quat;
			quat.x = w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y;
			quat.y = w * rhs.y - x * rhs.z + y * rhs.w + z * rhs.x;
			quat.z = w * rhs.z + x * rhs.y - y * rhs.x + z * rhs.w;
			quat.w = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
			return quat;
		}
	};
}
