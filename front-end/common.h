#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <string.h>

struct Node
{
	int num;
        char name[200];
	char id[200];
        struct Node *children;
	struct Node *sibling;
};

#define YYSTYPE struct Node*

#endif
