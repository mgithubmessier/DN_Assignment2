struct UDPHeader {
	char *sourcePort;
	char *destinationPort;
	char *length;
	char *checksum;
	char **data;
};
struct IPHeader {
	char *version;
	char *IHL;
	char *typeOfService;
	char *totalLength;
	char *identification;
	char *fragmentOffset;
	char *timeToLive;
	char *protocol;
	char *headerChecksum;
	char *sourceAddress1;
	char *sourceAddress2;
	char *destinationAddress1;
	char *destinationAddress2;
};
struct PseudoHeader {
	char *sourceAddress;
	char *destinationAddress;
	char *reserved;
	char *protocol;
	char *udpLength;
};

struct Headers {
	UDPHeader udpHeader;
	IPHeader ipHeader;
	PseudoHeader pseudoHeader;
};