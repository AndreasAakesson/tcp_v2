#ifndef TCP_STATES_HPP
#define TCP_STATES_HPP

#include "tcp.hpp"

namespace TCP {
/*
	TCP::State

	Collection of all the states available in TCP.
*/
namespace state {

/*
	TCP::State::State

	Interface for a TCP State.
*/
class State {
public:
	virtual void open(TCP::Socket*) = 0;
	//virtual void open(const net::Socket::Address&);
	virtual void close(TCP::Socket*) = 0;

protected:
	void change_state(TCP::Socket* sock, State& state);

}; // < TCP::State::State


///////////////// CONCRETE STATES /////////////////
/*
	CLOSED
*/
class Closed : public State {
public:
	inline static State& instance() {
		static State* instance = new Closed();
		return *instance;
	}

	virtual void open(TCP::Socket* sock) override;
	virtual void close(TCP::Socket* sock) override;

private:
	inline Closed() {};
};

/*
	LISTEN
*/
class Listen : public State {
public:
	inline static State& instance() {
		static State* instance = new Listen();
		return *instance;
	}

	virtual void open(TCP::Socket* sock) override;
	virtual void close(TCP::Socket* sock) override;

private:
	inline Listen() {};
};


};// < TCP::State
}; // < TCP

#endif