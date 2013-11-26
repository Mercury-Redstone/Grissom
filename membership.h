#ifndef membership_h
#define membership_h

#include "sql.h"
#include "user.h"
#include "group.h"

void add_membership(char* uname, char* gname) {
	char *uid=getUid(uname), *gid=getGid(gname);
}

#endif
