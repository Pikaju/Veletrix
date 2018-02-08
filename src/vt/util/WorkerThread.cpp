#include "WorkerThread.h"

#include "Timer.h"

namespace vt {
	
	WorkerThread::WorkerThread() : m_thread(), m_running(false), m_working(false), m_task()
	{
	}
	
	WorkerThread::~WorkerThread()
	{
	}

	void WorkerThread::start()
	{
		VT_DEBUG_ASSERT_M(!m_running, "Cannot start a running worker thread.");
		m_running = true;
		m_thread = std::thread(run, this);
	}

	void WorkerThread::stop()
	{
		VT_DEBUG_ASSERT_M(m_running, "Cannot stop a worker thread that isn't running.");
		m_running = false;
		m_thread.join();
	}

	void WorkerThread::setTask(const ThreadTask& task)
	{
		m_task = task;
		m_working = true;
	}

	ui16f WorkerThread::getConcurrentThreads()
	{
		return std::thread::hardware_concurrency();
	}

	void WorkerThread::run(WorkerThread* workerThread)
	{
	loop:
		// Sleep if there isn't a task to work on.
		while (!workerThread->m_working && workerThread->m_running) {
			Timer::sleep(1);
		}

		// Exit the function if the worker thread should stop running.
		if (!workerThread->isRunning()) {
			return;
		}

		// Execute the current task.
		workerThread->m_task.execute();
		workerThread->m_working = false;
		goto loop;
	}

}