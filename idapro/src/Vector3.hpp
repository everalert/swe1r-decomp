#pragma once
#include <cmath>

namespace vec3 {

	struct Vector3
	{
		float x;
		float y;
		float z;

		float magnitude() {
			return sqrt(x*x + y*y + z*z);
		}

		float magnitude_squared() {
			return x*x + y*y + z*z;
		}

		bool normalize() {
			float mag = magnitude();
			if (mag <= 0.0001f) return false; // don't divide by 0
			x /= mag;
			y /= mag;
			z /= mag;
			return true;
		}

		void add(Vector3 vec3) {
			x += vec3.x;
			y += vec3.y;
			z += vec3.z;
		}
		
		void add(float num) {
			x += num;
			y += num;
			z += num;
		}

		float sum() {
			return x+y+z;
		}

		void mult(Vector3 vec3) {
			x *= vec3.x;
			y *= vec3.y;
			z *= vec3.z;
		}

		void mult(float num) {
			x *= num;
			y *= num;
			z *= num;
		}

		void div(Vector3 vec3) {
			x /= vec3.x;
			y /= vec3.y;
			z /= vec3.z;
		}

		void div(float num) {
			x /= num;
			y /= num;
			z /= num;
		}
	};

	// ADD
	
	Vector3 operator +(Vector3 vec3a, Vector3 vec3b) {
		return { vec3a.x + vec3b.x, vec3a.y + vec3b.y, vec3a.z + vec3b.z };
	}
	Vector3& operator +=(Vector3& vec3a, Vector3 vec3b) {
		return { vec3a.x + vec3b.x, vec3a.y + vec3b.y, vec3a.z + vec3b.z };
	}
	Vector3 operator +(Vector3 vec3a, float num) {
		return { vec3a.x + num, vec3a.y + num, vec3a.z + num };
	}
	Vector3& operator +=(Vector3& vec3a, float num) {
		return { vec3a.x + num, vec3a.y + num, vec3a.z + num };
	}
	Vector3 operator +(float num, Vector3 vec3a) {
		return { vec3a.x + num, vec3a.y + num, vec3a.z + num };
	};

	// SUBTRACT
	
	Vector3 operator -(Vector3 vec3a, Vector3 vec3b) {
		return { vec3a.x - vec3b.x, vec3a.y - vec3b.y, vec3a.z - vec3b.z };
	}
	Vector3& operator -=(Vector3& vec3a, Vector3 vec3b) {
		return { vec3a.x - vec3b.x, vec3a.y - vec3b.y, vec3a.z - vec3b.z };
	}
	Vector3 operator -(Vector3 vec3a, float num) {
		return { vec3a.x - num, vec3a.y - num, vec3a.z - num };
	}
	Vector3& operator -=(Vector3& vec3a, float num) {
		return { vec3a.x - num, vec3a.y - num, vec3a.z - num };
	}
	Vector3 operator -(float num, Vector3 vec3a) {
		return { vec3a.x - num, vec3a.y - num, vec3a.z - num };
	};

	// MULTIPLYING


	Vector3 operator *(Vector3 vec3a, Vector3 vec3b) {
		return { vec3a.x * vec3b.x, vec3a.y * vec3b.y, vec3a.z * vec3b.z };
	};
	Vector3& operator *=(Vector3& vec3a, Vector3 vec3b) {
		return { vec3a.x * vec3b.x, vec3a.y * vec3b.y, vec3a.z * vec3b.z };
	};
	Vector3 operator *(Vector3 vec3a, float num) {
		return { vec3a.x * num, vec3a.y * num, vec3a.z * num };
	};
	Vector3& operator *=(Vector3& vec3a, float num) {
		return { vec3a.x * num, vec3a.y * num, vec3a.z * num };
	};
	Vector3 operator *(float num, Vector3 vec3a) {
		return { vec3a.x * num, vec3a.y * num, vec3a.z * num };
	};

	// DIVISION

	Vector3 operator /(Vector3 vec3a, Vector3 vec3b) {
		return { vec3a.x / vec3b.x, vec3a.y / vec3b.y, vec3a.z / vec3b.z };
	};
	Vector3& operator /=(Vector3& vec3a, Vector3 vec3b) {
		return { vec3a.x / vec3b.x, vec3a.y / vec3b.y, vec3a.z / vec3b.z };
	};
	Vector3 operator /(Vector3 vec3, float num) {
		return { vec3.x/num, vec3.y/num, vec3.z/num };
	};
	Vector3& operator /=(Vector3& vec3, float num) {
		return { vec3.x/num, vec3.y/num, vec3.z/num };
	};
	Vector3 operator /(float num, Vector3 vec3) {
		return { vec3.x/num, vec3.y/num, vec3.z/num };
	};

	// FUNCTIONS

	float sum(Vector3 vec3) {
		return vec3.x+vec3.y+vec3.z;
	}

	float magnitude(Vector3 vec3) {
		return sqrt(vec3.x*vec3.x + vec3.y*vec3.y + vec3.z*vec3.z);
	}

	float magnitude_squared(Vector3 vec3) {
		return vec3.x*vec3.x + vec3.y*vec3.y + vec3.z*vec3.z;
	}

	Vector3 normalize(Vector3 vec3) {
		float mag = magnitude(vec3);
		return (mag >= 0.0001f) ? vec3/mag : Vector3({0.0f,0.0f,0.0f});
	}
}