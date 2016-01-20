#include "tcp.hpp"
#include "tcp_states.hpp"
#include <iostream>

using namespace TCP;

/*void Socket::change_state(TCPState* state) {
	state_ = state;
}*/
void Socket::change_state(TCPState& state) {
	std::cout << "TCP::Socket : change_state() - Changing state...\n";
	state_ = &state;
	//std::cout << "TCP::Socket : change_state() - Changing state ( " << &state_ << " )\n";
}

Socket::Socket()
	: state_(&state::Closed::instance())
{ 
	std::cout << "TCP::Socket : Socket() - Closed socket was created.\n";	
};

void Socket::open() {
	//std::cout << "TCP::Socket : open() - LISTEN (Passive open)\n";
	state_->open(this);
}
void Socket::open(const net::Socket::Address&) {
	//std::cout << "TCP::Socket : open(const Socket::Address&) - SYN_SENT (Active Open)\n";
}
void Socket::close() {
	//std::cout << "TCP::Socket : close() - CLOSED\n";
	state_->close(this);
}