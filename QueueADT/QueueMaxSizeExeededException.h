#pragma once
#include <iostream>
#include <string>

using namespace std;

class QueueMaxSizeExeededException
{
	public:
		QueueMaxSizeExeededException();
		~QueueMaxSizeExeededException();
		string getMessage();
	
	private:
		string m_msg;
};

