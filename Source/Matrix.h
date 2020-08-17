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
		inline Matrix4() : mat_{} { }

		inline Matrix4(
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

		inline Matrix4 operator*(const Matrix4& a) const
		{
			Matrix4 mat;

			mat[0] = mat_[0] * a.mat_[0] + mat_[1] * a.mat_[4] + mat_[2] * a.mat_[8] + mat_[3] * a.mat_[12];
			mat[1] = mat_[0] * a.mat_[1] + mat_[1] * a.mat_[5] + mat_[2] * a.mat_[9] + mat_[3] * a.mat_[13];
			mat[2] = mat_[0] * a.mat_[2] + mat_[1] * a.mat_[6] + mat_[2] * a.mat_[10] + mat_[3] * a.mat_[14];
			mat[3] = mat_[0] * a.mat_[3] + mat_[1] * a.mat_[7] + mat_[2] * a.mat_[11] + mat_[3] * a.mat_[15];
			mat[4] = mat_[4] * a.mat_[0] + mat_[5] * a.mat_[4] + mat_[6] * a.mat_[8] + mat_[7] * a.mat_[12];
			mat[5] = mat_[4] * a.mat_[1] + mat_[5] * a.mat_[5] + mat_[6] * a.mat_[9] + mat_[7] * a.mat_[13];
			mat[6] = mat_[4] * a.mat_[2] + mat_[5] * a.mat_[6] + mat_[6] * a.mat_[10] + mat_[7] * a.mat_[14];
			mat[7] = mat_[4] * a.mat_[3] + mat_[5] * a.mat_[7] + mat_[6] * a.mat_[11] + mat_[7] * a.mat_[15];
			mat[8] = mat_[8] * a.mat_[0] + mat_[9] * a.mat_[4] + mat_[10] * a.mat_[8] + mat_[11] * a.mat_[12];
			mat[9] = mat_[8] * a.mat_[1] + mat_[9] * a.mat_[5] + mat_[10] * a.mat_[9] + mat_[11] * a.mat_[13];
			mat[10] = mat_[8] * a.mat_[2] + mat_[9] * a.mat_[6] + mat_[10] * a.mat_[10] + mat_[11] * a.mat_[14];
			mat[11] = mat_[8] * a.mat_[3] + mat_[9] * a.mat_[7] + mat_[10] * a.mat_[11] + mat_[11] * a.mat_[15];
			mat[12] = mat_[12] * a.mat_[0] + mat_[13] * a.mat_[4] + mat_[14] * a.mat_[8] + mat_[15] * a.mat_[12];
			mat[13] = mat_[12] * a.mat_[1] + mat_[13] * a.mat_[5] + mat_[14] * a.mat_[9] + mat_[15] * a.mat_[13];
			mat[14] = mat_[12] * a.mat_[2] + mat_[13] * a.mat_[6] + mat_[14] * a.mat_[10] + mat_[15] * a.mat_[14];
			mat[15] = mat_[12] * a.mat_[3] + mat_[13] * a.mat_[7] + mat_[14] * a.mat_[11] + mat_[15] * a.mat_[15];

			return mat;
		}

		inline Matrix4 operator*(const Vector4& a) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] * a.x; mat[1] = mat_[1] * a.y; mat[2] = mat_[2] * a.z; mat[3] = mat_[3] * a.w;
			mat[4] = mat_[4] * a.x; mat[5] = mat_[5] * a.y; mat[6] = mat_[6] * a.z; mat[7] = mat_[7] * a.w;
			mat[8] = mat_[8] * a.x; mat[9] = mat_[9] * a.y; mat[10] = mat_[10] * a.z; mat[11] = mat_[11] * a.w;
			mat[12] = mat_[12] * a.x; mat[13] = mat_[13] * a.y; mat[14] = mat_[14] * a.z; mat[15] = mat_[15] * a.w;
			return mat;
		}

		inline Matrix4 operator+(const Matrix4& a) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] + a.mat_[0]; mat[1] = mat_[1] + a.mat_[1]; mat[2] = mat_[2] + a.mat_[2]; mat[3] = mat_[3] + a.mat_[3];
			mat[4] = mat_[4] + a.mat_[4]; mat[5] = mat_[5] + a.mat_[5]; mat[6] = mat_[6] + a.mat_[6]; mat[7] = mat_[7] + a.mat_[7];
			mat[8] = mat_[8] + a.mat_[8]; mat[9] = mat_[9] + a.mat_[9]; mat[10] = mat_[10] + a.mat_[10]; mat[11] = mat_[11] + a.mat_[11];
			mat[12] = mat_[12] + a.mat_[12]; mat[13] = mat_[13] + a.mat_[13]; mat[14] = mat_[14] + a.mat_[14]; mat[15] = mat_[15] + a.mat_[15];
			return mat;
		}

		inline Matrix4 operator-(const Matrix4& a) const
		{
			Matrix4 mat;
			mat[0] = mat_[0] - a.mat_[0]; mat[1] = mat_[1] - a.mat_[1]; mat[2] = mat_[2] - a.mat_[2]; mat[3] = mat_[3] - a.mat_[3];
			mat[4] = mat_[4] - a.mat_[4]; mat[5] = mat_[5] - a.mat_[5]; mat[6] = mat_[6] - a.mat_[6]; mat[7] = mat_[7] - a.mat_[7];
			mat[8] = mat_[8] - a.mat_[8]; mat[9] = mat_[9] - a.mat_[9]; mat[10] = mat_[10] - a.mat_[10]; mat[11] = mat_[11] - a.mat_[11];
			mat[12] = mat_[12] - a.mat_[12]; mat[13] = mat_[13] - a.mat_[13]; mat[14] = mat_[14] - a.mat_[14]; mat[15] = mat_[15] - a.mat_[15];
			return mat;
		}

		inline float& operator[](const int index)
		{
			return mat_[index];
		}

		inline static Matrix4 translate(const Vector3& vec)
		{
			Matrix4 mat;
			mat.identity();
			mat[12] = vec.x; mat[13] = vec.y; mat[14] = vec.z;
			return mat;
		}

		inline static Matrix4 scale(const Vector3& vec)
		{
			Matrix4 mat;
			mat.identity();
			mat[0] = vec.x; mat[5] = vec.y; mat[10] = vec.z;
			return mat;
		}

		inline static Matrix4 perspective(const float& fovy, const float& aspect, const float& nearDst, const float& farDst)
		{
			Matrix4 mat;
			mat[0] = 1.0f / (std::tanf(fovy / 2) * aspect); mat[5] = 1.0f / std::tanf(fovy / 2);
			mat[10] = (farDst + nearDst) / (nearDst - farDst); mat[11] = -1.0f;
			mat[14] = (2 * nearDst * farDst) / (nearDst - farDst);
			return mat;
		}

		inline static Matrix4 orthographic(const float& left, const float& right, const float& bottom, const float& top, const float& nearDst, const float& farDst)
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

		inline static Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
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
		inline Matrix3() : mat_{} { }

		inline Matrix3(
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

		inline Matrix3 operator*(const Matrix3& a) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] * a.mat_[0] + mat_[1] * a.mat_[3] + mat_[2] * a.mat_[6];
			mat[1] = mat_[0] * a.mat_[1] + mat_[1] * a.mat_[4] + mat_[2] * a.mat_[7];
			mat[2] = mat_[0] * a.mat_[2] + mat_[1] * a.mat_[5] + mat_[2] * a.mat_[8];
			mat[3] = mat_[3] * a.mat_[0] + mat_[4] * a.mat_[3] + mat_[5] * a.mat_[6];
			mat[4] = mat_[3] * a.mat_[1] + mat_[4] * a.mat_[4] + mat_[5] * a.mat_[7];
			mat[5] = mat_[3] * a.mat_[2] + mat_[4] * a.mat_[5] + mat_[5] * a.mat_[8];
			mat[6] = mat_[6] * a.mat_[0] + mat_[7] * a.mat_[3] + mat_[8] * a.mat_[6];
			mat[7] = mat_[6] * a.mat_[1] + mat_[7] * a.mat_[4] + mat_[8] * a.mat_[7];
			mat[8] = mat_[6] * a.mat_[2] + mat_[7] * a.mat_[5] + mat_[8] * a.mat_[8];
			return mat;
		}

		inline Matrix3 operator*(const Vector3& a) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] * a.x; mat[1] = mat_[1] * a.y; mat[2] = mat_[2] * a.z;
			mat[3] = mat_[3] * a.x; mat[4] = mat_[4] * a.y; mat[5] = mat_[5] * a.z;
			mat[6] = mat_[6] * a.x; mat[7] = mat_[7] * a.y; mat[8] = mat_[8] * a.z;
			return mat;
		}

		inline Matrix3 operator+(const Matrix3& a) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] + a.mat_[0]; mat[1] = mat_[1] + a.mat_[1]; mat[2] = mat_[2] + a.mat_[2];
			mat[3] = mat_[3] + a.mat_[3]; mat[4] = mat_[4] + a.mat_[4]; mat[5] = mat_[5] + a.mat_[5];
			mat[6] = mat_[6] + a.mat_[6]; mat[7] = mat_[7] + a.mat_[7]; mat[8] = mat_[8] + a.mat_[8];
			return mat;
		}

		inline Matrix3 operator-(const Matrix3& a) const
		{
			Matrix3 mat;
			mat[0] = mat_[0] - a.mat_[0]; mat[1] = mat_[1] - a.mat_[1]; mat[2] = mat_[2] - a.mat_[2];
			mat[3] = mat_[3] - a.mat_[3]; mat[4] = mat_[4] - a.mat_[4]; mat[5] = mat_[5] - a.mat_[5];
			mat[6] = mat_[6] - a.mat_[6]; mat[7] = mat_[7] - a.mat_[7]; mat[8] = mat_[8] - a.mat_[8];
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
		inline Matrix2() : mat_{} { }

		inline Matrix2(
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

		inline Matrix2 operator*(const Matrix2& a) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] * a.mat_[0] + mat_[1] * a.mat_[2];
			mat[1] = mat_[0] * a.mat_[1] + mat_[1] * a.mat_[3];
			mat[2] = mat_[2] * a.mat_[0] + mat_[3] * a.mat_[2];
			mat[3] = mat_[2] * a.mat_[1] + mat_[3] * a.mat_[3];
			return mat;
		}

		inline Matrix2 operator*(const Vector2& a) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] * a.x; mat[1] = mat_[1] * a.y;
			mat[2] = mat_[2] * a.x; mat[3] = mat_[3] * a.y;
			return mat;
		}

		inline Matrix2 operator+(const Matrix2& a) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] + a.mat_[0]; mat[1] = mat_[1] + a.mat_[1];
			mat[2] = mat_[2] + a.mat_[2]; mat[3] = mat_[3] + a.mat_[3];
			return mat;
		}

		inline Matrix2 operator-(const Matrix2& a) const
		{
			Matrix2 mat;
			mat[0] = mat_[0] - a.mat_[0]; mat[1] = mat_[1] - a.mat_[1];
			mat[2] = mat_[2] - a.mat_[2]; mat[3] = mat_[3] - a.mat_[3];
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
