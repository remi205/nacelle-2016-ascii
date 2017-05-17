
// 4 digit decimaux ; 16/05/2014
int tvc_atoi( char *s )
{
  if ( s[3] != 0 && s[2] != 0  && s[1] != 0)
    return (s[3] - 48) + (s[2] - 48) * 10 + (s[1] - 48) * 100 + (s[0]- 48) * 1000 ;
  if ( s[2] != 0  && s[1] != 0)
    return (s[2]- 48) + (s[1]- 48) * 10 + (s[0]- 48) * 100;
  else if ( s[1] != 0 )
    return (s[1]- 48) + (s[0]- 48) * 10;
  else
    return s[0]- 48;
}
