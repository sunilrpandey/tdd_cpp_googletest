## Why add main functions for google tests( Are InitGoogleTest and RUN_ALL_TESTS required)

Add below lines in CMakeLists.txt
```
  include(GoogleTest)
  gtest_discover_tests(${PROJECT_NAME})
```
and no need to write main function for google tests

```
{
    cout << "\n\n\n\n*****\n\nPopulating tests from gtest main" << endl;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
```
