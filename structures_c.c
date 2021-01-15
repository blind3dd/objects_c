// 
// pawelBek
// blind3dd@gmail.com
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdup_c();

typedef struct
{
	int id;
	char* name;
	char* type;
	char* location;
} Object;

char* strdup_c(const char* s)
{
	char* out = NULL;
	if (s != NULL)
	{
		if ((out = malloc(strlen(s) + 1)) != NULL)
			memcpy(out, s, strlen(s) + 1);
	}

	return out;
}

Object *createObject(int id, char *name, char *type, char *addr) {
	// constructor?
	Object *o = malloc(sizeof(Object));
	o->id = id;
	o->name = strdup_c(name);
	o->type = strdup_c(type);
	o->location = strdup_c(addr);

	return o;
}

void display(Object* s)
{
	printf("id : %d\n", s->id);
	printf("Name : %s\n", s->name);
	printf("Type : %s\n", s->type);
	printf("location : %s\n", s->location);
}

void printObject(Object* o, const char* o_name, const int* id, const char* name, const char* type, const char* addr)
{
	printf("Structure %s\nid: %d\nName: %s\nType: %s\nLocation: %s\n", o_name, o->id, o->name, o->type, o->location);
}

int main(int argc, char* argv[])
{
	Object* o1= createObject(1122, "String", "Array", "String location");
	Object* o2 = createObject(1133, "Double", "Number", "Double location");
	Object* o3 = createObject(1144, "Float", "Number", "Float location");

	display(o1);
	display(o2);
	printObject(o3, "Object", o3->id, o3->name, o3->type, o3->location);
}
