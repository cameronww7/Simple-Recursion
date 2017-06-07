/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 6 Recursion
 * Class         : CS 301
 ************************************************************************/


#include "header.h"
#include "NodeType.h"

/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	NodeType *head;   //First node in list
	char      option; //Users menu choice
	int       value;  //value to be stored

	head = NULL;

	option = menuPrompt("\n\tA for Add\n"
			   	   	      "\tD for Delete\n"
			   	   	      "\tS for Search & Delete\n"
			   	   	      "\tP for Print\n"
						  "\tB for Print Backwards\n"
						  "\tG for a Generated List\n"
						  "\tQ for Quit\n"
						  "\tEnter your Choice : ");

	while(option != 'Q')
	{
		switch(option)
		{
			//Adds to the front of the list
			case 'A' : value = NumberError("\tEnter any Integer "
										   "(between 0-1000): ",
											         0, 1000);
			       	   addToEnd(head, value);
				break;
			//Deletes from front or search and deletes
			case 'D' :	if(!isEmpty(head))
						{
							deleteAtEnd(head);
						}

				break;
			//Searched through linked list for an item
			case 'S' :	if(!isEmpty(head))
						{
							value = NumberError("\tEnter any Integer to be deleted: ",
											0, 1000);
							searchAndDelete(head, value);
						}
				break;
			//Prints the list unless its empty
			case 'P' : 	if(!isEmpty(head))
						{
							cout << "\n\t>> Printing List << \n";
							PrintList(head, 0);
						}
				break;
			case 'B' : 	if(!isEmpty(head))
						{
							cout << "\n\t>> Printing List Backwards << \n";
							PrintListBackWards(head, 6);
						}
				break;
			case 'G' : 	if(isEmpty(head))
						{
							cout << "\n\tCreating a Generated List with 5 Values\n";
						GenerateList(head);
						}
						else
						{
							cout << "\n\t>> List Must be Empty <<\n";
						}

				break;
		}

		option = menuPrompt("\n\tA for Add\n"
				   	   	      "\tD for Delete\n"
				   	   	      "\tS for Search & Delete\n"
				   	   	      "\tP for Print\n"
							  "\tB for Print Backwards\n"
							  "\tG for a Generated List\n"
							  "\tQ for Quit\n"
							  "\tEnter your Choice : ");
	}


	cout << "\n\nThank You, and Have a Wonderful Day";
	return 0;
}


void GenerateList(NodeType *&head)
{
	//Creates a List from 1-5 with values from 0-4 list must be empty first
	for(int index = 0; index < 5; index++)
	{
		NodeType* newNode;
		newNode = new NodeType;
		newNode->info = index;
		newNode->nextPtr = head;
		head = newNode;
	}
}

void addToEnd(NodeType *&curPtr, int &value)
{
	//adds to an empty list
	if(curPtr == NULL)
	{
		cout << "\n\tAdding value \"" << value << "\" to the end of the list\n";
		NodeType* newNode;
		newNode = new NodeType;
		newNode->info = value;
		newNode->nextPtr = NULL;
		curPtr = newNode;
	}
	// if not at the end it continues finding end
	else
	{
		addToEnd(curPtr->nextPtr,value);
	}
}

void deleteAtEnd(NodeType *&curPtr)
{
	// deletes from a 1 node list
	if(curPtr->nextPtr == NULL)
	{
		cout << "\n\tDeleting --> " << curPtr->info << endl;
		delete curPtr;
		curPtr = NULL;
	}
	//if not at the end it deletes it
	else
	{
		deleteAtEnd(curPtr->nextPtr);
	}
}

void searchAndDelete(NodeType *&curPtr, int &value)
{
	// checks and sees if were at the end and the value wasn't found
	if(curPtr == NULL)
	{
		cout << "\n\tThe Number " << value << " is not in the List\n";
	}
	// checks to see if its at the current value
	else if(curPtr->info == value)
	{
		cout << "\n\tDeleting --> " << value << endl;
		NodeType* removePtr;
		removePtr = curPtr;
		curPtr = curPtr->nextPtr;
		delete removePtr;
	}
	else
	{
		searchAndDelete(curPtr->nextPtr, value);
	}
}

void PrintListBackWards(NodeType *curPtr, int index)
{

	if(curPtr != NULL)
	{
		PrintListBackWards(curPtr->nextPtr, --index);

		cout << "\tIndex " << index << " : " <<  curPtr->info << endl;
	}
}


void PrintList(NodeType *curPtr, int index)
{
	if(curPtr != NULL)
	{
		cout << "\tIndex " << ++index << " : " <<  curPtr->info << endl;
		PrintList(curPtr->nextPtr, index);
	}
}


bool isEmpty(NodeType *head)
{
	bool empty = false;

	//checks and sees if the list is empty
	if(head == NULL)
	{
		cout << "\n\tList is Empty\n";
		empty = true;
	}
	return empty;
}


char menuPrompt(const string MENU_PROMPT)
{

	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	char option;					// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_PROMPT;
		cin.get(option);
		option = toupper(option);

		if (  option == 'A' || option == 'D' || option == 'P' ||
		      option == 'Q' || option == 'S' || option == 'B' ||
		      option == 'G')
		{
			someBool = true;
		}
		else
		{
			cout << "\n * Error *  Please Enter one choice Of A,D,P,B,Q \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(!someBool);

	return option;

}


/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}

