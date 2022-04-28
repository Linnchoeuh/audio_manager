/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89
**
** - print_wave_header.c -
**
** Print a wave header
** *****************************************************************************
*/

#include "wave.h"

static int	wave_print_base10(int    nbr)
{
  char	c;
  int	count;

  if (nbr < 0)
    {
      nbr = -nbr;
      write(STDOUT_FILENO, "-", 1);
    }
  c = nbr % 10 + '0';
  count = 1;
  if (nbr > 9)
    count += wave_print_base10(nbr / 10);
  write(STDOUT_FILENO, &c, 1);
  return (count);
}

static void print_wave_header_part1(t_wave_header *header)
{
	write(STDOUT_FILENO, "File Type Bloc ID : ", 20);
	write(STDOUT_FILENO, header->file_type_bloc_id, 4);
	write(STDOUT_FILENO, "\nFile Size         : ", 22);
	wave_print_base10(header->file_size);
	write(STDOUT_FILENO, "\nFormat ID         : ", 22);
	write(STDOUT_FILENO, header->format_id, 4);
	write(STDOUT_FILENO, "\nID                : ", 22);
	write(STDOUT_FILENO, header->id, 4);
}

static void print_wave_header_part2(t_wave_header *header)
{
	write(STDOUT_FILENO, "\nBloc Size         : ", 22);
	wave_print_base10(header->bloc_size);
	write(STDOUT_FILENO, "\nAudio Format      : ", 22);
	wave_print_base10(header->audio_format);
	write(STDOUT_FILENO, "\nChannels          : ", 22);
	wave_print_base10(header->channels);
	write(STDOUT_FILENO, "\nSample Rate       : ", 22);
	wave_print_base10(header->sample_rate);
	write(STDOUT_FILENO, "\nBytes Per Second  : ", 22);
	wave_print_base10(header->byte_per_second);
	write(STDOUT_FILENO, "\nByte Per Bloc     : ", 22);
	wave_print_base10(header->byte_per_bloc);
	write(STDOUT_FILENO, "\nBits Per Sample   : ", 22);
	wave_print_base10(header->bits_per_sample);
	write(STDOUT_FILENO, "\nData Bloc ID      : ", 22);
	write(STDOUT_FILENO, header->data_bloc_id, 4);
	write(STDOUT_FILENO, "\nData Size         : ", 22);
	wave_print_base10(header->data_size);
}

void wave_print_header(t_wave_header *header)
{
	print_wave_header_part1(header);
	print_wave_header_part2(header);
	write(STDERR_FILENO, "\n", 1);
}