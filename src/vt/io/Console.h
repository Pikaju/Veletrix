#pragma once

#include "../Build.h"
#include "../Types.h"
#include "../util/String.h"

namespace vt {
	namespace log {
		
		enum LogLevel {
			LOG_LEVEL_INFO,
			LOG_LEVEL_WARNING,
			LOG_LEVEL_ERROR,
			LOG_LEVEL_FATAL
		};
	
		template<typename... Message>
		static void log(const LogLevel& logLevel, Message... message)
		{
			switch (logLevel) {
			case LOG_LEVEL_INFO:
				internal::setColor(15 + 0 * 16);
				internal::print("Info> ", message...);
				break;
			case LOG_LEVEL_WARNING:
				internal::setColor(14 + 0 * 16);
				internal::print("Warning> ", message...);
				break;
			case LOG_LEVEL_ERROR:
				internal::setColor(12 + 0 * 16);
				internal::print("Error> ", message...);
				break;
			case LOG_LEVEL_FATAL:
				internal::setColor(4 + 15 * 16);
				internal::print("Fatal> ", message...);
				break;
			}
		}
	
		template<typename... Message>
		static inline void info(Message... message)
		{
			log(LOG_LEVEL_INFO, std::forward<Message>(message)..., "\n");
		}
	
		template<typename... Message>
		static inline void warning(Message... message)
		{
			log(LOG_LEVEL_WARNING, std::forward<Message>(message)..., "\n");
		}
	
		template<typename... Message>
		static inline void error(Message... message)
		{
			log(LOG_LEVEL_ERROR, std::forward<Message>(message)..., "\n");
		}
	
		template<typename... Message>
		static inline void fatal(Message... message)
		{
			log(LOG_LEVEL_FATAL, std::forward<Message>(message)..., "\n");
		}
	
		namespace internal {

			static inline void print()
			{
			}

			template<typename First, typename... Message>
			static inline void print(First& first, Message... message)
			{
				printElement(first);
				print(message...);
			}
	
			template<typename Message>
			static inline void printElement(Message& message)
			{
				printString(toString(message).c_str());
			}
	
			extern VT_API void printString(cString message);
			extern VT_API void setColor(ui8f color);
	
		}
	}
}