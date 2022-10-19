/****************************************************************
File name: gradSchools.cc
Name: Apurva Gandhi
Assignment: Assignment 8
Date: 04/27/2019
CSCI132
Professor: Saba Kadady
Purpose: Implementation of the GradSchools class
*****************************************************************/
#include "gradSchools.h"

/*****************************************************
Name: GradSchools (Constructor) 
Pre: None
Post: clear the schools data member.
***************************************************/
GradSchools::GradSchools()
{
	schools.clear();
}//end of GradSchools()

/****************************************************************
Name: addSchool 
Pre: The parameters are provided when calling the function
Post:This function creates a new instance 
of the School class and add it to the schools list
in the GradSchools object that is used to call the function.
****************************************************************/
void GradSchools::addSchool(string name, string state, int women, int rateAI, int rateSys,
                            int rateTheory, int effect, int ratePubs)
{
	School newSchools = School(name, state, women, rateAI, rateSys, rateTheory, effect, ratePubs);
	schools.insert(schools.size(), newSchools);
}//end of addSchool()

/*******************************************************************************
Name: printGradSchools()
Pre: None
Post: Prints all of the information that is stored in the entire GradSchools
object used to invoke this method.(Utilizes printSchoolInfo from school class.
***********************************************************************************/
void GradSchools::printGradSchools()
{
    cout << "There are " << schools.size() << " schools in the database:" << endl;
    cout << endl;
    School x;

	for (int i = 0; i < schools.size(); i++)
	{
		schools.retrieve(i, x);
		x.printSchoolInfo();
	}
}//end of printGradSchools

/*******************************************************************************
Name: printSortedGradSchools()
Pre: None
Post: Helper function to print names of the sorted schools (given their prefrence)
***********************************************************************************/
void GradSchools :: printSortedGradSchools()
{
	cout << "Ranking of Grad School programs, given your preferences: " << endl;
	School x;
	for (int i = schools.size() - 1 ; i >= 0; i--)
	{
		schools.retrieve(i, x);
		cout << x.name << endl;
	}
    cout << endl; 
}//printSortedGradSchools

/*******************************************************************************
Name: computeRatings()
Pre: None
Post: computes the overallRating for each of the School objects stored in the schools array, 
using the computeRating() method defined for the School class.
***********************************************************************************/
void GradSchools::computeRatings(int weightWomen, int weightAI, int weightSys,
                                 int weightTheory, int weightEffect, int weightPubs)
{
	School x;
    for (int i = 0; i < schools.size(); i++)
	{
		schools.retrieve(i, x);
		x.computeRating(weightWomen, weightAI, weightSys, weightTheory, weightEffect, weightPubs);
		schools.replace(i, x);
	}
}//end of computeRatings

/*******************************************************************************
Name: rankSchools
Pre: None
Post: sorts all of the School objects contained in the schools Sortable_list
using the overallRating as the basis for the ranking and print the names of the schools
***********************************************************************************/
void GradSchools::rankSchools(int weightWomen, int weightAI, int weightSys,
                              int weightTheory, int weightEffect, int weightPubs)
{
	computeRatings(weightWomen, weightAI, weightSys, weightTheory, weightEffect, weightPubs);
	schools.selection_sort();
    printSortedGradSchools();
}//end of rankSchools

/*******************************************************************************
Name: rankSchoolsFactor
Pre: None
Post: ranks the schools based on a single factor provided in the parameter
***********************************************************************************/
void GradSchools :: rankSchoolsFactor(string factor)
{
    if (factor == "women")
		rankSchools(1, 0, 0, 0, 0, 0);
	else if(factor == "AI")
		rankSchools(0, 1, 0, 0, 0, 0);
	else if (factor == "sys")
		rankSchools(0, 0, 1, 0, 0, 0);
	else if (factor == "theory")
		rankSchools(0, 0, 0, 1, 0, 0);
	else if (factor == "effect")
		rankSchools(0, 0, 0, 0, 1, 0);
	else if(factor == "pub")
		rankSchools(0, 0, 0, 0, 0, 1);
}//end of rankSchoolsFactor
    
