#include <iostream>
#include <vector>
#include <memory>

class StateMashine
{
public:
	class IEvent
	{
	public:
		class State
		{
		public:
			virtual ~State() = default;

			virtual void enter() = 0;
			virtual void leave() = 0;
		};

		virtual operator bool() const = 0;
		virtual void invoke(State&) = 0;
	};
	static class StatePointer
	{
	public:
		void operator=(IEvent::State* state)
		{
			if(current_state != nullptr)
				current_state->leave();

			current_state = state;
			if(current_state != nullptr)
				current_state->enter();
		}

		IEvent::State* operator->() { return current_state; }
		IEvent::State* operator&() { return current_state; }
		IEvent::State& operator*() { return *current_state; }

	private:
		IEvent::State* current_state;
	} state_ptr;

	static std::vector<IEvent*> events;
	static std::vector<const IEvent> event_queue;
	template <typename T>
	class AEvent : public IEvent
	{
	public:
		class State { public: State() { T::get(); } virtual void event(T&) = 0; };

		virtual void invoke(IEvent::State& state) override final
		{
			if(*this)
			{
				try { dynamic_cast<State&>(state).event(dynamic_cast<T&>(*this)); }
				catch(...) {}
			}
		}

	protected:
		AEvent() { events.push_back(this); }
	};

	static void start(IEvent::State* state)
	{
		state_ptr = state;

		//while(true)
		for(int j = 0; j < 10; ++j)
		{
			for( std::size_t i = 0; i < events.size(); ++i)
				events[i]->invoke(*state_ptr);
		}
	}
};
StateMashine::StatePointer StateMashine::state_ptr;
std::vector<StateMashine::IEvent*> StateMashine::events;
std::vector<const StateMashine::IEvent> StateMashine::event_queue;

#define SINGLETON(class_name) \
	public: \
		static class_name& get() \
		{ \
			return singleton; \
		} \
	private: \
		class_name() {} \
		class_name(const class_name&) = delete; \
		void operator=(const class_name&) = delete; \
		static class_name singleton;\
	public:

#define START_EVENT(event_name) \
	struct event_name : StateMashine::AEvent<event_name> \
	{ \
		SINGLETON(event_name)

#define START_STATE(state_name) \
	struct state_name : \
		StateMashine::IEvent::State\
	{ \
		SINGLETON(state_name)

#define END_EVENT(name) };\
	name name::singleton;

#define END_STATE(name) };\
	name name::singleton;





START_EVENT(Event1)
	virtual operator bool() const { StateMashine::event_queue.push_back(this); }
END_EVENT(Event1)

START_EVENT(Event2)
	virtual operator bool() const {return true;}
END_EVENT(Event2)

START_EVENT(Event3)
	virtual operator bool() const {return true;}
END_EVENT(Event3)

START_EVENT(Change)
	virtual operator bool() const {return true;}
END_EVENT(Change)


START_STATE(State12)
	virtual void enter() { std::cout << "Enter State12" << std::endl; }
	virtual void leave() { std::cout << "Leave State12" << std::endl; }

	virtual void event( Event1& ) { std::cout << "state12::Event 1\n" ; }
	virtual void event( Event2& ) { std::cout << "state12::Event 2\n" ; }
	virtual void event( Change& );
END_STATE(State12)

START_STATE(State23)
	virtual void enter() { std::cout << "Enter State23" << std::endl; }
	virtual void leave() { std::cout << "Leave State23" << std::endl; }

	virtual void event( Event2& ) { std::cout << "state23::Event 2\n" ; }
	virtual void event( Event3& ) { std::cout << "state23::Event 3\n" ; }
	virtual void event( Change& );
END_STATE(State23)

void State23::event(Change &) { StateMashine::state_ptr = &State12::get(); }
void State12::event(Change &) { StateMashine::state_ptr = &State23::get(); }

int main(void)
{
	std::cout << StateMashine::events.size() << std::endl;
	StateMashine::start(&State12::get());

	return 0;
}
