#pragma once

#include <math.h>
#include <float.h>
#include <string.h>

namespace pxl {
	struct vec3f;
	struct vec4f;
	struct vec2f;

	namespace mathf {
		static constexpr float epsilon{ FLT_EPSILON };
		static constexpr float infinity{ INFINITY };
		static constexpr float nan{ NAN };
		static constexpr float pi{ 3.14159265359f };
		static constexpr float halfpi{ 1.57079632679f };
		static constexpr float deg2rad{ 0.01745329252f };
		static constexpr float rad2deg{ 57.295779513f };
		inline static float rsqrt(const float& x) {
			int i = *(int*)&x;
			i = 0x5f3759df - (i >> 1);
			const float y = *(float*)&i;
			return y * (1.5f - 0.5f * x * y * y);
		}
	}

	struct vec2f {
		float x, y;
		inline constexpr float magnitude() const {
			const float sqrmag = x * x + y * y;
			if (sqrmag < mathf::epsilon) return 0;
			return sqrtf(sqrmag);
		}
		inline const vec2f& normalize() {
			const float sqrmag = x * x + y * y;
			if (sqrmag < mathf::epsilon) x = y = 0;
			const float rmag = mathf::rsqrt(sqrmag);
			x *= rmag; y *= rmag;
			return *this;
		}
		inline constexpr vec2f normalized() const {
			const float sqrmag = x * x + y * y;
			if (sqrmag < mathf::epsilon) return { 0 };
			const float rmag = mathf::rsqrt(sqrmag);
			return { x * rmag, y * rmag };
		}
		inline constexpr vec2f operator+() const { return *this; }
		inline constexpr vec2f operator-() const { return (*this) * -1; }
		inline vec2f& operator++() { ++x; ++y; return *this; }
		inline constexpr vec2f operator++(int) { return { x++, y++ }; }
		inline vec2f& operator--() { --x; --y; return *this; }
		inline constexpr vec2f operator--(int) { return { x--, y-- }; }
		inline constexpr vec2f operator+(const float& o) const { return { x + o, y + o }; }
		inline friend constexpr vec2f operator+(const float& l, const vec2f& r) { return { l + r.x, l + r.y }; }
		inline constexpr vec2f operator+(const vec2f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator+(const vec3f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator+(const vec4f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator-(const float& o) const { return { x - o, y - o }; }
		inline friend constexpr vec2f operator-(const float& l, const vec2f& r) { return { l - r.x, l - r.y }; }
		inline constexpr vec2f operator-(const vec2f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator-(const vec3f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator-(const vec4f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator*(const float& o) const { return { x * o, y * o }; }
		inline friend constexpr vec2f operator*(const float& l, const vec2f& r) { return { l * r.x, l * r.y }; }
		inline constexpr vec2f operator*(const vec2f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator*(const vec3f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator*(const vec4f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator/(const float& o) const { return { x / o, y / o }; }
		inline friend constexpr vec2f operator/(const float& l, const vec2f& r) { return { l / r.x, l / r.y }; }
		inline constexpr vec2f operator/(const vec2f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator/(const vec3f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1) }; }
		inline constexpr vec2f operator/(const vec4f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1) }; }
		inline vec2f& operator =(const float& o) { x = o; y = o; return *this; }
		//inline vec2f& operator =(const vec2f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); return *this; }
		inline vec2f& operator =(const vec3f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); return *this; }
		inline vec2f& operator =(const vec4f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); return *this; }
		inline vec2f& operator+=(const float& o) { x += o; y += o; return *this; }
		inline vec2f& operator+=(const vec2f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); return *this; }
		inline vec2f& operator+=(const vec3f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); return *this; }
		inline vec2f& operator+=(const vec4f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); return *this; }
		inline vec2f& operator-=(const float& o) { x -= o; y -= o; return *this; }
		inline vec2f& operator-=(const vec2f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator-=(const vec3f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator-=(const vec4f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator*=(const float& o) { x *= o; y *= o; return *this; }
		inline vec2f& operator*=(const vec2f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator*=(const vec3f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator*=(const vec4f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator/=(const float& o) { x /= o; y /= o; return *this; }
		inline vec2f& operator/=(const vec2f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator/=(const vec3f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); return *this; }
		inline vec2f& operator/=(const vec4f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); return *this; }
		inline bool operator==(const vec2f& o) { return memcmp(this, &o, sizeof(vec2f)); }
		inline bool operator!=(const vec2f& o) { return !memcmp(this, &o, sizeof(vec2f)); }
		inline float& operator[](const size_t& i) { return ((float*)this)[i]; }
		inline const float& operator[](const size_t& i) const { return ((float*)this)[i]; }

		inline static constexpr vec2f zero() { return { 0 }; }
		inline static constexpr vec2f left() { return { -1, 0 }; }
		inline static constexpr vec2f right() { return { 1, 0 }; }
		inline static constexpr vec2f up() { return { 0, 1 }; }
		inline static constexpr vec2f down() { return { 0, -1 }; }
		inline static constexpr vec2f infinity() { return { INFINITY, INFINITY }; }
	};

	struct vec3f {
		float x, y, z;
		inline constexpr float magnitude() const {
			const float sqrmag = x * x + y * y + z * z;
			if (sqrmag < mathf::epsilon) return 0;
			return sqrtf(sqrmag);
		}
		inline const vec3f& normalize() {
			const float sqrmag = x * x + y * y + z * z;
			if (sqrmag < mathf::epsilon) x = y = z = 0;
			const float rmag = mathf::rsqrt(sqrmag);
			x *= rmag; y *= rmag; z *= rmag;
			return *this;
		}
		inline constexpr vec3f normalized() const {
			const float sqrmag = x * x + y * y + z * z;
			if (sqrmag < mathf::epsilon) return { 0 };
			const float rmag = mathf::rsqrt(sqrmag);
			return { x * rmag, y * rmag, z * rmag };
		}
		inline constexpr vec3f operator+() const { return *this; }
		inline constexpr vec3f operator-() const { return (*this) * -1; }
		inline vec3f& operator++() { ++x; ++y; ++z; return *this; }
		inline constexpr vec3f operator++(int) { return { x++, y++, z++ }; }
		inline vec3f& operator--() { --x; --y; --z; return *this; }
		inline constexpr vec3f operator--(int) { return { x--, y--, z-- }; }
		inline constexpr vec3f operator+(const float& o) const { return { x + o, y + o, z + o }; }
		inline friend constexpr vec3f operator+(const float& l, const vec3f& r) { return { l + r.x, l + r.y, l + r.z }; }
		inline constexpr vec3f operator+(const vec2f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z }; }
		inline constexpr vec3f operator+(const vec3f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z + *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator+(const vec4f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z + *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator-(const float& o) const { return { x - o, y - o, z - o }; }
		inline friend constexpr vec3f operator-(const float& l, const vec3f& r) { return { l - r.x, l - r.y, l - r.z }; }
		inline constexpr vec3f operator-(const vec2f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z }; }
		inline constexpr vec3f operator-(const vec3f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z - *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator-(const vec4f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z - *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator*(const float& o) const { return { x * o, y * o, z * o }; }
		inline friend constexpr vec3f operator*(const float& l, const vec3f& r) { return { l * r.x, l * r.y, l * r.z }; }
		inline constexpr vec3f operator*(const vec2f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z }; }
		inline constexpr vec3f operator*(const vec3f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z * *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator*(const vec4f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z * *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator/(const float& o) const { return { x / o, y / o, z / o }; }
		inline friend constexpr vec3f operator/(const float& l, const vec3f& r) { return { l / r.x, l / r.y, l / r.z }; }
		inline constexpr vec3f operator/(const vec2f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z }; }
		inline constexpr vec3f operator/(const vec3f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z / *(((float*)&o) + 2) }; }
		inline constexpr vec3f operator/(const vec4f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z / *(((float*)&o) + 2) }; }
		inline vec3f& operator =(const float& o) { x = o; y = o; z = o; return *this; }
		inline vec3f& operator =(const vec2f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); return *this; }
		//inline vec3f& operator =(const vec3f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); z = *(((float*)&o) + 2); return *this; }
		inline vec3f& operator =(const vec4f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); z = *(((float*)&o) + 2); return *this; }
		inline vec3f& operator+=(const float& o) { x += o; y += o; z += o; return *this; }
		inline vec3f& operator+=(const vec2f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); return *this; }
		inline vec3f& operator+=(const vec3f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); z += *(((float*)&o) + 2); return *this; }
		inline vec3f& operator+=(const vec4f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); z += *(((float*)&o) + 2); return *this; }
		inline vec3f& operator-=(const float& o) { x -= o; y -= o; z -= o; return *this; }
		inline vec3f& operator-=(const vec2f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); return *this; }
		inline vec3f& operator-=(const vec3f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); z -= *(((float*)&o) + 2); return *this; }
		inline vec3f& operator-=(const vec4f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); z -= *(((float*)&o) + 2); return *this; }
		inline vec3f& operator*=(const float& o) { x *= o; y *= o; z *= o; return *this; }
		inline vec3f& operator*=(const vec2f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); return *this; }
		inline vec3f& operator*=(const vec3f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); z *= *(((float*)&o) + 2); return *this; }
		inline vec3f& operator*=(const vec4f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); z *= *(((float*)&o) + 2); return *this; }
		inline vec3f& operator/=(const float& o) { x /= o; y /= o; z /= o; return *this; }
		inline vec3f& operator/=(const vec2f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); return *this; }
		inline vec3f& operator/=(const vec3f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); z /= *(((float*)&o) + 2); return *this; }
		inline vec3f& operator/=(const vec4f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); z /= *(((float*)&o) + 2); return *this; }
		inline bool operator==(const vec3f& o) { return memcmp(this, &o, sizeof(vec3f)); }
		inline bool operator!=(const vec3f& o) { return !memcmp(this, &o, sizeof(vec3f)); }
		inline float& operator[](const size_t& i) { return ((float*)this)[i]; }
		inline const float& operator[](const size_t& i) const { return ((float*)this)[i]; }

		inline static constexpr vec3f zero() { return { 0 }; }
		inline static constexpr vec3f left() { return { -1, 0, 0 }; }
		inline static constexpr vec3f right() { return { 1, 0, 0 }; }
		inline static constexpr vec3f up() { return { 0, 1, 0 }; }
		inline static constexpr vec3f down() { return { 0, -1, 0 }; }
		inline static constexpr vec3f forward() { return { 0, 0, 1 }; }
		inline static constexpr vec3f back() { return { 0, 0, -1 }; }
		inline static constexpr vec3f infinity() { return { INFINITY, INFINITY, INFINITY }; }
	};

	struct vec4f {
		float x, y, z, w;
		inline constexpr float magnitude() const {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) return 0;
			return sqrtf(sqrmag);
		}
		inline const vec4f& normalize() {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) x = y = z = w = 0;
			const float rmag = mathf::rsqrt(sqrmag);
			x *= rmag; y *= rmag; z *= rmag; w *= rmag;
			return *this;
		}
		inline constexpr vec4f normalized() const {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) return { 0 };
			const float rmag = mathf::rsqrt(sqrmag);
			return { x * rmag, y * rmag, z * rmag, w * rmag };
		}
		inline constexpr vec4f operator+() const { return *this; }
		inline constexpr vec4f operator-() const { return (*this) * -1; }
		inline vec4f& operator++() { ++x; ++y; ++z; ++w; return *this; }
		inline constexpr vec4f operator++(int) { return { x++, y++, z++, w++ }; }
		inline vec4f& operator--() { --x; --y; --z; --w; return *this; }
		inline constexpr vec4f operator--(int) { return { x--, y--, z--, w-- }; }
		inline constexpr vec4f operator+(const float& o) const { return { x + o, y + o, z + o, w + o }; }
		inline friend constexpr vec4f operator+(const float& l, const vec4f& r) { return { l + r.x, l + r.y, l + r.z, l + r.w }; }
		inline constexpr vec4f operator+(const vec2f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z, w }; }
		inline constexpr vec4f operator+(const vec3f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z + *(((float*)&o) + 2), w }; }
		inline constexpr vec4f operator+(const vec4f& o) const { return { x + *((float*)&o), y + *(((float*)&o) + 1), z + *(((float*)&o) + 2), w + *(((float*)&o) + 3) }; }
		inline constexpr vec4f operator-(const float& o) const { return { x - o, y - o, z - o, w - o }; }
		inline friend constexpr vec4f operator-(const float& l, const vec4f& r) { return { l - r.x, l - r.y, l - r.z, l - r.w }; }
		inline constexpr vec4f operator-(const vec2f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z, w }; }
		inline constexpr vec4f operator-(const vec3f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z - *(((float*)&o) + 2), w }; }
		inline constexpr vec4f operator-(const vec4f& o) const { return { x - *((float*)&o), y - *(((float*)&o) + 1), z - *(((float*)&o) + 2), w - *(((float*)&o) + 3) }; }
		inline constexpr vec4f operator*(const float& o) const { return { x * o, y * o, z * o, w * o }; }
		inline friend constexpr vec4f operator*(const float& l, const vec4f& r) { return { l * r.x, l * r.y, l * r.z, l * r.w }; }
		inline constexpr vec4f operator*(const vec2f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z, w }; }
		inline constexpr vec4f operator*(const vec3f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z * *(((float*)&o) + 2), w }; }
		inline constexpr vec4f operator*(const vec4f& o) const { return { x * *((float*)&o), y * *(((float*)&o) + 1), z * *(((float*)&o) + 2), w * *(((float*)&o) + 3) }; }
		inline constexpr vec4f operator/(const float& o) const { return { x / o, y / o, z / o, w / o }; }
		inline friend constexpr vec4f operator/(const float& l, const vec4f& r) { return { l / r.x, l / r.y, l / r.z, l / r.w }; }
		inline constexpr vec4f operator/(const vec2f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z, w }; }
		inline constexpr vec4f operator/(const vec3f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z / *(((float*)&o) + 2), w }; }
		inline constexpr vec4f operator/(const vec4f& o) const { return { x / *((float*)&o), y / *(((float*)&o) + 1), z / *(((float*)&o) + 2), w / *(((float*)&o) + 3) }; }
		inline vec4f& operator =(const float& o) { x = o; y = o; z = o; w = o; return *this; }
		inline vec4f& operator =(const vec2f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); return *this; }
		inline vec4f& operator =(const vec3f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); z = *(((float*)&o) + 2); return *this; }
		//inline vec4f& operator =(const vec4f& o) { x = *((float*)&o); y = *(((float*)&o) + 1); z = *(((float*)&o) + 2); w = *(((float*)&o) + 3); return *this; }
		inline vec4f& operator+=(const float& o) { x += o; y += o; z += o; w += o; return *this; }
		inline vec4f& operator+=(const vec2f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); return *this; }
		inline vec4f& operator+=(const vec3f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); z += *(((float*)&o) + 2); return *this; }
		inline vec4f& operator+=(const vec4f& o) { x += *((float*)&o); y += *(((float*)&o) + 1); z += *(((float*)&o) + 2); w += *(((float*)&o) + 3); return *this; }
		inline vec4f& operator-=(const float& o) { x -= o; y -= o; z -= o; w -= o; return *this; }
		inline vec4f& operator-=(const vec2f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); return *this; }
		inline vec4f& operator-=(const vec3f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); z -= *(((float*)&o) + 2); return *this; }
		inline vec4f& operator-=(const vec4f& o) { x -= *((float*)&o); y -= *(((float*)&o) + 1); z -= *(((float*)&o) + 2); w -= *(((float*)&o) + 3); return *this; }
		inline vec4f& operator*=(const float& o) { x *= o; y *= o; z *= o; w *= o; return *this; }
		inline vec4f& operator*=(const vec2f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); return *this; }
		inline vec4f& operator*=(const vec3f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); z *= *(((float*)&o) + 2); return *this; }
		inline vec4f& operator*=(const vec4f& o) { x *= *((float*)&o); y *= *(((float*)&o) + 1); z *= *(((float*)&o) + 2); w *= *(((float*)&o) + 3); return *this; }
		inline vec4f& operator/=(const float& o) { x /= o; y /= o; z /= o; w /= o; return *this; }
		inline vec4f& operator/=(const vec2f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); return *this; }
		inline vec4f& operator/=(const vec3f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); z /= *(((float*)&o) + 2); return *this; }
		inline vec4f& operator/=(const vec4f& o) { x /= *((float*)&o); y /= *(((float*)&o) + 1); z /= *(((float*)&o) + 2); w /= *(((float*)&o) + 3); return *this; }
		inline bool operator==(const vec4f& o) { return memcmp(this, &o, sizeof(vec4f)); }
		inline bool operator!=(const vec4f& o) { return !memcmp(this, &o, sizeof(vec4f)); }
		inline float& operator[](const size_t& i) { return ((float*)this)[i]; }
		inline const float& operator[](const size_t& i) const { return ((float*)this)[i]; }

		inline static constexpr vec4f zero() { return { 0 }; }
		inline static constexpr vec4f infinity() { return { INFINITY, INFINITY, INFINITY, INFINITY }; }
	};

	struct quatf {
		float x, y, z, w;
		inline constexpr float magnitude() const {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) return 0;
			return sqrtf(sqrmag);
		}
		inline quatf& normalize() {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) x = y = z = w = 0;
			const float rmag = mathf::rsqrt(sqrmag);
			x *= rmag; y *= rmag; z *= rmag; w *= rmag;
			return *this;
		}
		inline constexpr quatf normalized() const {
			const float sqrmag = x * x + y * y + z * z + w * w;
			if (sqrmag < mathf::epsilon) return { 0 };
			const float rmag = mathf::rsqrt(sqrmag);
			return { x * rmag, y * rmag, z * rmag, w * rmag };
		}
		inline quatf& conjugate() { x = -x; y = -y, z = -z; return *this; }
		inline constexpr quatf conjugated() const { return { -x, -y, -z, w }; }
		inline quatf& euler(const vec3f& rad) { return *this = from_euler(rad); }
		inline vec3f euler() const { return to_euler(*this); }
		inline constexpr quatf operator*(const quatf& o) const {
			return { x * o.w + y * o.z - z * o.y + w * o.x,
			-x * o.z + y * o.w + z * o.x + w * o.y,
			x * o.y - y * o.x + z * o.w + w * o.z,
			-x * o.x - y * o.y - z * o.z + w * o.w };
		}
		inline constexpr quatf& operator*=(const quatf& o)
		{
			const float x = this->x, y = this->y, z = this->z, w = this->w;
			this->x = x * o.w + y * o.z - z * o.y + w * o.x;
			this->y = -x * o.z + y * o.w + z * o.x + w * o.y;
			this->z = x * o.y - y * o.x + z * o.w + w * o.z;
			this->w = -x * o.x - y * o.y - z * o.z + w * o.w;
			return *this;
		}
		inline float& operator[](const size_t& i) { return ((float*)this)[i]; }
		inline const float& operator[](const size_t& i) const { return ((float*)this)[i]; }

		inline static constexpr quatf zero() { return { 0 }; }
		inline static constexpr quatf identity() { return { 0, 0, 0, 1 }; }

		inline static vec3f to_euler(const quatf& q) {
			const float x2 = q.x * q.x, y2 = q.y * q.y, z2 = q.z * q.z, w2 = q.w * q.w,
				u = x2 + y2 + z2 + w2, t = q.x * q.y + q.z * q.w;
			if (t > 0.499f * u) return { 0, mathf::halfpi, 2 * atan2f(q.x, q.w) };
			if (t < -0.499f * u) return { 0, -mathf::halfpi, -2 * atan2f(q.x, q.w) };
			return {
				atan2f(2 * q.x * q.w - 2 * q.y * q.z, -x2 + y2 - z2 + w2),
				atan2f(2 * q.y * q.w - 2 * q.x * q.z, x2 - y2 - z2 + w2),
				asinf(2 * t / u) };
		}
		inline static quatf from_euler(const vec3f& r /* radians */) {
			//const vec3f hr{ r * 0.00872664625f };
			const vec3f hr{ r * 0.5f };
			const float
				x0 = cosf(hr.x), x1 = sinf(hr.x),
				y0 = cosf(hr.y), y1 = sinf(hr.y),
				z0 = cosf(hr.z), z1 = sinf(hr.z),
				y0z0 = y0 * z0, y0z1 = y0 * z1,
				y1z0 = y1 * z0, y1z1 = y1 * z1;
			return {
				y0z0 * x1 + y1z1 * x0,
				y1z0 * x0 + y0z1 * x1,
				y0z1 * x0 - y1z0 * x1,
				y0z0 * x0 - y1z1 * x1 };
		}
	};

	struct mat4f {
		float
			m00, m01, m02, m03,
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33;
		inline constexpr float det() const {
			const float m2323 = m22 * m33 - m23 * m32;
			const float m1323 = m21 * m33 - m23 * m31;
			const float m1223 = m21 * m32 - m22 * m31;
			const float m0323 = m20 * m33 - m23 * m30;
			const float m0223 = m20 * m32 - m22 * m30;
			const float m0123 = m20 * m31 - m21 * m30;
			const float m2313 = m12 * m33 - m13 * m32;
			const float m1313 = m11 * m33 - m13 * m31;
			const float m1213 = m11 * m32 - m12 * m31;
			const float m2312 = m12 * m23 - m13 * m22;
			const float m1312 = m11 * m23 - m13 * m21;
			const float m1212 = m11 * m22 - m12 * m21;
			const float m0313 = m10 * m33 - m13 * m30;
			const float m0213 = m10 * m32 - m12 * m30;
			const float m0312 = m10 * m23 - m13 * m20;
			const float m0212 = m10 * m22 - m12 * m20;
			const float m0113 = m10 * m31 - m11 * m30;
			const float m0112 = m10 * m21 - m11 * m20;
			float det = m00 * (m11 * m2323 - m12 * m1323 + m13 * m1223)
				- m01 * (m10 * m2323 - m12 * m0323 + m13 * m0223)
				+ m02 * (m10 * m1323 - m11 * m0323 + m13 * m0123)
				- m03 * (m10 * m1223 - m11 * m0223 + m12 * m0123);
			return det;
		}
		inline float inverse(mat4f& out) const {
			const float m2323 = m22 * m33 - m23 * m32;
			const float m1323 = m21 * m33 - m23 * m31;
			const float m1223 = m21 * m32 - m22 * m31;
			const float m0323 = m20 * m33 - m23 * m30;
			const float m0223 = m20 * m32 - m22 * m30;
			const float m0123 = m20 * m31 - m21 * m30;
			const float m2313 = m12 * m33 - m13 * m32;
			const float m1313 = m11 * m33 - m13 * m31;
			const float m1213 = m11 * m32 - m12 * m31;
			const float m2312 = m12 * m23 - m13 * m22;
			const float m1312 = m11 * m23 - m13 * m21;
			const float m1212 = m11 * m22 - m12 * m21;
			const float m0313 = m10 * m33 - m13 * m30;
			const float m0213 = m10 * m32 - m12 * m30;
			const float m0312 = m10 * m23 - m13 * m20;
			const float m0212 = m10 * m22 - m12 * m20;
			const float m0113 = m10 * m31 - m11 * m30;
			const float m0112 = m10 * m21 - m11 * m20;
			const float det = m00 * (m11 * m2323 - m12 * m1323 + m13 * m1223)
				- m01 * (m10 * m2323 - m12 * m0323 + m13 * m0223)
				+ m02 * (m10 * m1323 - m11 * m0323 + m13 * m0123)
				- m03 * (m10 * m1223 - m11 * m0223 + m12 * m0123);
			if (det) {
				const float rdet = 1 / det;
				out.m00 = rdet * (m11 * m2323 - m12 * m1323 + m13 * m1223);
				out.m01 = rdet * -(m01 * m2323 - m02 * m1323 + m03 * m1223);
				out.m02 = rdet * (m01 * m2313 - m02 * m1313 + m03 * m1213);
				out.m03 = rdet * -(m01 * m2312 - m02 * m1312 + m03 * m1212);
				out.m10 = rdet * -(m10 * m2323 - m12 * m0323 + m13 * m0223);
				out.m11 = rdet * (m00 * m2323 - m02 * m0323 + m03 * m0223);
				out.m12 = rdet * -(m00 * m2313 - m02 * m0313 + m03 * m0213);
				out.m13 = rdet * (m00 * m2312 - m02 * m0312 + m03 * m0212);
				out.m20 = rdet * (m10 * m1323 - m11 * m0323 + m13 * m0123);
				out.m21 = rdet * -(m00 * m1323 - m01 * m0323 + m03 * m0123);
				out.m22 = rdet * (m00 * m1313 - m01 * m0313 + m03 * m0113);
				out.m23 = rdet * -(m00 * m1312 - m01 * m0312 + m03 * m0112);
				out.m30 = rdet * -(m10 * m1223 - m11 * m0223 + m12 * m0123);
				out.m31 = rdet * (m00 * m1223 - m01 * m0223 + m02 * m0123);
				out.m32 = rdet * -(m00 * m1213 - m01 * m0213 + m02 * m0113);
				out.m33 = rdet * (m00 * m1212 - m01 * m0212 + m02 * m0112);
			}
			return det;
		}
		inline constexpr mat4f operator*(const float& o) const {
			return {
				m00 * o, m01 * o, m02 * o, m03 * o,
				m10 * o, m11 * o, m12 * o, m13 * o,
				m20 * o, m21 * o, m22 * o, m23 * o,
				m30 * o, m31 * o, m32 * o, m33 * o };
		}
		inline constexpr mat4f operator*(const mat4f& o) const {
			return {
				m00 * o.m00 + m01 * o.m10 + m02 * o.m20 + m03 * o.m30,
				m00 * o.m01 + m01 * o.m11 + m02 * o.m21 + m03 * o.m31,
				m00 * o.m02 + m01 * o.m12 + m02 * o.m22 + m03 * o.m32,
				m00 * o.m03 + m01 * o.m13 + m02 * o.m23 + m03 * o.m33,

				m10 * o.m00 + m11 * o.m10 + m12 * o.m20 + m13 * o.m30,
				m10 * o.m01 + m11 * o.m11 + m12 * o.m21 + m13 * o.m31,
				m10 * o.m02 + m11 * o.m12 + m12 * o.m22 + m13 * o.m32,
				m10 * o.m03 + m11 * o.m13 + m12 * o.m23 + m13 * o.m33,

				m20 * o.m00 + m21 * o.m10 + m22 * o.m20 + m23 * o.m30,
				m20 * o.m01 + m21 * o.m11 + m22 * o.m21 + m23 * o.m31,
				m20 * o.m02 + m21 * o.m12 + m22 * o.m22 + m23 * o.m32,
				m20 * o.m03 + m21 * o.m13 + m22 * o.m23 + m23 * o.m33,

				m30 * o.m00 + m31 * o.m10 + m32 * o.m20 + m33 * o.m30,
				m30 * o.m01 + m31 * o.m11 + m32 * o.m21 + m33 * o.m31,
				m30 * o.m02 + m31 * o.m12 + m32 * o.m22 + m33 * o.m32,
				m30 * o.m03 + m31 * o.m13 + m32 * o.m23 + m33 * o.m33 };
		}
		inline const mat4f& operator =(const float& o) {
			m00 = o; m01 = o; m02 = o; m03 = o;
			m10 = o; m11 = o; m12 = o; m13 = o;
			m20 = o; m21 = o; m22 = o; m23 = o;
			m30 = o; m31 = o; m32 = o; m33 = o;
			return *this;
		}
		/*inline const mat4f& operator =(const mat4f& o) {
			m00 = o.m00; m01 = o.m01; m02 = o.m02; m03 = o.m03;
			m10 = o.m10; m11 = o.m11; m12 = o.m12; m13 = o.m13;
			m20 = o.m20; m21 = o.m21; m22 = o.m22; m23 = o.m23;
			m30 = o.m30; m31 = o.m31; m32 = o.m32; m33 = o.m33;
			return *this;
		}*/
		inline const mat4f& operator*=(const float& o) {
			m00 *= o; m01 *= o; m02 *= o; m03 *= o;
			m10 *= o; m11 *= o; m12 *= o; m13 *= o;
			m20 *= o; m21 *= o; m22 *= o; m23 *= o;
			m30 *= o; m31 *= o; m32 *= o; m33 *= o;
			return *this;
		}
		inline const mat4f& operator*=(const mat4f& o) { return *this = *this * o; }
		inline bool operator==(const mat4f& o) { return memcmp(this, &o, sizeof(mat4f)); }
		inline bool operator!=(const mat4f& o) { return !memcmp(this, &o, sizeof(mat4f)); }
		inline float& operator[](const size_t& i) { return ((float*)this)[i]; }
		inline const float& operator[](const size_t& i) const { return ((float*)this)[i]; }
		inline float& operator()(const size_t& r, const size_t& c) { return *(((float*)this) + (c << 2) + r); }
		inline const float& operator()(const size_t& r, const size_t& c) const { return *(((float*)this) + (c << 2) + r); }

		inline static constexpr mat4f zero() { return { 0 }; }
		inline static constexpr mat4f identity() { return { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }; }

		inline static vec3f to_translation(const mat4f& m) { return { m.m03, m.m13, m.m23 }; }
		inline static quatf to_rotation(const mat4f& m) {
			float e = m.m00 + m.m11 + m.m22;
			if (e > 0) {
				const float a = mathf::rsqrt(e + 1.0) * 0.5f; // S=4*qw 
				return {
					(m.m21 - m.m12) * a,
					(m.m02 - m.m20) * a,
					(m.m10 - m.m01) * a,
					0.25f / a };
			}
			else if ((m.m00 > m.m11) && (m.m00 > m.m22)) {
				float a = mathf::rsqrt(1.0 + m.m00 - m.m11 - m.m22) * 0.5f; // S=4*qx 
				return {
					0.25f / a,
					(m.m01 + m.m10) * a,
					(m.m02 + m.m20) * a,
					(m.m21 - m.m12) * a };

			}
			else if (m.m11 > m.m22) {
				float a = mathf::rsqrt(1.0 + m.m11 - m.m00 - m.m22) * 0.5f; // S=4*qy
				return {
					(m.m01 + m.m10) * a,
					0.25f / a,
					(m.m12 + m.m21) * a,
					(m.m02 - m.m20) * a };
			}
			else {
				float a = mathf::rsqrt(1.0 + m.m22 - m.m00 - m.m11) * 0.5f; // S=4*qz
				return {
					(m.m02 + m.m20) * a,
					(m.m12 + m.m21) * a,
					0.25f / a,
					(m.m10 - m.m01) * a };
			}
		}
		inline static vec3f to_scale(const mat4f& m) {
			return {
				m.m00 * m.m00 + m.m10 * m.m10 + m.m20 * m.m20,
				m.m01 * m.m01 + m.m11 * m.m11 + m.m21 * m.m21,
				m.m02 * m.m02 + m.m12 * m.m12 + m.m22 * m.m22 };
		}
		inline static constexpr mat4f trs(const vec3f& t, const quatf& r, const vec3f& s) {
			const float x = r.x, y = r.y, z = r.z, w = r.w,
				x2 = x * x, y2 = y * y, z2 = z * z, xy = x * y, xz = x * z, yz = y * z,
				wx = w * x, wy = w * y, wz = w * z;
			return {
				(1.0f - 2.0f * (y2 + z2)) * s.x, (2.0f * (xy - wz)) * s.y, (2.0f * (xz + wy)) * s.z, t.x,
				(2.0f * (xy + wz)) * s.x, (1.0f - 2.0f * (x2 + z2)) * s.y, (2.0f * (yz - wx)) * s.z, t.y,
				(2.0f * (xz - wy)) * s.x, (2.0f * (yz + wx)) * s.y, (1.0f - 2.0f * (x2 + y2)) * s.z, t.z,
				0, 0, 0, 1 };
		}
		inline static void trs(mat4f& m, const vec3f& t, const quatf& r, const vec3f& s) {
			const float x = r.x, y = r.y, z = r.z, w = r.w,
				x2 = x * x, y2 = y * y, z2 = z * z, xy = x * y, xz = x * z, yz = y * z,
				wx = w * x, wy = w * y, wz = w * z;

			m.m00 = (1.0f - 2.0f * (y2 + z2)) * s.x; m.m01 = (2.0f * (xy - wz)) * s.y; m.m02 = (2.0f * (xz + wy)) * s.z; m.m03 = t.x;
			m.m10 = (2.0f * (xy + wz)) * s.x; m.m11 = (1.0f - 2.0f * (x2 + z2)) * s.y; m.m12 = (2.0f * (yz - wx)) * s.z; m.m13 = t.y;
			m.m20 = (2.0f * (xz - wy)) * s.x; m.m21 = (2.0f * (yz + wx)) * s.y; m.m22 = (1.0f - 2.0f * (x2 + y2)) * s.z; m.m23 = t.z;
			m.m30 = 0; m.m31 = 0; m.m32 = 0; m.m33 = 1;
		}
		inline static constexpr mat4f view(const vec3f& t, const quatf& r, const vec3f& s) {
			const float x = r.x, y = r.y, z = r.z, w = r.w,
				x2 = x * x, y2 = y * y, z2 = z * z, xy = x * y, xz = x * z, yz = y * z,
				wx = w * x, wy = w * y, wz = w * z;
			return {
				(1.0f - 2.0f * (y2 + z2)) * s.x, (2.0f * (xy - wz)) * s.y, (2.0f * (xz + wy)) * s.z, -t.x,
				(2.0f * (xy + wz)) * s.x, (1.0f - 2.0f * (x2 + z2)) * s.y, (2.0f * (yz - wx)) * s.z, -t.y,
				(2.0f * (xz - wy)) * s.x, (2.0f * (yz + wx)) * s.y, (1.0f - 2.0f * (x2 + y2)) * s.z, t.z,
				0, 0, 0, 1 };
		}
		inline static void view(mat4f& m, const vec3f& t, const quatf& r, const vec3f& s) {
			const float x = r.x, y = r.y, z = r.z, w = r.w,
				x2 = x * x, y2 = y * y, z2 = z * z, xy = x * y, xz = x * z, yz = y * z,
				wx = w * x, wy = w * y, wz = w * z;

			m.m00 = (1.0f - 2.0f * (y2 + z2)) * s.x; m.m01 = (2.0f * (xy - wz)) * s.y; m.m02 = (2.0f * (xz + wy)) * s.z; m.m03 = -t.x;
			m.m10 = (2.0f * (xy + wz)) * s.x; m.m11 = (1.0f - 2.0f * (x2 + z2)) * s.y; m.m12 = (2.0f * (yz - wx)) * s.z; m.m13 = -t.y;
			m.m20 = (2.0f * (xz - wy)) * s.x; m.m21 = (2.0f * (yz + wx)) * s.y; m.m22 = (1.0f - 2.0f * (x2 + y2)) * s.z; m.m23 = t.z;
			m.m30 = 0; m.m31 = 0; m.m32 = 0; m.m33 = 1;
		}
		inline static constexpr mat4f orthographic(const float& n /*near*/, const float& f /*far*/,
			const float& l /*left*/, const float& r /*right*/, const float& t /*top*/, const float& b /*bottom*/, const float& s = 1 /*size*/) {
			return {
				2 / (r - l) * s, 0, 0, -((r + l) / (r - l)), // (1-1)/(1+1)
				0, 2 / (t - b) * s, 0, -((t + b) / (t - b)),
				0, 0, -2 / (f - n) * s, -((f + n) / (f - n)),
				0, 0, 0, 1 };
		}
		inline static void orthographic(mat4f& m, const float& n /*near*/, const float& f /*far*/,
			const float& l /*left*/, const float& r /*right*/, const float& t /*top*/, const float& b /*bottom*/, const float& s = 1 /*size*/)
		{
			m.m00 = 2 / (r - l) * s; m.m01 = 0; m.m02 = 0; m.m03 = -((r + l) / (r - l));
			m.m10 = 0; m.m11 = 2 / (t - b) * s; m.m12 = 0; m.m13 = -((t + b) / (t - b));
			m.m20 = 0; m.m21 = 0; m.m22 = -2 / (f - n) * s; m.m23 = -((f + n) / (f - n));
			m.m30 = 0; m.m31 = 0; m.m32 = 0; m.m33 = 1;
		}
		inline static constexpr mat4f perspective(const float& n /*near*/, const float& f /*far*/,
			const float& l /*left*/, const float& r /*right*/, const float& t /*top*/, const float& b /*bottom*/)
		{
			return {
				(2 * n) / (r - l), 0, (r + l) / (r - l), 0,
				0, (2 * n) / (t - b), (t + b) / (t - b), 0,
				0, 0, (f + n) / (n - f), (2 * f * n) / (n - f),
				0, 0, -1, 0 };
		}
		inline static void perspective(mat4f& m, const float& n /*near*/, const float& f /*far*/,
			const float& l /*left*/, const float& r /*right*/, const float& t /*top*/, const float& b /*bottom*/) {
			m.m00 = (2 * n) / (r - l); m.m01 = 0; m.m02 = (r + l) / (r - l); m.m03 = 0;
			m.m10 = 0; m.m11 = (2 * n) / (t - b); m.m12 = (t + b) / (t - b); m.m13 = 0;
			m.m20 = 0; m.m21 = 0; m.m22 = -(f + n) / (f - n); m.m23 = (-2 * f * n) / (f - n);
			m.m30 = 0; m.m31 = 0; m.m32 = -1; m.m33 = 0;
		}
	};
}