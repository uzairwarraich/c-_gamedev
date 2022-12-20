/*
 * utils.cpp
 *
 *  Created on: Dec. 4, 2022
 *      Author: uzair
 */


#include "utils.h"
#include <cmath>




bool IsEqual(float x, float y){

	return fabsf(x-y) < EPSILON;
}


bool IsGreaterThanOrEqual(float x, float y){

	return x > y || IsEqual(x, y);


}

bool IsLessThanOrEqual(float x, float y){

	return x < y || IsEqual(x,y);
}
