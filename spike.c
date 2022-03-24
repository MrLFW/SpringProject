#include "common.h"
static void touch(Entity* other);

void initSpike(char* line)
{
	Entity* e;

	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;

	sscanf(line, "%*s %f %f", &e->x, &e->y);

	e->health = 1;

	e->texture = loadTexture("gfx/spike.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_SOLID + EF_WEIGHTLESS + EF_DANGEROUS;
	e->touch = touch;
	e->touch = e->touch;
}

static void touch(Entity* other)
{
	if (other == player)
	{
		player->x = player->y = 0;
	}
}