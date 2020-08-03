/*****************************************************************************/
/**
 *  @file   CellTag.cpp
 *  @author Naohisa Sakamoto
 */
/*****************************************************************************/
#include "CellTag.h"
#include <kvs/Message>
#include <kvs/String>
#include <kvs/XMLNode>
#include <kvs/XMLElement>


namespace kvs
{

namespace kvsml
{

/*===========================================================================*/
/**
 *  @brief  Constructs a new CellTag class.
 */
/*===========================================================================*/
CellTag::CellTag():
    kvs::kvsml::TagBase( "Cell" ),
    m_ncells( "ncells" )
{
}

/*===========================================================================*/
/**
 *  @brief  Reads the cell tag.
 *  @param  parent [in] pointer to the parent node
 *  @return true, if the reading process is done successfully
 */
/*===========================================================================*/
bool CellTag::read( const kvs::XMLNode::SuperClass* parent )
{
    BaseClass::read( parent );

    const auto* element = kvs::XMLNode::ToElement( BaseClass::m_node );
    const auto ncells = kvs::XMLElement::AttributeValue( element, "ncells" );
    if ( ncells != "" ) { m_ncells = static_cast<size_t>( atoi( ncells.c_str() ) ); }

    return true;
}

/*===========================================================================*/
/**
 *  @brief  Writes the cell tag.
 *  @param  parent [in] pointer to the parent node
 *  @return true, if the writing process is done successfully
 */
/*===========================================================================*/
bool CellTag::write( kvs::XMLNode::SuperClass* parent )
{
    kvs::XMLElement element( BaseClass::name() );
    if ( m_ncells.hasValue() ) { element.setAttribute( "ncells", m_ncells ); }

    return BaseClass::write_with_element( parent, element );
}

} // end of namespace kvsml

} // end of namespace kvs
