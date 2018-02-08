#pragma once

#include "../Build.h"
#include "../PrimitiveTypes.h"

#include <thread>

namespace vt {

	class VT_API ThreadTask
	{
	public:
		// Constructs a task that can call the function with the given parameter.
		VT_CONSTEXPR ThreadTask(void(*function)(void*), void* parameter) : m_function(function), m_parameter(parameter) {  }
		VT_CONSTEXPR ThreadTask() : m_function(nullptr), m_parameter(nullptr) {  }
		~ThreadTask() {  }

		// Executes the task. This method is used by worker threads.
		inline void execute() const { m_function(m_parameter); }
	private:
		void(*m_function)(void*);
		void* m_parameter;
	};

	class VT_API WorkerThread
	{
	public:
		WorkerThread();
		~WorkerThread();

		// Starts the worker thread. Do not call this method if the thread is already running.
		void start();
		// Stops the worker thread. Do not call this method if the thread is not running.
		void stop();

		// Sets the current task for the worker thread. Do not call this method if
		// the thread is currently working on a task.
		void setTask(const ThreadTask& task);

		// Returns true if the worker thread is currently running.
		inline bool isRunning() const { return m_running; }
		// Returns true if the worker thread is currently working on a task.
		inline bool isWorking() const { return m_working; }

		// Returns the maximum number of concurrent threads on the current system.
		static ui16f getConcurrentThreads();
	private:
		static void run(WorkerThread* workerThread);

		std::thread m_thread;
		bool m_running;
		bool m_working;

		ThreadTask m_task;
	};

}