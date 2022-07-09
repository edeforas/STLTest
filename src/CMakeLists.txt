set(STLTEST_FILES
	Body.cpp Body.h
	BodyFactory.cpp BodyFactory.h
	BodyUnion.cpp BodyUnion.h
	BodyIntersection.cpp BodyIntersection.h
	Geometry.cpp Geometry.h
	Mesh.cpp Mesh.h
	MeshTessellate.cpp MeshTessellate.h
	MeshBoolean.cpp MeshBoolean.h
	Transform.cpp Transform.h
	STLFile.cpp STLFile.h
	OBJFile.cpp OBJFile.h
)

include_directories(.)
add_library( libSTLTest STATIC ${STLTEST_FILES})