#ifndef NET_SOCKET_HPP
#define NET_SOCKET_HPP

#include <string>

namespace net {

/*
	net::Socket

	Kinda like an abstract interface. 
	Everything thats common for a socket.
*/
class Socket {

public:
	using IPAddress = std::string;
	using Port = int;
	
	// Socket::Address
	/* IP + Port */
	struct Address {
		IPAddress addr;
		Port port;
	};

private:
	/* Source (Local address) */
	Socket::Address src_address_;

public:
	inline Socket::Address& src_address() {
		return src_address_;
	}
}; // < net::Socket
}; // namespace net


#endif