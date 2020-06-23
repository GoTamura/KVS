/*****************************************************************************/
/**
 *  @file   GLFW.h
 *  @author Naohisa Sakamoto
 */
/*****************************************************************************/
#pragma once
#include <kvs/OpenGL>
#include <GLFW/glfw3.h>


namespace kvs
{

namespace glfw
{

/*===========================================================================*/
/**
 *  @brief  Returns GLFW description.
 *  @return description
 */
/*===========================================================================*/
inline std::string Description()
{
    const std::string description( "GLFW - A Multi-platform Graphics Library Framework." );
    return description;
}


/*===========================================================================*/
/**
 *  @brief  Returns GLFW version.
 *  @return GLFW version string
 */
/*===========================================================================*/
inline std::string Version()
{
    const int major_version = GLFW_VERSION_MAJOR;
    const int minor_version = GLFW_VERSION_MINOR;
    const int patch_version = GLFW_VERSION_REVISION;

    const std::string version(
        kvs::String::ToString( major_version ) + "." +
        kvs::String::ToString( minor_version ) + "." +
        kvs::String::ToString( patch_version ) );
    return version;
}

} // end of namespace glfw

} // end of namespace kvs