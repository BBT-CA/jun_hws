/*
 * data.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef DATA_H_
#define DATA_H_

template <typename T>
class Data
{
public:
	void set(T value);
	T get();

private:
	T value_;

};

/* set value */
template <typename T>
void Data<T>::set(T value)
{
	this->value_ = value;
}

/* get value */
template <typename T>
T Data<T>::get()
{
	return this->value_;
}

#endif /* DATA_H_ */
