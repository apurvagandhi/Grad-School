/**********************************************************************
File name: school.cc
Name: Apurva Gandhi
Assignment: Assignment 8
Date: 04/27/2019
CSCI132
Professor: Saba Kadady
Purpose: Implementation of the school class (represents each school)
**********************************************************************/
#include "school.h"

/*****************************************************
Name: School (Constructor) 
Pre: None
Post: All the instance variables are intialized to 0
***************************************************/
School :: School()
{
	women = 0;
	rateAI = 0;
	rateSys = 0;
	rateTheory = 0;
	effectiveness = 0;
	ratePubs = 0;
	overallRating = 0;
}//end of school()

/***************************************************************************
Name: School (Constructor) 
Pre: The parameters are provided while creating the instance of the school
Post: Instance variables are intialized to value provided in the parameter
****************************************************************************/
School :: School(string myName, string myState, int theWomen, int myRateAI, int myRateSys,
                 int myRateTheory, int myEffectiveness, int myRatePubs)
{
	name = myName;
	state = myState;
	women = theWomen;
	rateAI = myRateAI;
	rateSys = myRateSys;
	rateTheory = myRateTheory;
	effectiveness = myEffectiveness;
	ratePubs = myRatePubs;
	overallRating = 0;
}//end of School()

/*****************************************************
Name: printSchoolInfo()
Pre: None
Post: prints all of the information contained in a single School object. 
The printout should contain short strings of text that label each data member.
***************************************************/
void School :: printSchoolInfo()
{
	cout << "Name: " << name << endl;
	cout << "State: " << state << endl;
	cout << "Rating of number of women PhD's: " << women << endl;
	cout << "Rating of AI program: " << rateAI << endl; 
	cout << "Rating of Systems program: " << rateSys << endl; 
	cout << "Rating of Theory program: " << rateTheory << endl;
	cout << "Effectiveness rating: " << effectiveness << endl;
	cout << "Rating of faculty publications: " <<  ratePubs << endl; 
	cout << "Overall rating: " << overallRating << endl;
    cout << endl;
}//end of printSchoolInfo()

/*****************************************************
Name: ComputeRating
Pre: The parameters are provided when calling the function
Post: Intializes the overallRating data member by calculating 
rating for the school's graduate program by weight * factor for each factor. 
***************************************************/
void School::computeRating(int weightWomen, int weightAI, int weightSys,
                           int weightTheory, int weightEffect, int weightPubs)
{
	overallRating = (weightWomen * women) + (weightAI * rateAI)
		+ (weightSys * rateSys) + (weightTheory * rateTheory) +
		(weightEffect * effectiveness) + (weightPubs * ratePubs);
}//end of computeRating

/*****************************************************
Name:operator ==  
Pre: None
Post: Returns true if overallRating for 
school x is equal to school y, false otherwise
***************************************************/
bool operator == (const School &x, const School &y)
{
	if (x.overallRating == y.overallRating)
		return true;
	return false;
}//end of overloaded assignment operator == 

/*****************************************************
Name:operator >  
Pre: None
Post: Returns true if overallRating for 
school x is greater than school y, false otherwise
***************************************************/
bool operator > (const School &x, const School &y)
{
	if (x.overallRating > y.overallRating)
		return true;
	return false;
}//end of overloaded > operation

/*****************************************************
Name:operator <  
Pre: None
Post: Returns true if overallRating for 
school x is less than school y, false otherwise
***************************************************/
bool  operator < (const School &x, const School &y)
{
	if (x.overallRating < y.overallRating)
		return true;
	return false;
}//end of overloaded < operator

/*****************************************************
Name:operator >=  
Pre: None
Post: Returns true if overallRating for 
school x is greater than or equal to school y, false otherwise
***************************************************/
bool operator >= (const School &x, const School &y)
{
	if (x.overallRating >= y.overallRating)
		return true;
	return false;
}//end of overloaded >= operator

/*****************************************************
Name:operator <=  
Pre: None
Post: Returns true if overallRating for 
school x is less than or equal to school y, false otherwise
***************************************************/
bool operator <=(const School &x, const School &y)
{
	if (x.overallRating <= y.overallRating)
		return true;
	return false;
}//end of overloaded <= operator

/*****************************************************
Name:operator !=  
Pre: None
Post: Returns true if overallRating for 
school x is NOT equal to school y, false otherwise
***************************************************/
bool operator != (const School &x, const School &y)
{
	if (x.overallRating != y.overallRating)
		return true;
	return false;
}//end of overloaded != operator

