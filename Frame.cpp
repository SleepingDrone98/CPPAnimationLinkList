/************************************************
Filename: Frame.cpp
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
Purpose: Holds the default constructor and destructor
**************************************************/
#include <iostream>
#include <string>
#include "Frame.h"
using namespace std;
#pragma once
/******************************************************************************
Function name: Frame (default constructor)
Purpose: Purpose is to initialize the Frame members
In parameters: N/A
Out parameters: N/A
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
Frame::Frame()
{
	Frame::frameName = NULL;
	Frame::pNext = NULL;
}
/******************************************************************************
Function name: Frame (default destructor)
Purpose: Is to free allocated space but I didn't do it here
In parameters: N/A
Out parameters: N/A
Version: 1.0
Author: Phillip Clarke
******************************************************************************/
Frame::~Frame()
{

}