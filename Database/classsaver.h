#ifndef CLASSSAVER_H
#define CLASSSAVER_H

#include "attributesaver.h"
#include "Attributes/class.h"

class ClassSaver : public AttributeSaver
{
public:
    ClassSaver();
    int saveAttributes();
    int readAttributes();
    void removeAllAttributes();
    int removeAttribute(int toRemove);
};

#endif // CLASSSAVER_H
