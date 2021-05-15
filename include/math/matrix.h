// Copyright © 2020-2021 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace openmath {

template<typename T>
struct Matrix {
	T m00, m01, m02, m03;
	T m10, m11, m12, m13;
	T m20, m21, m22, m23;
	T m30, m31, m32, m33;

	Matrix() : 
		m00(0), m01(0), m02(0), m03(0),
		m10(0), m11(0), m12(0), m13(0),
		m20(0), m21(0), m22(0), m23(0),
		m30(0), m31(0), m32(0), m33(0) {
	}

	Matrix(
		const T m00_, const T m01_, const T m02_, const T m03_,
		const T m10_, const T m11_, const T m12_, const T m13_,
		const T m20_, const T m21_, const T m22_, const T m23_,
		const T m30_, const T m31_, const T m32_, const T m33_
	) :  
		m00(m00_), m01(m01_), m02(m02_), m03(m03_),
		m10(m10_), m11(m11_), m12(m12_), m13(m13_),
		m20(m20_), m21(m21_), m22(m22_), m23(m23_),
		m30(m30_), m31(m31_), m32(m32_), m33(m33_) {
	}

	Matrix(const Matrix& rhs) : 
		m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(rhs.m03),
		m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(rhs.m13),
		m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(rhs.m23),
		m30(rhs.m30), m31(rhs.m31), m32(rhs.m32), m33(rhs.m33) {
	}

	Matrix(Matrix&& rhs) noexcept :
		m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(rhs.m03),
		m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(rhs.m13),
		m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(rhs.m23),
		m30(rhs.m30), m31(rhs.m31), m32(rhs.m32), m33(rhs.m33) {
	}

	Matrix& operator=(const Matrix& rhs) {
		m00 = rhs.m00;
		m01 = rhs.m01;
		m02 = rhs.m02;
		m03 = rhs.m03;
		m10 = rhs.m10;
		m11 = rhs.m11;
		m12 = rhs.m12;
		m13 = rhs.m13;
		m20 = rhs.m20;
		m21 = rhs.m21;
		m22 = rhs.m22;
		m23 = rhs.m23;
		m30 = rhs.m30;
		m31 = rhs.m31;
		m32 = rhs.m32;
		m33 = rhs.m33;
		return *this;
	}

	Matrix& operator=(Matrix&& rhs) noexcept {
		m00 = rhs.m00;
		m01 = rhs.m01;
		m02 = rhs.m02;
		m03 = rhs.m03;
		m10 = rhs.m10;
		m11 = rhs.m11;
		m12 = rhs.m12;
		m13 = rhs.m13;
		m20 = rhs.m20;
		m21 = rhs.m21;
		m22 = rhs.m22;
		m23 = rhs.m23;
		m30 = rhs.m30;
		m31 = rhs.m31;
		m32 = rhs.m32;
		m33 = rhs.m33;
		return *this;
	}

	const T* data() const {
		return &m00;
	}

	usize size() const {
		return 16;
	}

	void transpose() {
		Matrix mat;
		mat = *this;

		m00 = mat.m00;
		m01 = mat.m10;
		m02 = mat.m20;
		m03 = mat.m30;
		m10 = mat.m01;
		m11 = mat.m11;
		m12 = mat.m21;
		m13 = mat.m31;
		m20 = mat.m02;
		m21 = mat.m12;
		m22 = mat.m22;
		m23 = mat.m32;
		m30 = mat.m03;
		m31 = mat.m13;
		m32 = mat.m23;
		m33 = mat.m33;	
	}

