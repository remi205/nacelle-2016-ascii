//
// Rémi Prud'homme
//

//#include "stdafx.h"
#include "ParameterParser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int tvc_atoi( char *s );

//#include "TraceFunction.h"

#define strcpy_s strcpy

/////////////////////////////////////////////////////////////////////////
//  Function : ParameterParser
//
//  IN   :  
//          
//  OUT  : 
//  RET  : 
//
//  Notes : initialise tous les slot à zéro
//
/////////////////////////////////////////////////////////////////////////
ParameterParser::ParameterParser( char *Seps )
  {

  m_NumberOfParameters = 0;
  strcpy(m_seps, Seps);
  for ( int i = 0; i < NUMBER_OF_PARAMETER; i++)
    strcpy(m_String[i], "");
  }



/////////////////////////////////////////////////////////////////////////
//  Function : ParseString
//
//  IN   :  InputString, la chaine à parser
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Parse la sting en n sous string qui sont rangées dans
//          un slot
//
/////////////////////////////////////////////////////////////////////////
int ParameterParser::ParseString ( char * InputString )
{
  //char *token;
  int Index = 0;
  int NbParams = 0;

  int len = strlen(InputString);

  int i = 0;
  int last = 0;

  while( Index < len )
    {
      /* Get next token: */
      while ( Index < len && InputString[Index] != m_seps[0])
        Index++;

      strncpy(m_String[i], &InputString[last], Index - last);
      m_String[i][Index - last] = 0;

      if ( Index < len)
        last = Index + 1;

      NbParams++;
      Index++;
      i++;
    }

  m_NumberOfParameters = NbParams;
  return NbParams;
}



/////////////////////////////////////////////////////////////////////////
//  Function : GetString
//
//  IN   :  Index : index du slot considéré
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Retourne le slot désigné par l'index sous la forme 
//          d'une chaine de caractères.
//
/////////////////////////////////////////////////////////////////////////
char * ParameterParser::GetString( int Index)
  {
    return m_String[Index];
  }


/////////////////////////////////////////////////////////////////////////
//  Function : GetInteger
//
//  IN   :  Index : index du slot considéré
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Retourne le slot désigné par l'index sous la forme 
//          d'un entier.
//
/////////////////////////////////////////////////////////////////////////
int ParameterParser::GetInteger ( int Index )
  {
    return tvc_atoi(GetString(Index));
  }

#if 0
/////////////////////////////////////////////////////////////////////////
//  Function : GetFloat
//
//  IN   :  Index : index du slot considéré
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Retourne le slot désigné par l'index sous la forme 
//          d'un flotant.
//
/////////////////////////////////////////////////////////////////////////
float  ParameterParser::GetFloat ( int Index )
{
  return (float )atof( GetString(Index));
}


/////////////////////////////////////////////////////////////////////////
//  Function : GetDouble
//
//  IN   :  Index : index du slot considéré
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Retourne le slot désigné par l'index sous la forme 
//          d'un double.
//
/////////////////////////////////////////////////////////////////////////
double  ParameterParser::GetDouble ( int Index )
{
  return atof( GetString(Index));
}

/////////////////////////////////////////////////////////////////////////
//  Function : GetHex
//
//  IN   :  Index : index du slot considéré
//          
//  OUT  : 
//  RET  : 
//
//  Notes : Retourne le slot désigné par l'index sous la forme 
//          d'un entier.
//
/////////////////////////////////////////////////////////////////////////
int  ParameterParser::GetHex( int Index )
{
  int res;
  //sscanf(GetString(Index), "%x",&res);
  return res;
}

#endif

