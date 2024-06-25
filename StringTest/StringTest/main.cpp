#include "main.h"
#include "StringTest.h"
#include "String.h"
#include <ctime>  

void main() 
{
	time_t t = time(0);
	char* dt = ctime(&t);
	String time = dt;
	String null;
	StringTest ST;
	null.WriteToConsole();
	time.WriteToConsole();
	ST.Test();
}