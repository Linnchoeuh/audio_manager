/**
 ** @file main.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

typedef struct s_struct
{
  t_bunny_window	*ws;
  t_bunny_picture *px;
  t_bunny_effect *fx1;
  t_bunny_effect *fx2;
  double cursor;
}               t_struct;

static t_bunny_response	key_response(t_bunny_event_state	state,
                                     t_bunny_keysym		sym,
                                     void			*data)
{
  t_struct *s;

  s = data;
  if (state == GO_UP && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_UP && sym == BKS_SPACE)
  {
    if (bunny_sound_is_playing(&s->fx1->sound))
    {
      s->cursor = bunny_sound_get_cursor(&s->fx1->sound);
      bunny_sound_stop(&s->fx1->sound);
      bunny_sound_set_cursor(&s->fx2->sound, s->cursor);
      bunny_sound_play(&s->fx2->sound);
    }
    else
    {
      s->cursor = bunny_sound_get_cursor(&s->fx2->sound);
      bunny_sound_stop(&s->fx2->sound);
      bunny_sound_set_cursor(&s->fx1->sound, s->cursor);
      bunny_sound_play(&s->fx1->sound);
    }
  }
  return (GO_ON);
}

static t_bunny_response	main_loop(void				*data)
{
  t_struct		*s;

  s = (t_struct*) data;
  bunny_fill(&s->px->buffer, BLACK);
  bunny_blit(&s->ws->buffer, s->px, NULL);
  bunny_display(s->ws);
  return (GO_ON);
}

int			main(int				argc,
			     char				*argv[])
{

  t_struct *s;

  if (argc == 1)
    return (0);
  s = bunny_malloc(sizeof(t_struct));
  s->fx1 = bfx_load_audio(argv[1], false);
  // s->fx2 = bfx_load_audio(argv[1], false);
  if (s->fx1 == NULL)
    return (0);
  s->cursor = 0;
  bunny_compute_effect(s->fx1);
  // bunny_compute_effect(s->fx2);
  bunny_sound_play(&s->fx1->sound);
  s->ws = bunny_start(256, 256, 0, "Bunny");
  s->px = bunny_new_picture(s->ws->buffer.width, s->ws->buffer.height);
  bunny_set_key_response(key_response);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(s->ws, 15, s);

  bunny_stop(s->ws);
  bunny_delete_clipable(s->px);
  bunny_delete_sound(&s->fx1);
  // bunny_delete_sound(s->fx2);
  return (0);
}

