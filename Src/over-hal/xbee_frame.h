#pragma once

#define XBEE1 0x13A20040B4B8 // Coordinators 
#define XBEE2 0x13A20040B45F // Coordinators : gateway central
#define XBEE3 0x13A20040B272 // Router
#define XBEE4 0x13A20040B271 // Router
#define XBEE5 0x13A20040B4B1 // Router  
#define XBEE6 0x13A20040B2A9 // Router
#define XBEE7 0x13A20040B274 // Router
#define XBEE8 0x13A20040B2A5 // Router : 
#define XBEE9 0x13A20040B464 // Router
#define XBEE10 0x13A20040B2A6 // Router

#define EAST    XBEE9
#define WEST    XBEE5
#define SOUTH   XBEE7
#define M1   	XBEE6
#define GONDOLA XBEE3 // ou xbee 10

#pragma pack(1)
struct escape_common {
	unsigned char  start_delimiter;
	unsigned short length;
	unsigned char  type;
	unsigned char  frame_id;

	/*  */
	char address[8];
};

#pragma pack(1)
struct escape_api_frame {
	struct escape_common common;
	unsigned char  options;
	
	/* apriori pas de chaine plus de 200 characteres. */
	char rf[200];
	// check sum a la fin de la payload. Donc a l'interieur dr rf. 
 };

// 0X17
#pragma pack(1)
struct escape_api_at {
	struct escape_common common;
	unsigned short address_16;
    unsigned char  options;
	char rf[64];
 };

#if 0
unsigned char xbee_frame[255] = {0x7E, 0x00, 0x10, 0x17, 0x01, 0x00, 0x13, 0xA2, 0x00, 0x40, 0xF8, 0xB4, 0x5F, 0xFF, 0xFE, 0x02, 0x44, 0x30, 0x05, 0x16};
#endif
#define TX_TRANSMIT 0
#define REMOTE_AT   0x17

void new_frame(struct escape_api_frame *f, char type );
void xbee_set_address(struct escape_api_frame *f, unsigned long long address);

char* xbee_format_string(struct escape_api_frame *f, char* string);

char* xbee_format_at(struct escape_api_at *f, char *cmd, char *param, int len_param);

typedef unsigned char BYTE;
typedef unsigned short WORD;

#ifndef MAKEWORD
#define MAKEWORD(a,b)   ((WORD)(((BYTE)(a))|(((WORD)((BYTE)(b)))<<8)))
#endif

bool west_power_off();
bool west_power_on();
bool east_power_off();
bool east_power_on();

bool south_power_off();
bool south_power_on();

bool m1_power_off();
bool m1_power_on();
