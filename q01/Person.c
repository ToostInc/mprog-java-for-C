/******************************************************************************
 * Person.c
 *
 * Minor Programmeren
 * Joost Bremmer, 10113452
 *
 * This will contain the functions to make a person talk about his age
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "Person.h"

/*
 * main() Function to reproduce PersonTest()
 * Create two Persons, initialize them and have them
 * talk and comment about their age.
 */
int main()
{
	//empty PersonPtrs
    PersonPtr ls = NULL;
    PersonPtr ss = NULL;

	//Initialize their values.
    ls = make_person("Luke Skywalker", 34);
    ss = make_person("Slim Shady", 48);

	//Test for errors
	if (!ss || !ls)
	{
      fprintf(stderr, "\033[0;31mIt appears something has gone wrong!\n");
      return 1;
    }

	//talk and comment about their age.
	talk(ls);
	commentAboutAge(ls);
    talk(ss);
    commentAboutAge(ss);

	//Free people from their bondage.
    free(ls);
    free(ss);

    return 0;

}

/*
 * Function to print a person's name and age to stdout
 * Requires an initialized Person* p as argument
 */
void talk(PersonPtr p)
{
    fprintf(stdout, "Hi my name is %s \n", p->name);
    fprintf(stdout, "and my age is %d \n", p->age);
    fprintf(stdout, "\n");
}

/*
 * Makes a comment about a person's age if the person's age
 * if that person is of the age 5 or under.
 * Requires an initialized Person* p as argument
 */
void commentAboutAge(PersonPtr p)
{
    //check if person is of the age 5 or under,
    //if so comment about it.
    if (p->age < 5)
        fprintf(stdout, "little babby \n");
    else if (p->age == 5)
        fprintf(stdout, "Time to start school! \n");
    else
        fprintf(stdout, "... \n");

	fprintf(stdout, "\n");
}

/*
 * Function to initialize a Person to contain values
 *
 * Takes the following arguments
 * char * aName = String of the name of the Person
 * int    anAge = int of the person's age
 *
 * Returns the Person*, pointing to an initialized Person
 */
PersonPtr make_person(String aName, int anAge)
{
    PersonPtr person = NULL;

    //If the Person is not yet initialized, require memory
    if(!person)
        person = malloc(sizeof(Person));

    //Still not initialized? Then we have a problem
    if(!person)
        fprintf(stderr, \
		"\033[0;31mHalp, I don't have any memory to work with!");

    //Initialize the person's values
    person->name = aName;
    person->age  = anAge;

    return person;
};

//vim: set tabstop=2 shiftwidth=2 expandtab:
