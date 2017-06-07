/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 6 Recursion
 * Class         : CS 301
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "NodeType.h"

using namespace std;

void addToEnd(NodeType *&curPtr, int &value);
void deleteAtEnd(NodeType *&curPtr);
void searchAndDelete(NodeType *&curPtr, int &value);
void PrintList(NodeType *curPtr, int index);
void PrintListBackWards(NodeType *curPtr, int index);
void GenerateList(NodeType *&head);

bool isEmpty(NodeType *head);

char menuPrompt(const string MENU_PROMPT);
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX);			// IN & OUT		- maximum optio

#endif /* HEADER_H_ */
