/*
* Name: Tim Alberts (timothy.alberts@snhu.edu)
* Course: IT-312-X2914 Software Devel w/C++.Net 20EW2
* Date: 2020-11-08
* Project: Module 7-1
*/

//#define TEST_SUITE

#ifdef TEST_SUITE
#include "test\test_suite.h"
#else
#include "src\application.h"
#endif // TEST_SUITE

int main()
{
#ifdef TEST_SUITE
	TestSuite tests;
	return tests.Run();
#else
	Application app;
	return app.run();
#endif // TEST_SUITE
}
