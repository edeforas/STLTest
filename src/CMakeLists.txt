set(STLTEST_FILES
	Body.cpp Body.h
	BodyFactory.cpp BodyFactory.h
	BodyUnion.cpp BodyUnion.h
	BodyIntersection.cpp BodyIntersection.h
	BodyDifference.cpp BodyDifference.h
	Geometry.cpp Geometry.h
	
	Mesh.cpp Mesh.h
	MeshKernel.cpp MeshKernel.h
	MeshKernelTIN.cpp MeshKernelTIN.h
	MeshKernelHalfEdge.cpp MeshKernelHalfEdge.h
	MeshKernelLinkedTriangles.cpp MeshKernelLinkedTriangles.h
	MeshMeasurements.cpp MeshMeasurements.h

	MeshTessellate.cpp MeshTessellate.h
	MeshBoolean.cpp MeshBoolean.h
	Transform.cpp Transform.h
	STLFile.cpp STLFile.h
	OBJFile.cpp OBJFile.h
	
	Renderer.cpp Renderer.h
	Image.h
	ImageGenerator.cpp ImageGenerator.h
	ImageIoBmp.cpp ImageIoBmp.h
)

include_directories(.)
add_library( libSTLTest STATIC ${STLTEST_FILES})