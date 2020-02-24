# JAVA JNI and JNA demo built using gradle and cmake

This project provides a simple example that shows how to build java JNI, 
JNA and native code in the same project using gradle.

java-jna, java-jni and native are sub-projects of this demo.

A simple speed comparison between JNA and JNI in this project shows that JNA is 
about 10 times slower than the JNI counterpart.

Native sub-project is built using cmake. And dependencies added accordingly. Cmake is
still the most convenient way to build native C/C++ project.

## build and run

simply run `gradle -q clean build`, each sub-project will be compiled and tested.

run the application:
```bash
> gradle -q  java-jni:run
jni iterations: 10000000 execution_time(ms): 2325
> gradle -q  java-jna:run
OpenJDK 64-Bit Server VM warning: You have loaded library /tmp/jna2852382103107776071.tmp which might have disabled stack guard. The VM will try to fix the stack guard now.
It's highly recommended that you fix the library with 'execstack -c <libfile>', or link it with '-z noexecstack'.
jna iterations: 10000000 execution_time(ms): 26745
```