#pragma once

#include "../Types.h"

#include "WorkerThread.h"

namespace vt {

	class VT_API ThreadPool
	{
	public:
		ThreadPool();
		~ThreadPool();

		// Starts the thread pool with the given amount of worker threads.
		// Do not use this method if the thread pool is already running.
		void start(ui16f numThreads);
		// Stops the thread pool. Do not use this method if the thread pool isn't running.
		void stop();

		// Returns true if all worker threads are busy.
		bool isSaturated() const;
		// Assigns the task to a currently unoccupied thread.
		// Returns false if no unused thread was found.
		bool addTask(const ThreadTask& task);

		// Returns the maximum number of concurrent threads on the current system.
		static inline ui16f getConcurrentThreads() { return WorkerThread::getConcurrentThreads(); }
	private:
		WorkerThread* m_threads;
		ui16f m_numThreads;
	};

}