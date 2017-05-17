#include <string.h>
//#include "cmsis_os.h"
//#include "SerialModbus.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xbee_frame.h"


void new_frame(struct escape_api_frame *f, char type )
{
	f->common.frame_id = 1;
	f->common.type = 0;
	f->common.start_delimiter = 0x7E;
}

//////////////////////////////////////////////////////////////////////////////////
// le chksum ne comprend pas la longeur. donc on peut le calcul des que l'add et les data sont posés.
int xbee_chksum (struct escape_api_frame *f, int len)
{
  int sum = 0;

  char *p = (char *)&f->common.type;

  for ( int i = 0; i < len; i++)
    sum += p[i];

  return 255 - (sum & 0xFF);
  }

void xbee_set_address(struct escape_api_frame *f, unsigned long long address)
{
  // address 8 buyes dont le MSB est null. On n'en prend que 6
  unsigned char *in, *out;

  out = (unsigned char*)&f->common.address;
  in = (unsigned char*)&address;

  for (int i = 0; i < 7; i++) {
	out[7-i] = in[i]; 
  }
  out[0] = 0;
}

unsigned long long gondola_addr;

void set_gondola_addr (unsigned long long addr) 
{
  *(unsigned long *)&gondola_addr = addr;
}

// cmd une string 
char* xbee_format_at(struct escape_api_at *f, char *cmd, char *param, int len_param)
{
   	f->common.frame_id = 1;
	f->common.type = REMOTE_AT;
	f->common.start_delimiter = 0x7E;
	f->options = 2;
   	f->address_16 = MAKEWORD(0xFE, 0xFF);

	// set la commande
	int len = strlen(cmd);
	for (int i = 0; i < len; i++) {
		f->rf[i] = cmd[i];
	}

	// set le parametre
	for (int i = 0; i < len_param; i++) {
		f->rf[i + len] = param[i];
	}
	
   unsigned short l = (len + len_param + 13);
   f->common.length = MAKEWORD(l* 256, l %255);

   f->rf[len+len_param] = xbee_chksum((struct escape_api_frame *)f, len + len_param + 13);
   return (char*)f;
}

char* xbee_format_string(struct escape_api_frame *f, char* string)
{ 
   unsigned short len = strlen(string);

   // 17 début d'insertion escape
   // autobauds 7e = > debut de tramme. il faut seulement avoir setting ( j'ai actuellement 0x55)
   // le '\n' faudra verifier que la trame n'en place aucun.
   new_frame(f, TX_TRANSMIT);
   memcpy(&f->rf, string, len);

   f->options = 0;
   f->common.frame_id = 1;
  
   // il faut l'écrire en MSB et non en LSB
   unsigned short l = (len + 11);
   f->common.length = MAKEWORD(l* 256, l %255) ;

   f->rf[len] = xbee_chksum(f, len + 11);
   return (char*)f;
}

unsigned char * xbee_set_power_on(struct escape_api_at *f)
{
  char param = 5;
  xbee_format_at(f, "D0", &param, 1);
  return (unsigned char*)f;
}

unsigned char * xbee_set_power_off(struct escape_api_at *f)
{
  char param = 4;
  xbee_format_at(f, "D0", &param, 1);
  return (unsigned char*)f;
}


bool send_and_receive(struct escape_api_at *frame)
{
#if 0
  WriteModbusBuffer(frame, 20);

  // wait response with status
  if( ReadModbusBuffer(frame, 20))
  	  return true;
  else
	  return false;	
#else
	return true;
#endif
}

bool west_power_off()
{
  struct escape_api_at frame;
    
  xbee_set_address((escape_api_frame*)&frame, WEST);
  xbee_set_power_off(&frame);

  return send_and_receive(&frame);
}

bool west_power_on()
{
  struct escape_api_at frame;
    
  xbee_set_address((escape_api_frame*)&frame, WEST);
  xbee_set_power_on(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool east_power_off()
{
  struct escape_api_at frame;
      
  xbee_set_address((escape_api_frame*)&frame, EAST);
  xbee_set_power_off(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool east_power_on()
{
  struct escape_api_at frame;
  
  xbee_set_address((escape_api_frame*)&frame, EAST);
  xbee_set_power_on(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool south_power_off()
{
  struct escape_api_at frame;
        
  xbee_set_address((escape_api_frame*)&frame, SOUTH);
  xbee_set_power_off(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool south_power_on()
{
  struct escape_api_at frame;
        
  xbee_set_address((escape_api_frame*)&frame, SOUTH);
  xbee_set_power_on(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool m1_power_off()
{
  struct escape_api_at frame;
        
  xbee_set_address((escape_api_frame*)&frame, M1);
  xbee_set_power_off(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

bool m1_power_on()
{
  struct escape_api_at frame;
        
  xbee_set_address((escape_api_frame*)&frame, M1);
  xbee_set_power_on(&frame);

  // wait response with status
  return send_and_receive(&frame);
}

#if 0
void reset_nucleo()
{
  WriteModbusBuffer(&reset_nucleo_low[0], 19);
  // 1 milli seconde
  osDelay(1);
  WriteModbusBuffer(&reset_nucleo_high[0], 19);
}
#endif