#include "vector.h"

float vector::getX() const {
    return this->x;
}

float vector::getY() const {
    return this->y;
}

float vector::getZ() const {
    return this->z;
}

void vector::setX(float a) {
    this->x = a;
}

void vector::setY(float b) {
    this->y = b;
}

void vector::setZ(float c) {
    this->z = c;
}

//vector vector::operator+(vector self, vector other) {
//    vector v_new(self.getX() + other.getX(), self.getY() + other.getY(), self.getZ() + other.getZ());
//    return v_new;
//}

void vector::normalise() {
    float prevMag = this->mag();  // original magnitude of the vector
    this->x /= prevMag;
    this->y /= prevMag;
    this->z /= prevMag;
}

float vector::mag() const {
    return pow(this->x * this->x + this->y * this->y + this->z * this->z, 0.5);
}

float vector::distance(vector other) const {
    float delta_x, delta_y, delta_z;
    delta_x = other.getX() - this->x;
    delta_y = other.getY() - this->y;
    delta_z = other.getZ() - this->z;
    return pow(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z, 0.5);   
}

float vector::dot(vector other) const {
//    return this->;
}
