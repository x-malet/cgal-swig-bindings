// ------------------------------------------------------------------------------
// Copyright (c) 2011 GeometryFactory (FRANCE)
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
// ------------------------------------------------------------------------------ 


//there is no #ifndef protection here because this file is meant
//to be included by all packages that need to define an object.
//Each package using this file thus have a decl.h, Object.h and Object.cpp
//SWIG_CGAL_XXXXXX_DECL should be define in Object.h to SWIG_CGAL_[PKG_NAME]_DECL

#include <SWIG_CGAL/Common/Macros.h>
#include <SWIG_CGAL/Kernel/Plane_3.h>
#include <SWIG_CGAL/Kernel/Point_3.h>
#include <SWIG_CGAL/Kernel/Segment_3.h>
#include <SWIG_CGAL/Kernel/Triangle_2.h>
#include <SWIG_CGAL/Kernel/Line_3.h>
#include <SWIG_CGAL/Kernel/Line_2.h>
#include <SWIG_CGAL/Kernel/Point_2.h>
#include <SWIG_CGAL/Kernel/Segment_2.h>
#include <SWIG_CGAL/Kernel/Triangle_3.h>
#include <SWIG_CGAL/Kernel/Ray_2.h>
#include <SWIG_CGAL/Kernel/Ray_3.h>
#include <SWIG_CGAL/Kernel/Polygon_2.h>
#include <SWIG_CGAL/Kernel/Tetrahedron_3.h>
#include <SWIG_CGAL/Kernel/Iso_cuboid_3.h>
#include <SWIG_CGAL/Kernel/Sphere_3.h>


#include <CGAL/Object.h>

#define SWIG_CGAL_DECLARE_FCT_IS_AND_GET(TYPE) \
  bool is_##TYPE()  { return data.is<TYPE::cpp_base>(); } \
  TYPE get_##TYPE() { return TYPE ( CGAL::object_cast<TYPE::cpp_base>(data) ); }
  

class SWIG_CGAL_XXXXXX_DECL Object
{
  CGAL::Object data;
  typedef Object Self;
  //disable deep copy (CGAL::Object is reference counted)
  Self deepcopy();
  void deepcopy(const Self&);  
public:
  #ifndef SWIG
  typedef CGAL::Object cpp_base;
  const cpp_base& get_data() const {return data;}
        cpp_base& get_data()       {return data;}
  Object(const cpp_base& base):data(base){}
  #endif

//Creation
  Object(){};
//function to set and get "stored" object
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Point_2)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Point_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Triangle_2)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Triangle_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Segment_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Segment_2)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Line_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Line_2)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Plane_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Ray_2)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Ray_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Tetrahedron_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Iso_cuboid_3)
  SWIG_CGAL_DECLARE_FCT_IS_AND_GET(Sphere_3)
// special cases
  bool is_Polygon_2(){
    return data.is<std::vector<Point_2::cpp_base> >();
  }
  Polygon_2 get_Polygon_2() {
    const std::vector<Point_2::cpp_base>* points =
      CGAL::object_cast<std::vector<Point_2::cpp_base> >(&data);
    if (points != nullptr)
      return Polygon_2( Polygon_2::cpp_base(points->begin(), points->end()) );
    return Polygon_2();
  }
//Predicate
  SWIG_CGAL_FORWARD_CALL_0(bool,empty)
};


#undef SWIG_CGAL_DECLARE_FCT_IS_AND_GET
