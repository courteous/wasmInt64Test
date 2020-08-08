if ("${CMAKE_BUILD_TYPE}" MATCHES "WASM")
	set(CMAKE_SYSTEM_NAME Emscripten)
	MESSAGE( STATUS "CMAKE_SYSTEM_NAME now is set to 		  : " ${CMAKE_SYSTEM_NAME} )

set( MAIN_WASM_SRC 	mainWasm.cpp  )
	
	
	add_executable(wasmExec  ${MAIN_WASM_SRC} )
							 

	set(LINK_FLAGS_1  " -std=c++17 ")
	
	set(LINK_FLAGS_2  " -s WASM=1 ")
	set(LINK_FLAGS_3  " -s TOTAL_MEMORY=256MB ")
	set(LINK_FLAGS_4  " -s ALLOW_MEMORY_GROWTH=1 ")
	set(LINK_FLAGS_5  " -s NO_EXIT_RUNTIME=1 ")
	set(LINK_FLAGS_6  " -s VERBOSE=1 ")
	
	set(LINK_FLAGS_8  " -s DEMANGLE_SUPPORT=1 ")
	set(LINK_FLAGS_9  " -s DISABLE_EXCEPTION_CATCHING=0 ")
	set(LINK_FLAGS_10 " -s ERROR_ON_UNDEFINED_SYMBOLS=1 ")

	set(LINK_FLAGS_12 " -s EXTRA_EXPORTED_RUNTIME_METHODS='['cwrap', 'getValue', 'setValue' ]' ")
	set(LINK_FLAGS_13 " -s EXPORT_ALL=0 ")
	set(LINK_FLAGS_14 " -s SAFE_HEAP=1 ")
	set(LINK_FLAGS_15 " -s LLD_REPORT_UNDEFINED ")	
	
	set(LINK_FLAGS_16 " -s ERROR_ON_UNDEFINED_SYMBOLS=0 ")
	
	set(LINK_FLAGS_30 " -s EXPORTED_FUNCTIONS='[  ")	

	set(LINK_FLAGS_704 " '_intTest', ")
			                  
	
	set(LINK_FLAGS_1000 " '_main' ")
	
	set(LINK_FLAGS_10000 " ]' ") 
	
	
	string(CONCAT LINK_FLAGS_ALL 	"${LINK_FLAGS_1}"
                             		"${LINK_FLAGS_2}"
                            		"${LINK_FLAGS_3}"
                            		"${LINK_FLAGS_4}"
                            		"${LINK_FLAGS_5}"
                            		"${LINK_FLAGS_6}"
    
                            		"${LINK_FLAGS_8}"
                            		"${LINK_FLAGS_9}"
                            		"${LINK_FLAGS_10}"
                            		
                            		"${LINK_FLAGS_12}"
                            		"${LINK_FLAGS_13}"
                            		"${LINK_FLAGS_14}"
                            		"${LINK_FLAGS_15}"
                            		
		                       		"${LINK_FLAGS_16}"                            		
                            		
                            		"${LINK_FLAGS_30}"
                            		
        
                            		"${LINK_FLAGS_704}"
                            		
                            		# main
                            		"${LINK_FLAGS_1000}" 
                            		
                            		
                            		"${LINK_FLAGS_10000}"
                            		
                            		)
	                         		
    set_target_properties(wasmExec PROPERTIES LINK_FLAGS ${LINK_FLAGS_ALL} )

	target_compile_options(wasmExec PUBLIC ${CMAKE_C_FLAGS} -emit-llvm)
	target_compile_options(wasmExec PUBLIC ${CMAKE_CXX_FLAGS} -flto)
	target_compile_options(wasmExec PUBLIC ${CMAKE_CXX_FLAGS} -emit-llvm)



file(COPY index.html DESTINATION ${PROJECT_BINARY_DIR}/src/
FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
NO_SOURCE_PERMISSIONS
)

file(COPY client.js DESTINATION ${PROJECT_BINARY_DIR}/src/
FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
NO_SOURCE_PERMISSIONS
)


endif ()

