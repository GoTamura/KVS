/*****************************************************************************/
/**
 *  @file   IdleEventListener.cpp
 *  @author Naohisa Sakamoto
 */
/*****************************************************************************/
#include "IdleEventListener.h"
#include <kvs/IgnoreUnusedVariable>
#include <kvs/Binary>


namespace kvs
{

/*===========================================================================*/
/**
 *  @brief  Constructs a new IdleEventListener class.
 */
/*===========================================================================*/
IdleEventListener::IdleEventListener()
{
    kvs::EventListener::setEventType( kvsBinary12( 1111, 1111, 1111 ) );
}

/*===========================================================================*/
/**
 *  @brief  Destructs the IdleEventListener class.
 */
/*===========================================================================*/
IdleEventListener::~IdleEventListener()
{
}

/*===========================================================================*/
/**
 *  @brief  Executes the event function.
 *  @param  event [in] pointer to the event
 */
/*===========================================================================*/
void IdleEventListener::onEvent( kvs::EventBase* event )
{
    kvs::IgnoreUnusedVariable( event );
    this->update();
}

} // end of namespace kvs