	Matrix operator*(const Matrix& rhs) const {
		Matrix mat;
		mat.m00 = m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20 + m03 * rhs.m30;
		mat.m01 = m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21 + m03 * rhs.m31;
		mat.m02 = m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22 + m03 * rhs.m32;
		mat.m03 = m00 * rhs.m03 + m01 * rhs.m13 + m02 * rhs.m23 + m03 * rhs.m33;
		mat.m10 = m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20 + m13 * rhs.m30;
		mat.m11 = m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31;
		mat.m12 = m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32;
		mat.m13 = m10 * rhs.m03 + m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33;
		mat.m20 = m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20 + m23 * rhs.m30;
		mat.m21 = m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31;
		mat.m22 = m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32;
		mat.m23 = m20 * rhs.m03 + m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33;
		mat.m30 = m30 * rhs.m00 + m31 * rhs.m10 + m32 * rhs.m20 + m33 * rhs.m30;
		mat.m31 = m30 * rhs.m01 + m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31;
		mat.m32 = m30 * rhs.m02 + m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32;
		mat.m33 = m30 * rhs.m03 + m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33;
		return mat;
	}

	Matrix operator*(const Vector4<T>& rhs) const {
		Matrix mat;
		mat.m00 = m00 * rhs.x;
		mat.m01 = m01 * rhs.y;
		mat.m02 = m02 * rhs.z;
		mat.m03 = m03 * rhs.w;
		mat.m10 = m10 * rhs.x;
		mat.m11 = m11 * rhs.y;
		mat.m12 = m12 * rhs.z;
		mat.m13 = m13 * rhs.w;
		mat.m20 = m20 * rhs.x;
		mat.m21 = m21 * rhs.y;
		mat.m22 = m22 * rhs.z;
		mat.m23 = m23 * rhs.w;
		mat.m30 = m30 * rhs.x;
		mat.m31 = m31 * rhs.y;
		mat.m32 = m32 * rhs.z;
		mat.m33 = m33 * rhs.w;
		return mat;
	}

	Matrix operator*(const T rhs) const {
		Matrix mat;
		mat.m00 = m00 * rhs;
		mat.m01 = m01 * rhs;
		mat.m02 = m02 * rhs;
		mat.m03 = m03 * rhs;
		mat.m10 = m10 * rhs;
		mat.m11 = m11 * rhs;
		mat.m12 = m12 * rhs;
		mat.m13 = m13 * rhs;
		mat.m20 = m20 * rhs;
		mat.m21 = m21 * rhs;
		mat.m22 = m22 * rhs;
		mat.m23 = m23 * rhs;
		mat.m30 = m30 * rhs;
		mat.m31 = m31 * rhs;
		mat.m32 = m32 * rhs;
		mat.m33 = m33 * rhs;
		return mat;
	}

	Matrix operator+(const Matrix& rhs) const {
		Matrix mat;
		mat.m00 = m00 + rhs.m00;
		mat.m01 = m01 + rhs.m01;
		mat.m02 = m02 + rhs.m02;
		mat.m03 = m03 + rhs.m03;
		mat.m10 = m10 + rhs.m10;
		mat.m11 = m11 + rhs.m11;
		mat.m12 = m12 + rhs.m12;
		mat.m13 = m13 + rhs.m13;
		mat.m20 = m20 + rhs.m20;
		mat.m21 = m21 + rhs.m21;
		mat.m22 = m22 + rhs.m22;
		mat.m23 = m23 + rhs.m23;
		mat.m30 = m30 + rhs.m30;
		mat.m31 = m31 + rhs.m31;
		mat.m32 = m32 + rhs.m32;
		mat.m33 = m33 + rhs.m33;
		return mat;
	}

	Matrix operator-(const Matrix& rhs) const {
		Matrix mat;
		mat.m00 = m00 - rhs.m00;
		mat.m01 = m01 - rhs.m01;
		mat.m02 = m02 - rhs.m02;
		mat.m03 = m03 - rhs.m03;
		mat.m10 = m10 - rhs.m10;
		mat.m11 = m11 - rhs.m11;
		mat.m12 = m12 - rhs.m12;
		mat.m13 = m13 - rhs.m13;
		mat.m20 = m20 - rhs.m20;
		mat.m21 = m21 - rhs.m21;
		mat.m22 = m22 - rhs.m22;
		mat.m23 = m23 - rhs.m23;
		mat.m30 = m30 - rhs.m30;
		mat.m31 = m31 - rhs.m31;
		mat.m32 = m32 - rhs.m32;
		mat.m33 = m33 - rhs.m33;
		return mat;
	}

