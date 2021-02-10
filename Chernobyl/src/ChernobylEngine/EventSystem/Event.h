 #pragma once
#include <string>
#include "../Core/ChernobylCore.h"

namespace Chernobyl
{
	enum class EventType 
	{

	};

	class CHERNOBYL_API Event {
	public:
		EventType eventType;
	public:
		Event();
		virtual ~Event();
		virtual std::string GetEventName() = 0;
		virtual void Dispatch() = 0;

		EventType GetEventType()
		{
			return eventType;
		}

		
	private:
		bool eventHandled = false;
	};
}