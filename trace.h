#ifndef TRACE_H
#define TRACE_H

#include <iostream>

#define TRACE(str,...) \
		cout<<__FILE__<<":" \
            <<__LINE__<<":" \
            <<__FUNCTION__<<":" \
            <<str<<endl

#endif
