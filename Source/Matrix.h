// Copyright © 2019-2020 Dmitriy Lukovenko. All rights reserved.
// Contacts: <mludima23@gmail.com>
// License: http://opensource.org/licenses/MIT

#pragma once

#include "String.h"
#include "Vector.h"

namespace ion
{
	class Matrix4
	{
	public:
		Matrix4() : mat_{ } { }

		Matrix4(
			const float xx_, const float xy_, const float xz_, const float xw_,
			const float yx_, const float yy_, const float yz_, const float yw_,
			const float zx_, const float zy_, const float zz_, const float zw_,
			const float wx_, const float wy_, const float wz_, const float ww_) : mat_{
				xx_, xy_, xz_, xw_,
				yx_, yy_, yz_, yw_,
				zx_, zy_, zz_, zw_,
				wx_, wy_, wz_, ww_ } { }

		inline void identity()
		{
			mat_[0] = 1.0f;	mat_[5] = 1.0f;	mat_[10] = 1.0f; mat_[15] = 1.0f;
		}

		inline void transpose()
		{
			Matrix4 mat = *this;
			mat_[0] = mat[0]; mat_[4] = mat[1]; mat_[8] = mat[2]; mat_[12] = mat[3];
			mat_[1] = mat[4]; mat_[5] = mat[5]; mat_[9] = mat[6]; mat_[13] = mat[7];
			mat_[2] = mat[8]; mat_[6] = mat[9]; mat_[10] = mat[10]; mat_[14] = mat[11];
			mat_[3] = mat[12]; mat_[7] = mat[13]; mat_[11] = mat[14]; mat_[15] = mat[15];
		}

		inline const float* toArray() const
		{
			return mat_.data();
		}

		inline const std::string toString() const
		{
			return format("Matrix4 ((%f; %f; %f; %f), (%f; %f; %f; %f), (%f; %f; %f; %f), (%f; %f; %f; %f))",
				mat_[0], mat_[1], mat_[2], mat_[3],
				mat_[4], mat_[5], mat_[6] , mat_[7],
				mat_[8], mat_[9], mat_[10], mat_[11],
				mat_[12], mat_[13], mat_[14], mat_[15]);
		}

		inline Matrix4 operator*(const Matrix4& rhs) const
		{
			Matrix4 mat;

			mat[0] = mat_[0] * rhs.mat_[0] + mat_[1] * rhs.mat_[4] + mat_[2] * rhs.mat_[8] + mat_[3] * rhs.mat_[12];
			mat[1] = mat_[0] * rhs.mat_[1] + mat_[1] * rhs.mat_[5] + mat_[2] * rhs.mat_[9] + mat_[3] * rhs.mat_[13];
			mat[2] = mat_[0] * rhs.mat_[2] + mat_[1] * rhs.mat_[6] + mat_[2] * rhs.mat_[10] + mat_[3] * rhs.mat_[14];
			mat[3] = mat_[0] * rhs.mat_[3] + mat_[1] * rhs.mat_[7] + mat_[2] * rhs.mat_[11] + mat_[3] * rhs.mat_[15];
			mat[4] = mat_[4] * rhs.mat_[0] + mat_[5] * rhs.mat_[4] + mat_[6] * rhs.mat_[8] + mat_[7] * rhs.mat_[12];
			mat[5] = mat_[4] * rhs.mat_[1] + mat_[5] * rhs.mat_[5] + mat_[6] * rhs.mat_[9] + mat_[7] * rhs.mat_[13];
			mat[6] = mat_[4] * rhs.mat_[2] + mat_[5] * rhs.mat_[6] + mat_[6] * rhs.mat_[10] + mat_[7] * rhs.mat_[14];
			mat[7] = mat_[4] * rhs.mat_[3] + mat_[5] * rhs.mat_[7] + mat_[6] * rhs.mat_[11] + mat_[7] * rhs.mat_[15];
			mat[8] = mat_[8] * rhs.mat_[0] + mat_[9] * rhs.mat_[4] + mat_[10] * rhs.mat_[8] + mat_[11] * rhs.mat_[12];
			mat[9] = mat_[8] * rhs.mat_[1] + mat_[9] * rhs.mat_[5] + mat_[10] * rhs.mat_[9] + mat_[11] * rhs.mat_[13];
			mat[10] = mat_[8] * rhs.mat_[2] + mat_[9] * rhs.mat_[6] + mat_[10] * rhs.mat_[10] + mat_[11] * rhs.mat_[14];
			mat[11] = mat_[8] * rhs.mat_[3] + mat_[9] * rhs.mat_[7] + mat_[10] * rhs.mat_[11] + mat_[11] * rhs.mat_[15];
			mat[12] = mat_[12] * rhs.mat_[0] + mat_[13] * rhs.mat_[4] + mat_[14] * rhs.mat_[8] + mat_[15] * rhs.mat_[12];
			mat[13] = mat_[12] * rhs.mat_[1] + mat_[13] * rhs.mat_[5] + mat_[14] * rhs.mat_[9] + mat_[15] * rhs.mat_[13];
			mat[14] = mat_[12] * rhs.mat_[2] + mat_[13] * rhs.mat_[6] + mat_[14] * rhs.mat_[10] + mat_[15] * rhs.mat_[14];
			mat[15] = mat_[12] * rhs.mat_[3] + mat_[13] * rhs.mat_[7] + mat_[14] * rhs.mat_[11] + mat_[15] * rhs.mat_[15];

			return mat;
		}

