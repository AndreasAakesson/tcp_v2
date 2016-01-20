#ifndef TCP_HPP
#define TCP_HPP

#include "socket.hpp"

#include <iostream>
#include <map>

namespace TCP {

namespace state {
	class State;
}

/* 
	TCP::Socket

	A Socket following the TCP Protocol
*/
class Socket : public net::Socket {

private:
	friend class state::State;
	using TCPState = state::State;
	TCPState* state_;

	/* Change TCP State for the current Connection (socket) */
	void change_state(TCPState& state);

public:
	/*
		Create a Socket in with a State::Closed
	*/
	Socket();
	// LISTEN (Passive open)
	void open();
	// SYN_SENT (Active open)
	void open(const net::Socket::Address&);
	// CLOSED
	void close();

}; // < TCP::Socket


/*
	TCP::StreamSocket

	A TCP Socket "acting" like a stream.
	Has a peer on the other side (destination). 
	Can read/write.
*/
class StreamSocket : public Socket {
	using Packet = std::string;
private:
	/* Destination */
	net::Socket::Address dest_address_;

public:
	inline net::Socket::Address& dest_address() {
		return dest_address_;
	}

	inline void read(Packet& packet) {

	};

	inline void write(Packet& packet) {

	};

}; // < TCP::StreamSocket


/*
	TCP::ServerSocket

	A "passive" TCP Socket used for "server".
	It kinda works like a router for one or many StreamSocket. 
*/
class ServerSocket : public Socket {
private:
	std::map<net::Socket::Address, StreamSocket> connections_;

public:
	inline ServerSocket() {

	};

	inline ServerSocket& bind(Port) {
		return *this;
	};

	inline void listen() {

	};

	/*inline StreamSocket& accept() {
		StreamSocket sock;
		return sock;
	};*/

}; // < TCP::ServerSocket

}; // < namespace TCP


#endif