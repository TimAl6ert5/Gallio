/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-12-13
* Project: Module 7-1
*/

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>

class Serializable
{
public:
	/* Convert the object state to a string. */
	virtual void serialize(std::string&) const = 0;
	/* Restore the object state from a string. Return flag indicating success (True). */
	virtual bool deserialize(std::string&) = 0;
};

#endif // SERIALIZABLE_H
