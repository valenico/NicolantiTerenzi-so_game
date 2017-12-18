#ifndef COMMON_H
#define COMMON_H

// macro to simplify error handling
#define GENERIC_ERROR_HELPER(cond, errCode, msg) do {               \
        if (cond) {                                                 \
            fprintf(stderr, "%s: %s\n", msg, strerror(errCode));    \
            exit(EXIT_FAILURE);                                     \
        }                                                           \
    } while(0)

#define ERROR_HELPER(ret, msg)          GENERIC_ERROR_HELPER((ret < 0), errno, msg)
#define PTHREAD_ERROR_HELPER(ret, msg)  GENERIC_ERROR_HELPER((ret != 0), ret, msg)

/* Configuration parameters */
#define DEBUG           1   // display debug messages
#define MAX_CONN_QUEUE  3   // max number of connections the server can queue
#define UDP_PORT        3000
#define TCP_PORT        4000
#define BUFLEN          1000000
#define UDP_BUFLEN      512

#define SERVER_ADDRESS    "127.0.0.1"
#define UDP_SOCKET_NAME   "[UDP]"
#define TCP_SOCKET_NAME   "[TCP]"

#endif
