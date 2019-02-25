/*
 * Title: commandLineView.h
 * Purpose: Creates header file for the Command Line Inteface
 * Author: Micah Bonewell
 * Started on: Feb 25, 2019
 * Finished on: Feb 26, 2019
 * Class: CS 232
 * Professor: Joel Adams
 */

#ifndef COMMANDLINEVIEW_H_
#define COMMANDLINEVIEW_H_

#include <algorithm> // finds strings in vector
#include <string> // for string class
#include <stdio.h>

class commandLineView {
public:
	commandLineView();
	void outputProcessTime(double processTime);
    void outputThreadTime(double threadTime);
};

/* Constructor class for commandLineView.
 * 
 */
inline
commandLineView::commandLineView() {
	cout << "You're using the command Line View" << endl;
}
/* void method for outputing process results
 * 
 */
inline
void commandLineView::outputProcessTime(double processTime)
{
    cout << "The average time to create a Process is: " <<
			processTime << endl; 
}
/* void method for outputing thread results
 * 
 */
inline
void commandLineView::outputThreadTime(double threadTime)
{
    cout << "The average time to create a Thread is: " <<
			threadTime << endl; 
}
#endif /* COMMANDLINEVIEW_H_ */