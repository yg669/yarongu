#include "QueueMaxSizeExeededException.h"


QueueMaxSizeExeededException::QueueMaxSizeExeededException()
{
	m_msg = "queue size has exceeded the maximum capacity allowed";
}

QueueMaxSizeExeededException::~QueueMaxSizeExeededException()
{

}

string QueueMaxSizeExeededException::getMessage()
{
	return m_msg;
}