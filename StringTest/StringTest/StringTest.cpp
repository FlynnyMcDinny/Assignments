#include "StringTest.h"
#include <cstring>
#include <string>
#include "String.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>   

StringTest::StringTest()
{

}

StringTest::~StringTest()
{
}

bool StringTest::CheckResult(const char* str1, const char* str2)
{
	return strcmp(str1, str2) == 0;
}

void StringTest::Test()
{
	int passedTests = 0;
	int failedTests = 0;

	std::fstream file;

	file.open("testResults.txt", std::ios::app);
	time_t t = time(0);
	char* dt = ctime(&t);
	if (!file.is_open())
	{
		file.open("testResults.txt", std::ios::out);
	}

	String s1;
	std::string s2;

	bool result = false;

	String time = (String)"Test results for " + dt + "\n";
	file << time.CStr();
	file << ("--------------------------------------------------\n");
	s1 = "Hello";
	s2 = "Hello";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The to c string test has";
	if (result)
	{
		file << "----------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "----------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	s1.Append(" World");
	s2 = "Hello World";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The append string test has";
	if (result)
	{
		file << "--------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "--------------|FAILED|\n";
		failedTests++;
	}

	s1 = " World";
	s1.Prepend("Hello");

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The prepend string test has";
	if (result)
	{
		file << "-------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "-------------|FAILED|\n";
		failedTests++;
	}

	s1 = "HELLO WORLD";
	s1.ToLower();
	s2 = "hello world";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The to lower string test has";
	if (result)
	{
		file << "------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "------------|FAILED|\n";
		failedTests++;
	}

	s1 = "hello world";
	s1.ToUpper();
	s2 = "HELLO WORLD";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The to upper string test has";
	if (result)
	{
		file << "------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "------------|FAILED|\n";
		failedTests++;
	}


	s1 = "I wont give you 100 dollars";

	result = s1.Find("give") == 7;
	file << "The find string test has";
	if (result)
	{
		file << "----------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "----------------|FAILED|\n";
		failedTests++;
	}

	result = s1.Find(7, "give") == 7;
	file << "The find string from index test has";
	if (result)
	{
		file << "-----|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "-----|FAILED|\n";
		failedTests++;
	}

	s1 = "I wont give you 100 dollars";
	s1.Replace("wont", "will");

	s2 = "I will give you 100 dollars";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The replace string test has";
	if (result)
	{
		file << "-------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "-------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";

	result = s1.Length() == 5;
	file << "The length function test has";
	if (result)
	{
		file << "------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	result = s1 == "Hello";

	file << "The equal operator test has";
	if (result)
	{
		file << "-------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "-------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	result = s1 != "Hello1";

	file << "The not equal operator test has";
	if (result)
	{
		file << "---------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "---------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	s1 += " World";

	s2 = "Hello World";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The concat operator test has";
	if (result)
	{
		file << "------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	s1 = s1 + " World";

	s2 = "Hello World";

	result = CheckResult(s1.CStr(), s2.c_str());
	file << "The concat operator test has";
	if (result)
	{
		file << "------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "------------|FAILED|\n";
		failedTests++;
	}

	s1 = "Hello";
	result = s1[0] == 'H';
	file << "The index operator test has";
	if (result)
	{
		file << "-------------|PASSED|\n";
		passedTests++;
	}
	else
	{
		file << "-------------|FAILED|\n";
		failedTests++;
	}


	file << ("--------------------------------------------------\n");
	std::cout << "Passed tests: " << passedTests << std::endl;
	std::cout << "Failed tests: " << failedTests << std::endl;
	String pt = (String)"Passed tests: \t\t\t\t   " + std::to_string(passedTests).c_str() + "\n";
	String ft = (String)"Failed tests: \t\t\t\t   " + std::to_string(failedTests).c_str() + "\n";
	file << (pt.CStr());
	file << (ft.CStr());
	file << ("--------------------------------------------------\n");
	file.close();
}
