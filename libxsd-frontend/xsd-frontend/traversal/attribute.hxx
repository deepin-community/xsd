// file      : xsd-frontend/traversal/attribute.hxx
// copyright : Copyright (c) 2005-2014 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX
#define XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX

#include <xsd-frontend/traversal/elements.hxx>

#include <xsd-frontend/semantic-graph/attribute.hxx>


namespace XSDFrontend
{
  namespace Traversal
  {
    struct Attribute : Node<SemanticGraph::Attribute>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      belongs (Type&, EdgeDispatcher&);

      virtual void
      belongs (Type&);

      virtual void
      name (Type&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX
