#include "Queue.h"
#include "QueueMaxSizeExeededException.h"

Queue::Queue(int size)
{
	if (size > m_max_size)
		throw QueueMaxSizeExeededException();

	m_val = new int[size];
	m_capacity = size;
	m_count = 0;
	m_front_val = 0;
	m_back_val = 0;
}

Queue::Queue(const Queue &q)
{
	m_val = new int[q.m_count];
	m_back_val = q.m_back_val;
	m_front_val = q.m_front_val;
	m_capacity = q.m_capacity;
	m_count = q.m_count;
}

Queue::~Queue()
{
	delete [] m_val;
	m_val = NULL;
}

bool Queue::isFull()
{
	if (Size() == m_capacity)
		return true;
	else
		return false;
}

bool Queue::isEmpty()
{
	if (Size() == 0)
		return true;
	else
		return false;
}

int Queue::Size()
{
	return m_count;
}

void Queue::Enqueue(int item)
{	
	if (isFull())
	{
		std::cerr << "Enqueue error: queue is full." << std::endl;
		return;
	}
    m_count++;
	m_val[m_count-1] = item;
	if (m_count == 1)
	{
		m_front_val = m_val[0];
		m_back_val = m_front_val;
	}
	else
	{ 
		m_front_val = m_val[m_count - 1];
		m_back_val = m_val[0];
	}
}

void Queue::Dequeue()
{
	if (isEmpty())
	{
		std::cerr << "Dequeue error: queue is empty." << std::endl;
		return;
	}
	m_count--;
	if (m_count > 0)
	{
		m_front_val = m_val[m_count - 1];
	}
	else
	{
		m_front_val = m_empty_val;
		m_back_val =  m_empty_val;
	}
}

int Queue::FrontVal()
{
	if (isEmpty())
	{
		std::cerr << "FrontVal error: queue is empty." << std::endl;
	}
	return m_front_val;
}

int Queue::BackVal()
{
	if (isEmpty())
	{
		std::cerr << "BackVal error: queue is empty." << std::endl;
	}
	return m_back_val;
}

int Queue::PeekValue(int index)
{
	if (index > m_count || index <= 0)
	{
		std::cerr << "PeekValue error: valid peek range is from 1 to " << m_count << " returning last enqueued value ";
		return m_back_val;
	}
	else
		return m_val[index - 1];
}

Queue& Queue::operator=(const Queue &q)
{
	if (this != &q)
	{
		this->m_capacity = q.m_capacity;
		this->m_back_val = q.m_back_val;
		this->m_front_val = q.m_front_val;
		this->m_count = q.m_count;
		
		for (int i = 0; i < q.m_count; ++i)
		{
			this->m_val[i] = q.m_val[i];
		}
	}
	return *this;
}

void Queue::PrintQueue()
{
	for (int i = 0; i < m_count; ++i)
	{
		std::cout << "place: " << (i+1) << " value: " << m_val[i] << std::endl;
	}
}
