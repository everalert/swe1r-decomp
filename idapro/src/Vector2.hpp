#pragma once
#include <cmath>

namespace vec2 {

	struct Vector2
	{
		float x;
		float y;

		float magnitude() {
			return sqrt(x*x + y*y);
		}

		float magnitude_squared() {
			return x*x + y*y;
		}

		bool normalize() {
			float mag = magnitude();
			if (mag <= 0.0001f) return false; // don't divide by 0
			x /= mag;
			y /= mag;
			return true;
		}

		void add(Vector2 vec2) {
			x += vec2.x;
			y += vec2.y;
		}
		
		void add(float num) {
			x += num;
			y += num;
		}

		float sum() {
			return x+y;
		}

		void mult(Vector2 vec2) {
			x *= vec2.x;
			y *= vec2.y;
		}

		void mult(float num) {
			x *= num;
			y *= num;
		}

		void div(Vector2 vec2) {
			x /= vec2.x;
			y /= vec2.y;
		}

		void div(float num) {
			x /= num;
			y /= num;
		}
	};

	// ADD
	
	Vector2 operator +(Vector2 vec2a, Vector2 vec2b) {
		return { vec2a.x + vec2b.x, vec2a.y + vec2b.y };
	}
	Vector2& operator +=(Vector2& vec2a, Vector2 vec2b) {
		return { vec2a.x + vec2b.x, vec2a.y + vec2b.y };
	}
	Vector2 operator +(Vector2 vec2a, float num) {
		return { vec2a.x + num, vec2a.y + num };
	}
	Vector2& operator +=(Vector2& vec2a, float num) {
		return { vec2a.x + num, vec2a.y + num };
	}
	Vector2 operator +(float num, Vector2 vec2a) {
		return { vec2a.x + num, vec2a.y + num };
	};

	// SUBTRACT
	
	Vector2 operator -(Vector2 vec2a, Vector2 vec2b) {
		return { vec2a.x - vec2b.x, vec2a.y - vec2b.y };
	}
	Vector2& operator -=(Vector2& vec2a, Vector2 vec2b) {
		return { vec2a.x - vec2b.x, vec2a.y - vec2b.y };
	}
	Vector2 operator -(Vector2 vec2a, float num) {
		return { vec2a.x - num, vec2a.y - num };
	}
	Vector2& operator -=(Vector2& vec2a, float num) {
		return { vec2a.x - num, vec2a.y - num };
	}
	Vector2 operator -(float num, Vector2 vec2a) {
		return { vec2a.x - num, vec2a.y - num };
	};

	// MULTIPLYING


	Vector2 operator *(Vector2 vec2a, Vector2 vec2b) {
		return { vec2a.x * vec2b.x, vec2a.y * vec2b.y };
	};
	Vector2& operator *=(Vector2& vec2a, Vector2 vec2b) {
		return { vec2a.x * vec2b.x, vec2a.y * vec2b.y };
	};
	Vector2 operator *(Vector2 vec2a, float num) {
		return { vec2a.x * num, vec2a.y * num };
	};
	Vector2& operator *=(Vector2& vec2a, float num) {
		return { vec2a.x * num, vec2a.y * num };
	};
	Vector2 operator *(float num, Vector2 vec2a) {
		return { vec2a.x * num, vec2a.y * num };
	};

	// DIVISION

	Vector2 operator /(Vector2 vec2a, Vector2 vec2b) {
		return { vec2a.x / vec2b.x, vec2a.y / vec2b.y };
	};
	Vector2& operator /=(Vector2& vec2a, Vector2 vec2b) {
		return { vec2a.x / vec2b.x, vec2a.y / vec2b.y };
	};
	Vector2 operator /(Vector2 vec2a, float num) {
		return { vec2a.x/num, vec2a.y/num };
	};
	Vector2& operator /=(Vector2& vec2a, float num) {
		return { vec2a.x/num, vec2a.y/num };
	};
	Vector2 operator /(float num, Vector2 vec2a) {
		return { vec2a.x/num, vec2a.y/num };
	};

	// FUNCTIONS

	float sum(Vector2 vec2) {
		return vec2.x+vec2.y;
	}

	float magnitude(Vector2 vec2) {
		return sqrt(vec2.x*vec2.x + vec2.y*vec2.y);
	}

	float magnitude_squared(Vector2 vec2) {
		return vec2.x*vec2.x + vec2.y*vec2.y;
	}

	Vector2 normalize(Vector2 vec2) {
		float mag = magnitude(vec2);
		return (mag >= 0.0001f) ? vec2/mag : Vector2({0.0f,0.0f});
	}
}