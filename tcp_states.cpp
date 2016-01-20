#include "tcp_states.hpp"
#include "tcp.hpp"
#include <iostream>

using namespace TCP::state;

void State::change_state(TCP::Socket* sock, State& state) {
	sock->change_state(state);
}

///////////////// CONCRETE STATES /////////////////
/*
	CLOSED
*/
void Closed::open(TCP::Socket* sock) {
	std::cout << "TCP::State::Closed : open() - Start listening. This is allowed. \n";
	change_state(sock, Listen::instance());
}

void Closed::close(TCP::Socket* sock) {
	std::cout << "TCP::State::Closed : close() - Already closed. What's your problem..\n";
}

/*
	LISTEN
*/
void Listen::open(TCP::Socket* sock) {
	std::cout << "TCP::State::Listen : open() - Already opened, leave me alone.\n";
}

void Listen::close(TCP::Socket* sock) {
	std::cout << "TCP::State::Listen : close() - Stops listening. I'm done.\n";
	change_state(sock, Closed::instance());
}