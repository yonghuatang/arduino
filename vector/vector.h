#ifndef VECTOR_H
#define VECTOR_H

#include <Arduino.h>
#include <math.h>

// Vector algebra in three-dimensional Euclidean space
class vector {
	private:
		float x, y, z;

	public:
		vector() : x{0}, y{0}, z{0} {}

		vector(float i, float j, float k) : x{i}, y{j}, z{k} {}

        //
        float getX() const;

        //
        float getY() const;

        //
        float getZ() const;

        //
        void setX(float a);

        //
        void setY(float b);

        //
        void setZ(float c);

        // Operator overloading '+'
        vector operator+(vector other) {
            vector v_new(this->x + other.getX(), this->y + other.getY(), this->z + other.getZ());
            return v_new;
        }

        //
        void normalise();

		// Find the magnitude (or norm) of the vector
		float mag() const;

		//
		float distance(vector other) const;

        //
        float dot(vector other) const;

        //
        vector cross(vector other) const;
};

#endif  // VECTOR_H
