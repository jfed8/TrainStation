/*
 * Factory.h
 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#include "Factory.h"
#include "StationInterface.h"
#include "Station.h"

using namespace std;


/*
    createStation()
*/
StationInterface* Factory::createStation()
{
    return new Station();
}
//=======================================================================================
