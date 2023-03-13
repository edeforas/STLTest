set(STLTEST_FILES
	Body.cpp Body.h
	BodyFactory.cpp BodyFactory.h
	BodyUnion.cpp BodyUnion.h
	BodyIntersection.cpp BodyIntersection.h
	BodyDifference.cpp BodyDifference.h
	Geometry.cpp Geometry.h
	
	Face.cpp Face.h
	
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
	
	NurbsSurface.cpp NurbsSurface.h
	NurbsCurve.cpp NurbsCurve.h
	StepFile.cpp StepFile.h
	
	BezierTriangle.cpp BezierTriangle.h
	
	Renderer.cpp Renderer.h
	RendererCamera.cpp RendererCamera.h
	RendererLight.cpp RendererLight.h
	Image.h
	ImageGenerator.cpp ImageGenerator.h
	ImageIoBmp.cpp ImageIoBmp.h
	Color.h
	Util.h
)

include_directories(.)
add_library( libSTLTest STATIC ${STLTEST_FILES})