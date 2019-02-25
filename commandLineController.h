/*
 * Title: commandLineController.h
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
#include "commandLineView.h" // finds strings in vector
#include <string> // for string class
#include <stdio.h>

class commandLineController {
public:
	commandLineController(commandLineView view, callTimerModel model);
	int run(int argc, char **argv);
    void outputThreadTime(double threadTime);
};
private: 


/* Constructor class for commandLineController.
 * 
 */
inline
commandLineController::commandLineController(commandLineView view, callTimerModel model) {
	this.model = model;
    this.view = view;
}
/* 
 * void method for outputing process results
 */
inline
int commandLineController::run(int argc, char **argv)
{
    for( int i=1; i< argc; i++ )
	{
		string myString = std::string(argv[i]); // stand in for the item in the array
		string repeat = myString.substr(0,2); // if the process repeats, search for "-r"
		// if fork() needs to be called
		if ((myString == "-p") || (myString == "-process"))
		{
			initializeP= true;
			cout << "A process was initialized\n";
		}
		// if pthread needs to be called
		if ((myString == "-t" ) || ( myString == "-thread"))
		{
			initializeT= true;
			cout << "A thread was initialized\n";
		}
		// if the process is repeated
		if (repeat == "-r")
		{
			int pos = myString.find("r");
			// Copy substring after pos
			string times = myString.substr(pos + 1);
			int myRep = atoi( times.c_str() );
			if (myRep > 1)
			{
				repititions = myRep; // if the number of reps is greater than default replace
			}
			cout << "The number of reps are:" << repititions << "\n";
		}
		// Make sure there are no invalid arguments
		if (! ( (myString == "-p") || (myString == "-t") || (myString == "-thread")
				|| (myString == "-process") || (repeat == "-r") ) )
		{
			cout << "You entered an invalid argument\n" << endl;
			cout << "The valid arguments are:\n" <<
					"-p\n"<< "-process\n"<<
					"-t\n"<< "-thread\n"
					<< "-rN\n";
			exit(1); // terminate the program
		}
	}
}
/* 
 * void method for outputing thread results
 */
inline
void commandLineController::outputThreadTime(double threadTime)
{
    cout << "The average time to create a Thread is: " <<
			threadTime << endl; 
}
#endif /* COMMANDLINEVIEW_H_ */