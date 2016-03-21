/*
 * Factory.h
 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#include "StationInterface.h"
#pragma once

/*
	createStation()
*/
class Factory
{
public:
	static StationInterface* createStation();
};

//=======================================================================================
