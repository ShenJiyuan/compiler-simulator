
#include <stdio.h>
#include <string.h>


typedef struct _AttrT{
	int space;    //everytime entering a func, plus 1
	int isLeft;
	

}AttrT;

typedef struct _NodeT{
	int nType;	/*0:default 1:int 2:id 3:operator(include int, if, else...) 4:inner node */
	char *stri;
	AttrT attr;
	struct _NodeT *son;
	struct _NodeT *sibling;
        int isArray;  //is Array?
}NodeT;

typedef struct _IDT {
	char* id;
	int space;    //global=0    local>0
	int isPara;
	char* num;
        int isArray;  //is Array?
} IDT;

typedef struct _FUNC {
        char* ftype; //function return type
        char* name;  //function name
} FUNC;
