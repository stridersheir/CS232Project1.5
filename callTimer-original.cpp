/*
 * Title: callTimer.cpp
 * Purpose: Creates Main function which is a console application for testing the creation time of threads and processes
 * Author: Micah Bonewell
 * Started on: Feb 11, 2019
 * Finished on: Feb 13, 2019
 * Class: CS 232
 * Professor: Joel Adams
 */

#include "callTimer.h"
#include <string> // for string class
#include "stdlib.h" // atoi
#include <unistd.h> // fork
#include <pthread.h> // thread
#include <stdio.h>



using namespace std;

/*
 * Loop function for using pthread_create
 * Input: void* life, random variable, unused
 * Output: String to console with thread ID
 */
void* printTID(void *id)
{
	int myId =*(int*) id;
	//cout << "Hello from the child process (TID = " << pthread_self() <<")" << endl;
	printf("Hello from the child process (TID = %i) \n", myId);
	// terminate the thread
	pthread_exit(NULL);
}
/*
 * Main Function
 * Input: arguments
 * Output: average time for thread creation and process creation
 */
int main ( int argc, char **argv )
{

	bool initializeP = false;  // Whether fork() will be used.
	bool initializeT = false;  // Whether pthread_create() will be used.
	int repititions = 1; // variable for number of repeats
	double totalProcessTime = 0; // variable for total time from fork
	double totalThreadTime = 0; // variable for total time from pthread

	NanoTimer myTimer;
	// Make sure there are arguments passed
	if (argc<2)
	{
		cout << "Number of args is 0, please enter arguments to use the program.\n";
		cout << "The valid arguments are:\n" <<
						"-p\n"<< "-process\n"<<
						"-t\n"<< "-thread\n"
						<< "-rN\n";
		exit(1); // terminate the program
	}
	// Make sure there are no more than three arguments passed
	else if (argc>4)
	{
		cout << "Entered too many arguments.\n";
		cout << "The valid arguments are:\n" <<
				"-p\n"<< "-process\n"<<
				"-t\n"<< "-thread\n"
				<< "-rN\n";
		exit(1); // terminate the program
	}
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

	cout << endl << endl; // Blank Space for readability in console

	// if -p or -process is called
	if (initializeP)
	{
		for( int i=0; i< repititions; i++ )
		{
			myTimer.start();
			if (fork() == 0)
			{
				//child process
				cout << "Hello from the child process (PID = " << getpid() <<")\n";
				exit(0);
			}
			myTimer.stop();
			// Add total time to the sum
			totalProcessTime += myTimer.getTotalTime();
			myTimer.reset();
		}
		double averageTime = totalProcessTime/repititions;
		cout << "The average time to create a Process is: " <<
				averageTime << endl;
	}

	cout << endl << endl; // Blank Space for readability in console

	// if -t or -thread is called
	if (initializeT)
	{
		pthread_t pthread[repititions];
		int args[repititions];
		for( int i=0; i< repititions; i++ )
		{
			myTimer.start();
			args[i] = i;
			pthread_create(&pthread[i], NULL, &printTID,  &args[i]);
			myTimer.stop();
			// Add total time to the sum
			totalThreadTime += myTimer.getTotalTime();
			myTimer.reset();
		}
		for ( int i = 0; i < repititions; i++) {
        	pthread_join(pthread[i], NULL);
    	}
		double averageTime = totalThreadTime/repititions;
		cout << "The average time to create a Thread is: " <<
				averageTime << endl;
	}

	return 0;
}
