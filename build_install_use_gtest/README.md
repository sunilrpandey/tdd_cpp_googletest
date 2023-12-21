# tdd_cpp_googletest
h1. Build and use Gtest
```
git clone https://github.com/google/googletest.git -b v1.14.0

the go to googletest directory
    mkdir build 
    cd build
    cmake .. 
    make

    now  you will see lib folder.. list the content and you will find 
    libgtest.a libgtest_main.a
```
h2. Create example.cpp andn link Libraries to it (-lpthread is required for console)
```
g++ example.cpp googletest/build/lib/libgtest.a googletest/build/lib/libgtest_main.a -lpthread -I googletest/googletest/
```
Now you can see a.out, execute it to see test results 