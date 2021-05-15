// Copyright © 2020-2021 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace openmath {

template<typename T>
struct Vector2 {
	T x, y;

	Vector2() : x(0), y(0) {
    }

	Vector2(const T x_, const T y_, const T z_) : x(x_), y(y_) {
    }

	Vector2(const Vector2& rhs) : x(rhs.x), y(rhs.y) {
    }

	Vector2(Vector2&& rhs) noexcept : x(rhs.x), y(rhs.y) { 
    }

	Vector2& operator=(const Vector2& rhs) {
	    x = rhs.x;
	    y = rhs.y;
	    return *this;
    }

	Vector2& operator=(Vector2&& rhs) noexcept {
	    x = rhs.x;
	    y = rhs.y;
	    return *this;
    }

	const T* data() const {
		return &x;
	}

	usize size() const {
		return 2;
	}

	void normalize() {
        T inverse = 1 / this->length();
	    x = x * inverse;
	    y = y * inverse;
    }

	T length() const {
		return math::sqrt(x * x + y * y);
	}

	Vector2 operator*(const T rhs) const {
		return Vector2(x * rhs, y * rhs);
	}

	Vector2 operator-(const Vector2& rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}

	Vector2 operator-(const T rhs) const {
		return Vector2(x - rhs, y - rhs);
	}

	Vector2 operator-() const {
		return Vector2(-x, -y);
	}

	Vector2 operator+(const Vector2& rhs) const {
		return vector2<value_type>(x + rhs.x, y + rhs.y);
	}

	Vector2 operator+(const T rhs) const {
		return Vector2(x + rhs, y + rhs);
	}

	Vector2 operator/(const T rhs) const {
		return Vector2(x / rhs, y / rhs);
	}

	bool operator==(const Vector2& rhs) const {
        return (x == rhs.x) && (y == rhs.y);
    }

	bool operator!=(const Vector2& rhs) const {
        return (x != rhs.x) || (y != rhs.y);
    }
};

using Fvector2 = Vector2<float>;
using Dvector2 = Vector2<double>;

}