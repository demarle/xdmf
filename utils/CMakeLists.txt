include_directories(${CMAKE_CURRENT_SOURCE_DIR})

option(XDMF_BUILD_PARTITIONER OFF)

set(XdmfUtilsExecutables)
set(XdmfUtilsSources
	XdmfTopologyConverter
)
set(XdmfUtilsLinkLibraries Xdmf)

if(XDMF_BUILD_PARTITIONER)
	find_package(Metis REQUIRED)
	if(METIS_FOUND)
		include_directories(${METIS_INCLUDE_DIR})
	endif(METIS_FOUND)
	set(XdmfUtilsExecutables ${XdmfUtilsExecutables} XdmfPartitioner)
	set(XdmfUtilsSources ${XdmfUtilsSources} XdmfPartitioner)
	set(XdmfUtilsLinkLibraries ${XdmfUtilsLinkLibraries} ${METIS_LIBRARIES})
endif(XDMF_BUILD_PARTITIONER)

add_library(XdmfUtils ${XdmfUtilsSources})
target_link_libraries(XdmfUtils ${XdmfUtilsLinkLibraries})

foreach(executable ${XdmfUtilsExecutables})
	add_executable(${executable} ${executable})
	set_target_properties(${executable} PROPERTIES COMPILE_FLAGS -DBUILD_EXE)
	target_link_libraries(${executable} XdmfUtils)
endforeach(executable ${XdmfUtilsExecutables})

if(XDMF_BUILD_TESTING)
	add_subdirectory(tests)
endif(XDMF_BUILD_TESTING)

if(XDMF_WRAP_PYTHON)
	set_source_files_properties(XdmfUtils.i PROPERTIES CPLUSPLUS ON)
	swig_add_module(XdmfUtils python XdmfUtils.i)
	swig_link_libraries(XdmfUtils XdmfUtils ${PYTHON_LIBRARIES})
endif(XDMF_WRAP_PYTHON)