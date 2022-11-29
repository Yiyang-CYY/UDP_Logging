#ifndef UDP_LOGGING_DATA_FORMAT_H
#define UDP_LOGGING_DATA_FORMAT_H

#include "Std_Types.h"

typedef struct ETH_II_frame_struct {
  uint8  destination_MAC[4];
  uint8  source_MAC[4];
  uint16 type;
} ETH_II_frame_T;

typedef struct IPV4_frame_struct {
  uint8  version :4;
  uint8  IHL :4;       /* internet_header_length */
  uint8  DSCP :6;      /* Differentiated Services Code Point */
  uint8  ECN :2;       /* Explicit Congestion Notification */
  uint16 total_length;
  uint16 identification;
  uint8  flags :3;
  uint16 fragment_offset : 13;
  uint8  TTL;          /* Time to live */
  uint8  protocol;
  uint16 header_checksum;
  uint32 source_ip_address;
  uint32 destination_ip_address;
  uint8  options[0];
} IPV4_frame_T;

typedef struct UDP_frame_struct {
  uint16 source_port;
  uint16 destination_port;
  uint16 length;
  uint16 checksum;
} UDP_frame_T;

typedef struct IPV4_UDP_struct {
  ETH_II_frame_T ETH_frame;
  IPV4_frame_T   IPV4_frame;
  UDP_frame_T    UDP_frame;
} IPV4_UDP_T;

#endif // UDP_LOGGING_DATA_FORMAT_H
