/*
 * Vec2d.cpp
 *
 *  Created on: Dec. 4, 2022
 *      Author: uzair
 */



#include "Vec2d.h"
#include "utils.h"
#include <cassert>
#include <cmath>


const Vec2d Vec2d::Zero;



std::ostream& operator<<(std::ostream& consoleOut, const Vec2d& vec){

	std::cout << "X: " << vec.mX << " Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vec2d operator*(float scalar, const Vec2d& vec){

	return vec * scalar;
}

bool Vec2d::operator==(const Vec2d& vec2) const {

	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);

}

bool Vec2d::operator!=(const Vec2d& vec2) const {

	return !(*this == vec2);
}

Vec2d Vec2d::operator-() const{

	//returns a new vector thats negated, that is why this function takes no params and is const because it doesnt change
	//the current class, it just uses the member variables, negates them and creates a new vector.
	return Vec2d(-mX,-mY);
}

Vec2d Vec2d::operator*(float scale) const{

	return Vec2d(scale * mX, scale * mY);
}

Vec2d Vec2d::operator/(float scale) const {

	assert(fabsf(scale)> EPSILON);

	return Vec2d(mX/scale, mY/scale);
}

Vec2d& Vec2d::operator/=(float scale){

	assert(fabsf(scale)> EPSILON);

	*this = *this/scale;

	return *this;


}

Vec2d& Vec2d::operator*=(float scale){

	*this =*this * scale;

	return *this;
}


//Vector addition and subtraction
Vec2d Vec2d::operator+(const Vec2d& vec) const{

	return Vec2d(mX+vec.mX, mY+vec.mY);

}
Vec2d Vec2d::operator-(const Vec2d& vec) const{

	return Vec2d(mX-vec.mX,mY-vec.mY);

}
Vec2d& Vec2d::operator+=(const Vec2d& vec){

	*this = *this + vec;
	return *this;

}
Vec2d& Vec2d::operator-=(const Vec2d& vec){

	*this = *this + vec;
	return *this;
}

float Vec2d::Mag() const{

	return sqrt(Mag2());
}

float Vec2d::Mag2() const{

	return mX*mX +mY*mY;
}


Vec2d Vec2d::GetUnitVec() const{

	float mag =Mag();

	if(mag > EPSILON){

		return *this/mag;
	}

	return Vec2d::Zero;
}

Vec2d& Vec2d::Normalize(){

	float mag =Mag();

		if(mag > EPSILON){

			 *this/=mag;
		}

		return *this;
}

float Vec2d::Distance(const Vec2d& vec) const {

	return (vec - *this).Mag();
}


float Vec2d::Dot(const Vec2d& vec) const{

	return mX * vec.mX + mY*vec.mY;
}

Vec2d Vec2d::ProjectOnto(const Vec2d& vec2) const{

	float mag2 = vec2.Mag2();
	if(IsLessThanOrEqual(mag2,EPSILON)){

		return Vec2d::Zero;

	}

	float dot = Dot(vec2);

	return vec2 * (dot/mag2);

}

float Vec2d::AngleBetween(const Vec2d& vec2) const{

	return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));
}

Vec2d Vec2d::Reflect(const Vec2d& normal) const{

	//v - 2(v dot n)n

	return *this -2 * ProjectOnto(normal);
}

void Vec2d::Rotate(float angle , const Vec2d& aroundPoint){

	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2d thisVec(mX,mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mY * sine + thisVec.mY * cosine;


	Vec2d rot = Vec2d(xRot,yRot);

	*this = rot + aroundPoint;

}

Vec2d Vec2d::RotationResult(float angle,const Vec2d& aroundPoint) const{

	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2d thisVec(mX,mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mY * sine + thisVec.mY * cosine;


	Vec2d rot = Vec2d(xRot,yRot);

	return  rot + aroundPoint;


}








































