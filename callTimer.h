/*
 * Title: callTimer.h
 * Purpose: Creates header file for testing pthread and fork
 * Author: Micah Bonewell
 * Started on: Feb 11, 2019
 * Finished on: Feb 13, 2019
 * Class: CS 232
 * Professor: Joel Adams
 */

#ifndef CALLTIMER_H_
#define CALLTIMER_H_

#include "NanoTimer.h" // Timer class
#include <algorithm> // finds strings in vector

class callTimer {
public:
	callTimer();
	void* printTID(void* life);
	int main(int argc, char *argv[]);

	virtual ~callTimer();
};



#endif /* CALLTIMER_H_ */
