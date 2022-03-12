#ifndef _B_H
#define _B_H

#include "Base.h"

class B : public Base
{
public:
	B(Base* parent_ptr, string name) : Base(parent_ptr, name)
	{}
};

#endif