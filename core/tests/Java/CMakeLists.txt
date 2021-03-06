INCLUDE(AddTestsJava)

#Add any dependencies that the java core tests may need
# Note: The tests already depend on their own file
ADD_TEST_JAVA_DEPENDENCIES(Compiled_XdmfCore_Jar)

# Add any classpath directories that the java tests may need
ADD_TEST_JAVA_CLASSPATH("${XdmfCore_JAVA_JAR}")

# Add any ldpath directories that the java tests may need
ADD_TEST_JAVA_LDPATH("${CMAKE_BINARY_DIR}")
ADD_TEST_JAVA_LDPATH("${XDMF_LIBRARIES}")

# Add any path directories that the java tests may need
ADD_TEST_JAVA_PATH("${CMAKE_BINARY_DIR}")
ADD_TEST_JAVA_PATH("${XDMF_BINARIES}")

# Add any java tests here:
# Note: We don't want to use a foreach loop to test the files incase we
#	have extra arguments (ie: ADD_TEST_JAVA(testname inputfile))
#	Read UseJavaTest.cmake for more information
# ------------------------
ADD_TEST_JAVA(TestXdmfEquals)
ADD_TEST_JAVA(TestXdmfArray)

# Add any java cleanup here:
# Note: We don't want to use a foreach loop to test the files incase we
#	have multiple files (ie: CLEAN_TEST_JAVA(testname outputfile1 ...))
#	Read UseCxxTest.cmake for more information
# ---------------------------------------
CLEAN_TEST_JAVA(TestXdmfEquals)
CLEAN_TEST_JAVA(TestXdmfArray)

# Add a custom target for all java tests 
# Note: ${TARGETS} is set in ADD_TEST_JAVA
CREATE_TARGET_TEST_JAVA()
