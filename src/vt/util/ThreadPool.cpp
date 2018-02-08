#include "ThreadPool.h"

namespace vt {

	ThreadPool::ThreadPool() : m_threads(nullptr), m_numThreads(0)
	{
	}

	ThreadPool::~ThreadPool()
	{
	}

	void ThreadPool::start(ui16f numThreads)
	{
		VT_DEBUG_ASSERT_M(m_numThreads == 0, "Cannot start a running thread pool.");
		m_numThreads = numThreads;
		m_threads = new WorkerThread[m_numThreads];
		for (ui16f i = 0; i < m_numThreads; i++) {
			m_threads[i].start();
		}
	}

	void ThreadPool::stop()
	{
		VT_DEBUG_ASSERT_M(m_numThreads != 0, "Cannot stop a thread pool that isn't running.");
		for (ui16f i = 0; i < m_numThreads; i++) {
			m_threads[i].stop();
		}
		delete[] m_threads;
		m_numThreads = 0;
	}

	bool ThreadPool::isSaturated() const
	{
		for (ui16f i = 0; i < m_numThreads; i++) {
			if (!m_threads[i].isWorking()) {
				return false;
			}
		}
		return true;
	}

	bool ThreadPool::addTask(const ThreadTask& task)
	{
		for (ui16f i = 0; i < m_numThreads; i++) {
			if (!m_threads[i].isWorking()) {
				m_threads[i].setTask(task);
				return true;
			}
		}
		return false;
	}

}