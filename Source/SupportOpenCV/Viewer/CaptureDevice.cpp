/*****************************************************************************/
/**
 *  @file   CaptureDevice.cpp
 *  @author Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id: CaptureDevice.cpp 602 2010-08-19 02:43:34Z naohisa.sakamoto $
 */
/*****************************************************************************/
#include "CaptureDevice.h"


namespace kvs
{

namespace opencv
{

/*===========================================================================*/
/**
 *  @brief  Constructs a new CaptureDevice class.
 */
/*===========================================================================*/
CaptureDevice::CaptureDevice():
    m_handler( 0 )
{
}

/*===========================================================================*/
/**
 *  @brief  Destructs the CaptureDevice class.
 */
/*===========================================================================*/
CaptureDevice::~CaptureDevice()
{
    this->release();
}

/*===========================================================================*/
/**
 *  @brief  Initializes capturing video from camera.
 *  @param  index [in] index of the camera
 *  @return true, if the the capture device is initialized successfully
 */
/*===========================================================================*/
bool CaptureDevice::create( const int index )
{
    m_handler = cvCreateCameraCapture( index );
    return m_handler != NULL;
}

/*===========================================================================*/
/**
 *  @brief  Initializes capturing video from file.
 *  @param  filename [in] video file name
 *  @return true, if the the capture device is initialized successfully
 */
/*===========================================================================*/
bool CaptureDevice::create( const std::string filename )
{
    m_handler = cvCreateFileCapture( filename.c_str() );
    return m_handler != NULL;
}

/*===========================================================================*/
/**
 *  @brief  Releases the capture device.
 */
/*===========================================================================*/
void CaptureDevice::release()
{
    if ( m_handler ) cvReleaseCapture( &m_handler );
}

/*===========================================================================*/
/**
 *  @brief  Returns the capture device handler.
 *  @return capture device handler
 */
/*===========================================================================*/
const CvCapture* CaptureDevice::handler()
{
    return m_handler;
}

/*===========================================================================*/
/**
 *  @brief  Returns the frame width.
 *  @return frame width
 */
/*===========================================================================*/
double CaptureDevice::frameWidth()
{
    return cvGetCaptureProperty( m_handler, CV_CAP_PROP_FRAME_WIDTH );
}

/*===========================================================================*/
/**
 *  @brief  Returns the frame height.
 *  @return frame height
 */
/*===========================================================================*/
double CaptureDevice::frameHeight()
{
    return cvGetCaptureProperty( m_handler, CV_CAP_PROP_FRAME_HEIGHT );
}

/*===========================================================================*/
/**
 *  @brief  Returns the frame rate.
 *  @return frame rate
 */
/*===========================================================================*/
double CaptureDevice::frameRate()
{
    return cvGetCaptureProperty( m_handler, CV_CAP_PROP_FPS );
}

/*===========================================================================*/
/**
 *  @brief  Grabs frame and the grabbed frame is stored internally.
 */
/*===========================================================================*/
int CaptureDevice::grabFrame() const
{
    return cvGrabFrame( m_handler );
}

/*===========================================================================*/
/**
 *  @brief  Returns the pointer to the grabbed image.
 *  @return pointer to the grabbed image
 */
/*===========================================================================*/
const IplImage* CaptureDevice::retrieveFrame() const
{
    return cvRetrieveFrame( m_handler );
}

/*===========================================================================*/
/**
 *  @brief  Grabs image and returns the pointer to the image.
 *  @return pointer to the grabbed image
 */
/*===========================================================================*/
const IplImage* CaptureDevice::queryFrame() const
{
    return cvQueryFrame( m_handler );
}

} // end of namespace opencv

} // end of namespace kvs
