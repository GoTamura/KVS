/*****************************************************************************/
/**
 *  @file   OrthogonalMatrix44.h
 *  @author Naohisa Sakamoto
 */
/*****************************************************************************/
#pragma once
#include <cmath>
#include <kvs/Matrix44>
#include <kvs/Math>


namespace kvs
{

/*===========================================================================*/
/**
 *  @brief  Return orthogonal matrix (right-hand system).
 *  @param  left [in] Left position.
 *  @param  right [in] Right position.
 *  @param  bottom [in] Bottom position.
 *  @param  top [in] Top position.
 *  @param  near [in] Near position.
 *  @param  far [in] Far position.
 *  @return Orthogonal matrix.
 */
/*===========================================================================*/
template <typename T>
inline kvs::Matrix44<T> OrthogonalMatrix44(
    const T left,
    const T right,
    const T bottom,
    const T top,
    const T znear,
    const T zfar )
{
    KVS_ASSERT( !( kvs::Math::IsZero( right - left ) ) );
    KVS_ASSERT( !( kvs::Math::IsZero( top - bottom ) ) );
    KVS_ASSERT( !( kvs::Math::IsZero( zfar - znear ) ) );

    const T elements[ 16 ] =
    {
        2 / ( right - left ),                    0,                     0,     -( right + left ) / ( right - left ),
                           0, 2 / ( top - bottom ),                     0,     -( top + bottom ) / ( top - bottom ),
                           0,                    0, -2 / ( zfar - znear ),     -( zfar + znear ) / ( zfar - znear ),
                           0,                    0,                     0,                                        1
    };

    return kvs::Matrix44<T>( elements );
}

} // end of namespace kvs
