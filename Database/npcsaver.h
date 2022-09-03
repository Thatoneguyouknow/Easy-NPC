#ifndef NPCSAVER_H
#define NPCSAVER_H

#include "attributesaver.h"
#include "generator.h"

class NpcSaver : public AttributeSaver
{
public:
    NpcSaver();
    int saveAttributes();
    int readAttributes();
    void removeAllAttributes();

private:
    QString npcSqlSaveQuery;
    QString npcSqlReadQuery;
    QString npcSqlDeleteQuery;
};

#endif // NPCSAVER_H
