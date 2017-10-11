#include "texture.h"
#include "texture_private.h"

t_texture	**texture_set(void)
{
	static t_texture	*text[TEXT_COUNT];

	return (text);
}

void		text_load(void)
{
	t_texture	**text;

	text = texture_set();
	text[0] = text_read(TEXT_PATH_1);
	text[1] = text_read(TEXT_PATH_2);
}