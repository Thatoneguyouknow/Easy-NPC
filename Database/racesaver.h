#ifndef RACESAVER_H
#define RACESAVER_H

#include "attributesaver.h"
#include "Attributes/race.h"

class RaceSaver : public AttributeSaver
{
public:
    RaceSaver();
    int saveAttributes();
    int readAttributes();
    void removeAllAttributes();
    int removeAttribute(int toRemove);
};

#endif // RACESAVER_H