	static Matrix identity() {
		Matrix mat;
		mat.m00 = 1;
		mat.m11 = 1;
		mat.m22 = 1;
		mat.m33 = 1;
		return mat;
	}

	static Matrix translate(const Vector3<T>& rhs) {
		Matrix mat = Matrix::identity();
		mat.m30 = rhs.x;
		mat.m31 = rhs.y;
		mat.m32 = rhs.z;
		return mat;
	}

	static Matrix scale(const Vector3<T>& rhs) {
		Matrix mat = Matrix::identity();
		mat.m00 = rhs.x;
		mat.m11 = rhs.y;
		mat.m22 = rhs.z;
		return mat;
	}

	static Matrix perspective(const T fovy, const T aspect, const T near_dst, const T far_dst) {
		Matrix mat;
		mat.m00 = 1 / (math::tan(fovy / 2) * aspect);
		mat.m11 = 1 / math::tan(fovy / 2);
		mat.m22 = (far_dst + near_dst) / (near_dst - far_dst);
		mat.m23 = -1;
		mat.m32 = (2 * near_dst * far_dst) / (near_dst - far_dst);
		return mat;
	}

	static Matrix orthographic(
		const T left, const T right,
		const T bottom, const T top,
		const T near_dst, const T far_dst
	) {
		Matrix mat;
		mat.m00 = 2 / (right - left);
		mat.m11 = 2 / (top - bottom);
		mat.m22 = -2 / (far_dst - near_dst);
		mat.m30 = -(right + left) / (right - left);
		mat.m31 = -(top + bottom) / (top - bottom);
		mat.m32 = -(far_dst + near_dst) / (far_dst - near_dst);
		mat.m33 = 1;
		return mat;
	}

	static Matrix look_at(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up) {
		Vector3<T> z(eye - target);
		z.normalize();

		Vector3<T> x = Vector3<T>::cross_product(up, z);
		x.normalize();

		Vector3<T> y = Vector3<T>::cross_product(z, x);

		Matrix mat = Matrix::identity();
		mat.m00 = x.x;
		mat.m01 = y.x;
		mat.m02 = z.x;
		mat.m10 = x.y;
		mat.m11 = y.y;
		mat.m12 = z.y;
		mat.m20 = x.z;
		mat.m21 = y.z;
		mat.m22 = z.z;
		mat.m30 = Vector3<T>::dot_product(-x, eye);
		mat.m31 = Vector3<T>::dot_product(-y, eye);
		mat.m32 = Vector3<T>::dot_product(-z, eye);
		return mat;
	}

	bool operator==(const Matrix& rhs) const
	{
		return (m00 == rhs.m00) && (m01 == rhs.m01) && (m02 == rhs.m02) && (m03 == rhs.m03) &&
			(m10 == rhs.m10) && (m11 == rhs.m11) && (m12 == rhs.m12) && (m13 == rhs.m13) &&
			(m20 == rhs.m20) && (m11 == rhs.m21) && (m12 == rhs.m22) && (m13 == rhs.m23) &&
			(m30 == rhs.m30) && (m11 == rhs.m31) && (m12 == rhs.m32) && (m13 == rhs.m33);
	}

	bool operator!=(const Matrix& rhs) const
	{
		return (m00 != rhs.m00) || (m01 != rhs.m01) || (m02 != rhs.m02) || (m03 != rhs.m03) ||
			(m10 != rhs.m10) || (m11 != rhs.m11) || (m12 != rhs.m12) || (m13 != rhs.m13) ||
			(m20 != rhs.m20) || (m11 != rhs.m21) || (m12 != rhs.m22) || (m13 != rhs.m23) ||
			(m30 != rhs.m30) || (m11 != rhs.m31) || (m12 != rhs.m32) || (m13 != rhs.m33);
	}
};

using Fmatrix = Matrix<float>;
using Dmatrix = Matrix<double>;

}