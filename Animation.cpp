/************************************************
Filename: Animation.cpp
Version:1.0
Author:Phillip Clarke
Student number: 040832994
Assignment Number: 1
Assignment Name: Assignment 1
Course Name: C++ programming
Course Code: CST8219
Lab Section Number: 301
Professor's Name: Surbhi Bahri
Due Date: October 12th, 2019
Submission Date: October 8th, 2019
List of source files: Animation.cpp, Frame.cpp, Animation.h, Frame.h, Ass1.cpp
Purpose: Until the User quits the program. 
It will read a valid response from the keyboard in 
order to go through the process of either creating 
a frame of animation, editing a frame, 
displaying all frames or even delete a frame.
**************************************************/
#include <iostream>
#include <string>
#include "Frame.h"
#include "Animation.h"
using namespace std;
#pragma once
/******************************************************************************
Function name: Animation (default constructor)
Purpose: Purpose is to set Animation parameters
In parameters: N/A
Out parameters: N/A
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
Animation::Animation()
{
	Animation::animationName = new char[strlen("Animation 1") +1]; /*Allocates space on the heap for "Animation 1"*/
	strcpy_s(Animation::animationName, 12, "Animation 1"); /*Copies "Animation 1" into the location as well as the null terminator character*/
	Animation::frames = NULL;
}
/******************************************************************************
Function name: Animation (Destructor)
Purpose: Purpose is to delete the space allocated and frames created upon closing to avoid memory leaks
In parameters: N/A
Out parameters: N/A
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
Animation::~Animation()
{
	while (Animation::frames != NULL)/*Runs DeleteFrame() until all frames created are removed*/
	{
		DeleteFrame();
	}
	delete Animation::animationName; /*Clears space allocated for animationName*/
}
/******************************************************************************
Function name: InsertFrame
Purpose: purpose is to add a frame to the list
In parameters: N/A
Out parameters: void
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
void Animation::InsertFrame()
{
	char* tempName = new char[100];/*Creates a temporary name variable*/
	cout << "Insert a Frame in the Animation\nPlease enter the Frame frameName: ";
	cin >> tempName; /*Prompts the user to input a name*/
	if (Animation::frames == NULL) /*Checks if it's the first frame being added*/
	{
		Frame* tempFrame = new Frame; /*Creates a Frame object*/
		char* newName = new char[strlen(tempName)+1]; /*Creates a variable newName that holds the perfect amount of space for the size of tempname and the null terminator character*/
		strcpy_s(newName,strlen(tempName)+1, tempName);/*Copies the name at tempname into newName*/
		tempFrame->GetFrameName() = newName; /*Sets the new name in the frame*/
		Animation::frames = tempFrame; /*Sets the Animation::frames pointer to the tempFrame pointer*/
		
	}
	else /*This happens if there's already more than 1 frame in the animation*/
	{
		Frame* tempFrame = new Frame;
		char* newName = new char[strlen(tempName)+1];
		strcpy_s(newName, strlen(tempName) + 1, tempName);
		tempFrame->GetFrameName() = newName;
		tempFrame->GetpNext() = Animation::frames; /*Adds the current head to the next of the new frame*/
		Animation::frames = tempFrame;/*Sets the head to the new frame location*/
	}
	delete[] tempName;/*Frees allocated heap space for the temporary name*/
}
/******************************************************************************
Function name: Edit
Purpose: purpose is to edit a frame in the list
In parameters: N/A
Out parameters: void
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
void Animation::EditFrame()
{
	int counter=0, index = 0; /*Creates a counter and index variable for logic*/
	if (Animation::frames!=NULL)/*Checks if there are any frames in the animation*/
	{
		Frame* tempFrame = Animation::frames;/*Creates a frame pointer to hold the head of the animation*/
		while (Animation::frames != NULL) /*Loop to get the number of frames in the animation*/
		{
			counter++;
			Animation::frames = Animation::frames->GetpNext();
		}
		Animation::frames = tempFrame; /*Restores the head back to its original pointer after the loop*/
		cout << "There are " << counter << " Frame(s) in the list. Please specify the index (<=" << counter - 1 << ") to edit at : ";
		cin >> index; /*Prompts the user for an index to edit*/
		
			if (index >= 0 && index < counter)
			{
				for (int x = index; x > 0; x--) /*Navigates through the animation to the index specified by the user*/
				{
					Animation::frames = Animation::frames->GetpNext();
				}
				cout << "The name of this Frame is " << Animation::frames->GetFrameName() << ". What do you wish to replace it with?" << endl;
				char* tempName = new char[100]; /*Creates a new temporary name to hold new name edit*/
				cin >> tempName; /*Prompts the user for the new temporary name*/
				delete[] Animation::frames->GetFrameName(); /*Removes the current space allocated for the framename*/
				Animation::frames->GetFrameName() = new char[strlen(tempName) + 1];/*Allocates a new amount of space in the heap for the new edit name and a null terminator character*/
				strcpy_s(Animation::frames->GetFrameName(), strlen(tempName) + 1, tempName); /*Copies the new edit name into the location of getframename*/
				delete[] tempName; /*Removes the space allocated for the temporary name*/
				Animation::frames = tempFrame; /*Restores the head back to its original pointer after the above logic*/
			}
		else/*Runs if user enters a number outisde of the index bounds*/
		{
			cout << "Incorrect index entered, returning to menu." << endl;
		}

	}
	else /*Runs when there are no frames to edit*/
	{
		cout << "No frames to edit." << endl;
	}
}
/******************************************************************************
Function name: DeleteFrame
Purpose: purpose is to remove the last frame from the list
In parameters: N/A
Out parameters: void
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
void Animation::DeleteFrame()
{
	
	if (Animation::frames != NULL)/*Checks if there are any frames in the animation*/
	{
		Frame* tempFrame = Animation::frames;/*Creates a frame pointer to hold the head of the animation*/
		if (Animation::frames->GetpNext() != NULL)/*Checks if there are only 2 frames in the animation*/
		{
			if (Animation::frames->GetpNext()->GetpNext() != NULL) /*Checks if there are many frames in the animation*/
			{
				while (Animation::frames->GetpNext()->GetpNext() != NULL) /*Loop that navigates to the second last frame*/
				{
					Animation::frames = Animation::frames->GetpNext();
				}
				delete[] Animation::frames->GetpNext()->GetFrameName(); /*Removes tail frames allocated name space*/
				delete Animation::frames->GetpNext();/*Removes the tail from the animation*/
				Animation::frames->GetpNext() = NULL; /*Sets the tail to NULL*/
				Animation::frames = tempFrame; /*Restores the head back to its original location*/
			}
			else /*To be run if there are only 2 frames*/
			{
				delete[] Animation::frames->GetpNext()->GetFrameName();
				delete Animation::frames->GetpNext();
				Animation::frames->GetpNext() = NULL;
				Animation::frames = tempFrame;
			}
		}
		else/*To be run if there is only 1 frame*/
		{
			delete[] Animation::frames->GetFrameName();
			delete Animation::frames;
			Animation::frames = NULL;
		}	
	}
	else/*Runs if there are no frames in the animation*/
	{
		cout << "No frames to remove." << endl;
	}
	
}

/******************************************************************************
Function name: ReportAnimation
Purpose: purpose is to print the list
In parameters: N/A
Out parameters: void
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
void Animation::ReportAnimation()
{
	if (Animation::frames != NULL)/*Checks if there are any frames in the animation*/
	{
		int counter = 0;
		Frame* tempFrame = Animation::frames;/*Creates a frame pointer to hold the head of the animation*/
		while (Animation::frames != NULL) /*Loop that navigates from the head to the tail of the animation and printing the contents*/
		{
			cout << "Frame #" << counter<< " file name = "<<Animation::frames->GetFrameName() << endl;
			Animation::frames = Animation::frames->GetpNext();
			counter++;
		}
		Animation::frames = tempFrame; /*Sets the head pointer back to the original location*/
	}
	else/*Runs when there are no frames in the animation*/
	{
		cout << "There are no frames to display." << endl;
	}
}