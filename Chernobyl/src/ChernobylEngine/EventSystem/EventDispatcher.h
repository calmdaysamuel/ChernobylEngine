#pragma once
#include "Event.h"
#include "../Core/ChernobylCore.h"

namespace Chernobyl
{
	
	class CHERNOBYL_API EventDispatcher
	{

	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{

		}
		
		void Dispatch()
		{
			m_event.Dispatch();
			m_eventHandled = true;
		}

	private:
		Event m_event = event;
		bool m_eventHandled = false;
	};
}