		inline Matrix4 operator*(const Vector4& rhs) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] * rhs.x; mat[1] = mat_[1] * rhs.y; mat[2] = mat_[2] * rhs.z; mat[3] = mat_[3] * rhs.w;
			mat[4] = mat_[4] * rhs.x; mat[5] = mat_[5] * rhs.y; mat[6] = mat_[6] * rhs.z; mat[7] = mat_[7] * rhs.w;
			mat[8] = mat_[8] * rhs.x; mat[9] = mat_[9] * rhs.y; mat[10] = mat_[10] * rhs.z; mat[11] = mat_[11] * rhs.w;
			mat[12] = mat_[12] * rhs.x; mat[13] = mat_[13] * rhs.y; mat[14] = mat_[14] * rhs.z; mat[15] = mat_[15] * rhs.w;
			return mat;
		}

		inline Matrix4 operator+(const Matrix4& rhs) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] + rhs.mat_[0]; mat[1] = mat_[1] + rhs.mat_[1]; mat[2] = mat_[2] + rhs.mat_[2]; mat[3] = mat_[3] + rhs.mat_[3];
			mat[4] = mat_[4] + rhs.mat_[4]; mat[5] = mat_[5] + rhs.mat_[5]; mat[6] = mat_[6] + rhs.mat_[6]; mat[7] = mat_[7] + rhs.mat_[7];
			mat[8] = mat_[8] + rhs.mat_[8]; mat[9] = mat_[9] + rhs.mat_[9]; mat[10] = mat_[10] + rhs.mat_[10]; mat[11] = mat_[11] + rhs.mat_[11];
			mat[12] = mat_[12] + rhs.mat_[12]; mat[13] = mat_[13] + rhs.mat_[13]; mat[14] = mat_[14] + rhs.mat_[14]; mat[15] = mat_[15] + rhs.mat_[15];
			return mat;
		}

		inline Matrix4 operator-(const Matrix4& rhs) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] - rhs.mat_[0]; mat[1] = mat_[1] - rhs.mat_[1]; mat[2] = mat_[2] - rhs.mat_[2]; mat[3] = mat_[3] - rhs.mat_[3];
			mat[4] = mat_[4] - rhs.mat_[4]; mat[5] = mat_[5] - rhs.mat_[5]; mat[6] = mat_[6] - rhs.mat_[6]; mat[7] = mat_[7] - rhs.mat_[7];
			mat[8] = mat_[8] - rhs.mat_[8]; mat[9] = mat_[9] - rhs.mat_[9]; mat[10] = mat_[10] - rhs.mat_[10]; mat[11] = mat_[11] - rhs.mat_[11];
			mat[12] = mat_[12] - rhs.mat_[12]; mat[13] = mat_[13] - rhs.mat_[13]; mat[14] = mat_[14] - rhs.mat_[14]; mat[15] = mat_[15] - rhs.mat_[15];
			return mat;
		}

		inline float& operator[](const int index)
		{
			return mat_[index];
		}

		static inline Matrix4 translate(const Vector3& rhs)
		{
			Matrix4 mat;
			mat.identity();
			mat[12] = rhs.x; mat[13] = rhs.y; mat[14] = rhs.z;
			return mat;
		}

		static inline Matrix4 scale(const Vector3& rhs)
		{
			Matrix4 mat;
			mat.identity();
			mat[0] = rhs.x; mat[5] = rhs.y; mat[10] = rhs.z;
			return mat;
		}

		static inline Matrix4 perspective(const float fovy, const float aspect, const float nearDst, const float farDst)
		{
			Matrix4 mat;
			mat[0] = 1.0f / (std::tanf(fovy / 2) * aspect); mat[5] = 1.0f / std::tanf(fovy / 2);
			mat[10] = (farDst + nearDst) / (nearDst - farDst); mat[11] = -1.0f;
			mat[14] = (2 * nearDst * farDst) / (nearDst - farDst);
			return mat;
		}

		static inline Matrix4 orthographic(const float left, const float right, const float bottom, const float top, const float nearDst, const float farDst)
		{
			Matrix4 mat;
			mat[0] = 2.0f / (right - left);
			mat[5] = 2.0f / (top - bottom);
			mat[10] = -2.0f / (farDst - nearDst);
			mat[12] = -(right + left) / (right - left);
			mat[13] = -(top + bottom) / (top - bottom);
			mat[14] = -(farDst + nearDst) / (farDst - nearDst);
			mat[15] = 1.0f;
			return mat;
		}

		static inline Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
		{
			Vector3 z(eye - target);
			z = z.normalize();

			Vector3 x(up.cross(z));
			x = x.normalize();

			Vector3 y(z.cross(x));

			Matrix4 mat;
			mat.identity();
			mat[0] = x.x; mat[4] = x.y; mat[8] = x.z;
			mat[1] = y.x; mat[5] = y.y;	mat[9] = y.z;
			mat[2] = z.x; mat[6] = z.y;	mat[10] = z.z;
			mat[12] = -x.dot(eye); mat[13] = -y.dot(eye); mat[14] = -z.dot(eye);
			return mat;
		}

	private:

		std::array<float, 16> mat_;
	};

	class Matrix3
	{
	public:
		Matrix3() : mat_{ } { }

		Matrix3(
			const float xx_, const float xy_, const float xz_,
			const float yx_, const float yy_, const float yz_,
			const float zx_, const float zy_, const float zz_) : mat_{
				xx_, xy_, xz_,
				yx_, yy_, yz_,
				zx_, zy_, zz_ } { }

		inline void identity()
		{
			mat_[0] = 1.0f; mat_[4] = 1.0f; mat_[8] = 1.0f;
		}

		inline void transpose()
		{
			Matrix3 mat = *this;
			mat_[0] = mat[0]; mat_[3] = mat[1]; mat_[6] = mat[2];
			mat_[1] = mat[3]; mat_[4] = mat[4]; mat_[7] = mat[5];
			mat_[2] = mat[6]; mat_[5] = mat[7]; mat_[8] = mat[8];
		}

		inline const float* toArray() const
		{
			return mat_.data();
		}

		inline const std::string toString() const
		{
			return format("Matrix3 ((%f; %f; %f), (%f; %f; %f), (%f; %f; %f), (%f; %f; %f))",
				mat_[0], mat_[1], mat_[2],
				mat_[3], mat_[4], mat_[5],
				mat_[6], mat_[7], mat_[8]);
		}

		inline Matrix3 operator*(const Matrix3& rhs) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] * rhs.mat_[0] + mat_[1] * rhs.mat_[3] + mat_[2] * rhs.mat_[6];
			mat[1] = mat_[0] * rhs.mat_[1] + mat_[1] * rhs.mat_[4] + mat_[2] * rhs.mat_[7];
			mat[2] = mat_[0] * rhs.mat_[2] + mat_[1] * rhs.mat_[5] + mat_[2] * rhs.mat_[8];
			mat[3] = mat_[3] * rhs.mat_[0] + mat_[4] * rhs.mat_[3] + mat_[5] * rhs.mat_[6];
			mat[4] = mat_[3] * rhs.mat_[1] + mat_[4] * rhs.mat_[4] + mat_[5] * rhs.mat_[7];
			mat[5] = mat_[3] * rhs.mat_[2] + mat_[4] * rhs.mat_[5] + mat_[5] * rhs.mat_[8];
			mat[6] = mat_[6] * rhs.mat_[0] + mat_[7] * rhs.mat_[3] + mat_[8] * rhs.mat_[6];
			mat[7] = mat_[6] * rhs.mat_[1] + mat_[7] * rhs.mat_[4] + mat_[8] * rhs.mat_[7];
			mat[8] = mat_[6] * rhs.mat_[2] + mat_[7] * rhs.mat_[5] + mat_[8] * rhs.mat_[8];
			return mat;
		}

		inline Matrix3 operator*(const Vector3& rhs) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] * rhs.x; mat[1] = mat_[1] * rhs.y; mat[2] = mat_[2] * rhs.z;
			mat[3] = mat_[3] * rhs.x; mat[4] = mat_[4] * rhs.y; mat[5] = mat_[5] * rhs.z;
			mat[6] = mat_[6] * rhs.x; mat[7] = mat_[7] * rhs.y; mat[8] = mat_[8] * rhs.z;
			return mat;
		}

		inline Matrix3 operator+(const Matrix3& rhs) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] + rhs.mat_[0]; mat[1] = mat_[1] + rhs.mat_[1]; mat[2] = mat_[2] + rhs.mat_[2];
			mat[3] = mat_[3] + rhs.mat_[3]; mat[4] = mat_[4] + rhs.mat_[4]; mat[5] = mat_[5] + rhs.mat_[5];
			mat[6] = mat_[6] + rhs.mat_[6]; mat[7] = mat_[7] + rhs.mat_[7]; mat[8] = mat_[8] + rhs.mat_[8];
			return mat;
		}

		inline Matrix3 operator-(const Matrix3& rhs) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] - rhs.mat_[0]; mat[1] = mat_[1] - rhs.mat_[1]; mat[2] = mat_[2] - rhs.mat_[2];
			mat[3] = mat_[3] - rhs.mat_[3]; mat[4] = mat_[4] - rhs.mat_[4]; mat[5] = mat_[5] - rhs.mat_[5];
			mat[6] = mat_[6] - rhs.mat_[6]; mat[7] = mat_[7] - rhs.mat_[7]; mat[8] = mat_[8] - rhs.mat_[8];
			return mat;
		}

		inline float& operator[](const int index)
		{
			return mat_[index];
		}

	private:

		std::array<float, 9> mat_;
	};

	class Matrix2
	{
	public:
		Matrix2() : mat_{ } { }

		Matrix2(
			const float xx_, const float xy_,
			const float yx_, const float yy_) : mat_{
				xx_, xy_,
				yx_, yy_ } { }

		inline void identity()
		{
			mat_[0] = 1.0f;		mat_[3] = 1.0f;
		}

		inline void transpose()
		{
			Matrix2 mat = *this;
			mat_[0] = mat[0]; mat_[2] = mat[1];
			mat_[1] = mat[2]; mat_[3] = mat[3];
		}

		inline const float* toArray() const
		{
			return mat_.data();
		}

		inline const std::string toString() const
		{
			return format("Matrix3 ((%f; %f), (%f; %f), (%f; %f), (%f; %f))",
				mat_[0], mat_[1],
				mat_[2], mat_[3]);
		}

		inline Matrix2 operator*(const Matrix2& rhs) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] * rhs.mat_[0] + mat_[1] * rhs.mat_[2];
			mat[1] = mat_[0] * rhs.mat_[1] + mat_[1] * rhs.mat_[3];
			mat[2] = mat_[2] * rhs.mat_[0] + mat_[3] * rhs.mat_[2];
			mat[3] = mat_[2] * rhs.mat_[1] + mat_[3] * rhs.mat_[3];
			return mat;
		}

		inline Matrix2 operator*(const Vector2& rhs) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] * rhs.x; mat[1] = mat_[1] * rhs.y;
			mat[2] = mat_[2] * rhs.x; mat[3] = mat_[3] * rhs.y;
			return mat;
		}

		inline Matrix2 operator+(const Matrix2& rhs) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] + rhs.mat_[0]; mat[1] = mat_[1] + rhs.mat_[1];
			mat[2] = mat_[2] + rhs.mat_[2]; mat[3] = mat_[3] + rhs.mat_[3];
			return mat;
		}

		inline Matrix2 operator-(const Matrix2& rhs) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] - rhs.mat_[0]; mat[1] = mat_[1] - rhs.mat_[1];
			mat[2] = mat_[2] - rhs.mat_[2]; mat[3] = mat_[3] - rhs.mat_[3];
			return mat;
		}

		inline float& operator[](const int index)
		{
			return mat_[index];
		}

	private:

		std::array<float, 4> mat_;
	};
}
