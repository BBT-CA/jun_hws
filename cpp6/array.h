/*
 * data.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef ARRAY_H_
#define ARRAY_H_

class Array
{
public:
	Array(){};
	Array(int key,char* name);
	bool operator==(Array& arr);
	bool operator!=(Array& arr);
	bool operator<(Array& arr);
	int getKey();
	char* getName();

private:
	char* name_;
	int key_;

};

/* constructor */
Array::Array(int key,char* name)
{
	this->key_ = key;
	this->name_ = name;
}


bool Array::operator==(Array& arr)
{
	if((arr.key_ == this->key_) && (arr.name_ == this->name_))
		return true;
	return false;
}

bool Array::operator!=(Array& arr)
{
	return !(operator==(arr));
}

bool Array::operator<(Array& arr)
{
	if(arr.key_ < this->key_)
		return true;
	if((arr.key_ == this->key_) && (arr.name_ < this->name_))
		return true;
	return false;
}

int Array::getKey()
{
	return this->key_;
}

char* Array::getName()
{
	return this->name_;
}
#endif /* ARRAY_H_ */
