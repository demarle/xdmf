include(AddTestsPython)

# Add any dependencies that the python tests may need
# Note: The tests already depend on their own file
#	PYTHON_TEST_DEPENDENCIES is also set in core
ADD_TEST_PYTHON_DEPENDENCIES("")

# Add any pythonpath directories that the python tests may need
# Note: PYTHON_TEST_PYTHONPATH is also set in core
ADD_TEST_PYTHON_PYTHONPATH("${PYTHON_INCLUDE_MPI4PY_DIR}/../..")

# Add any python tests here:
# Note: We don't want to use a foreach loop to test the files incase we
#	have extra arguments (ie: ADD_TEST_PYTHON(testname inputfile))
#	Read UsePythonTest.cmake for more information
# -----------------------
ADD_TEST_PYTHON(TestXdmfEquals)
ADD_TEST_PYTHON(TestXdmfFunction)
ADD_TEST_PYTHON(TestXdmfFunctionRead)
ADD_TEST_PYTHON(TestXdmfHDF5Writer)
ADD_TEST_PYTHON(TestXdmfRead)
ADD_TEST_PYTHON(TestXdmfSet)
ADD_TEST_PYTHON(TestXdmfWriter)
ADD_TEST_PYTHON(TestXdmfXPointerReference)


# Add any python cleanup here:
# Note: We don't want to use a foreach loop to test the files incase we
#	have multiple files (ie: CLEAN_TEST_PYTHON(testname outputfile1 ...))
#	Read UseCxxTest.cmake for more information
# ---------------------------------------
CLEAN_TEST_PYTHON(TestXdmfEquals)
CLEAN_TEST_PYTHON(TestXdmfFunction
  function.xmf
  function.h5)
CLEAN_TEST_PYTHON(TestXdmfFunctionRead)
CLEAN_TEST_PYTHON(TestXdmfHDF5Writer
  hdf5WriterPythonTest.h5)
CLEAN_TEST_PYTHON(TestXdmfRead
  TestXdmfRead.xmf
  TestXdmfRead.h5)
CLEAN_TEST_PYTHON(TestXdmfSet)
CLEAN_TEST_PYTHON(TestXdmfWriter
  output.h5
  output.xmf)
CLEAN_TEST_PYTHON(TestXdmfXPointerReference
  duplicateXpointer.xmf
  duplicateXpointer.h5
  duplicateXpointer2.xmf
  duplicateXpointer2.h5)


# Add a custom target for all python tests
# Note: ${TARGETS} is set in ADD_TEST_PYTHON
#IF(EXISTS Python_Core_Test_target)
#	SET(Python_Core_Test_target Python_Core_Test_target)
#ENDIF(EXISTS Python_Core_Test_target)

#GET_PROPERTY(targets GLOBAL PROPERTY PYTHON_TEST_TARGETS)
#ADD_CUSTOM_TARGET(Python_ALLTEST ALL DEPENDS ${Python_Core_Test_target} ${targets})
CREATE_TARGET_TEST_PYTHON()
