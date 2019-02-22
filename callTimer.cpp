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
	Dumby method for clearing the terminal screen

	@param nothing
	@return void method
 */
void ClearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void CommandLineSwitchUI()
{

}

void CommandLineView()
{

}

void CommandLineController() 
{

}

void MenuDrivenUI() 
{

}

void MenuDrivenView() 
{

}

void MenuDrivenController() 
{

}

void callTimerModel()
{

}

double createThreads(repititions) 
{
	double totalThreadTime;
	NanoTimer threadTimer;
	pthread_t pthread[repititions];
	int args[repititions];
	for( int i=0; i< repititions; i++ )
	{
		threadTimer.start();
		args[i] = i;
		pthread_create(&pthread[i], NULL, &printTID,  &args[i]);
		threadTimer.stop();
		// Add total time to the sum
		totalThreadTime += threadTimer.getTotalTime();
		threadTimer.reset();
	}
	for ( int i = 0; i < repititions; i++) {
		pthread_join(pthread[i], NULL);
	}
	double averageTime = totalThreadTime/repititions;
	cout << "The average time to create a Thread is: " <<
			averageTime << endl;
	return averageTime;
}

double createProcesses(repititions) 
{
	double totalProcessTime;
	NanoTimer processTimer;
	for( int i=0; i< repititions; i++ )
	{
		processTimer.start();
		if (fork() == 0)
		{
			//child process
			cout << "Hello from the child process (PID = " << getpid() <<")\n";
			exit(0);
		}
		processTimer.stop();
		// Add total time to the sum
		totalProcessTime += processTimer.getTotalTime();
		processTimer.reset();
	}
	double averageTime = totalProcessTime/repititions;
	cout << "The average time to create a Process is: " <<
			averageTime << endl;
	return averageTime;
}

int main ( int argc, char **argv )
{
	int selection = NULL;
	bool noSelection = true;
	while(noSelection) 
	{

    	cout << "Please select whether you wish to use a command line interface or a text based:" << endl;
		cout << "Enter:" << endl;
		cout << "0: To terminate the program" << endl;
		cout << "1: Text-based command-line-switch-driven user interface" << endl;
		cout << "2: Text-based menu-driven user interface" << endl;
		cin >> selection;
		if (selection != NULL) 
		{
			if ( (selection == 0) || (selection == 1) || (selection == 2)
			{
				noSelection = false;
			} else
			{
				cout << "Incorrect input, please try again" << endl; 
				ClearScreen();
			} 
		} 
	}

	// Terminate the program
	if (selection == 0) 
	{
		exit(0);
	} else if ( selection == 1) 
	{
		CommandLineSwitchUI();
	} else
	{
		MenuDrivenUI();
	}

	return 0;
}