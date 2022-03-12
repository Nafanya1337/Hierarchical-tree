#ifndef _A_H
#define _A_H

#include "Base.h"

class A : public Base
{
public:
	A(Base* parent_ptr, string name) : Base(parent_ptr, name)
	{}
};

#endif
