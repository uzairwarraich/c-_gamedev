/*
 * Vec2d.h
 *
 *  Created on: Dec. 4, 2022
 *      Author: uzair
 */
#ifndef VEC2D_H_
#define VEC2D_H_
#include <iostream>
class Vec2d{

public:

	static const Vec2d Zero;

	Vec2d():Vec2d(0,0){

	}
	Vec2d(float x, float y):mX(x),mY(y){

	}

	inline void SetX(float x){
		mX = x;
	}
	inline void SetY(float y){mY=y;}
	inline float GetX()const {return mX;}
	inline float GetY()const {return mY;}


	//friend keyword can help other class (operator <<) access private variables of this class
	// oeprator overloading can help us use the cout << vec (vec2d object) directly rather than having a display function
	friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2d& vec);

	bool operator==(const Vec2d& vec2) const;
	bool operator!=(const Vec2d& vec2) const;

	//returns a new vector thats negated, that is why this function takes no params and is const because it doesnt change
		//the current class, it just uses the member variables, negates them and creates a new vector.
	//see implementation for details
	Vec2d operator-() const;

	Vec2d operator*(float scale) const;
	Vec2d operator/(float scale) const;

	Vec2d& operator*=(float scale);
	Vec2d& operator/=(float scale);

	//this is because 3* vec doesnt work and vec* 3 works
	friend Vec2d operator*(float scalar, const Vec2d& vec);


	//Vector addition and subtraction
	Vec2d operator+(const Vec2d& vec) const;
	Vec2d operator-(const Vec2d& vec) const;
	Vec2d& operator+=(const Vec2d& vec);//no const because this will change the original vector and give a new one
	Vec2d& operator-=(const Vec2d& vec);
    //The functions that change the original vector have a return type of a reference(&) and are not passed by value


	//magnitude of vectors
	float Mag() const;
	float Mag2() const;

	Vec2d GetUnitVec() const;

	//Normalizes the vector and passes itself back thats why Vec2d& is the return type
	Vec2d& Normalize();


	float Distance(const Vec2d& vec) const;

	float Dot(const Vec2d& vec) const;



	Vec2d ProjectOnto(const Vec2d& vec2) const;

	float AngleBetween(const Vec2d& vec2) const;

	Vec2d Reflect(const Vec2d& normal) const;

	void Rotate(float angle , const Vec2d& aroundPoint);

	Vec2d RotationResult(float angle,const Vec2d& vec) const;


private:
	float mX,mY;
};





#endif /* VEC2D_H_ */
