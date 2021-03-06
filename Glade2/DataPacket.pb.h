/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.2 at Sat Dec 15 21:32:42 2018. */

#ifndef PB_DATAPACKET_PB_H_INCLUDED
#define PB_DATAPACKET_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _DataPacket_PacketType {
    DataPacket_PacketType_MEASUREMENT = 0,
    DataPacket_PacketType_ACK = 1
} DataPacket_PacketType;
#define _DataPacket_PacketType_MIN DataPacket_PacketType_MEASUREMENT
#define _DataPacket_PacketType_MAX DataPacket_PacketType_ACK
#define _DataPacket_PacketType_ARRAYSIZE ((DataPacket_PacketType)(DataPacket_PacketType_ACK+1))

/* Struct definitions */
typedef struct _DataPacket {
    DataPacket_PacketType packet_type;
    char identifier[5];
    float value;
/* @@protoc_insertion_point(struct:DataPacket) */
} DataPacket;

/* Default values for struct fields */

/* Initializer values for message structs */
#define DataPacket_init_default                  {_DataPacket_PacketType_MIN, "", 0}
#define DataPacket_init_zero                     {_DataPacket_PacketType_MIN, "", 0}

/* Field tags (for use in manual encoding/decoding) */
#define DataPacket_packet_type_tag               1
#define DataPacket_identifier_tag                2
#define DataPacket_value_tag                     3

/* Struct field encoding specification for nanopb */
extern const pb_field_t DataPacket_fields[4];

/* Maximum encoded size of messages (where known) */
#define DataPacket_size                          14

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define DATAPACKET_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
