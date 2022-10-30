#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void boucle()
{
   int co = 1;
  SDL_Event event;
  while(co)
    {
      SDL_WaitEvent(&event);
      if(event.type == SDL_QUIT)
	{
	  co = 0;
	}
      else
	{
	  co = 1;
	}
    }
}

int main()
{
  if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr,"ERROR1 : %s\n",SDL_GetError()); exit(-1);
    }
  SDL_Surface * ecran = NULL;
  ecran = SDL_SetVideoMode(800,800,32,SDL_HWSURFACE);
			   
  if(ecran == NULL)
    {
      fprintf(stderr,"ERROR2 : %s\n",SDL_GetError()); exit(-1);
    }
  
  SDL_Surface * carree = NULL;
  carree = SDL_CreateRGBSurface(SDL_HWSURFACE,100,100,32,0,0,0,0);
  SDL_FillRect(carree,NULL,SDL_MapRGB(carree->format,255,255,255));
  
  if(carree == NULL)
  {
    fprintf(stderr,"ERROR3 : %s\n",SDL_GetError()); exit(-1);
  }

  SDL_Rect pos;
  
  for(int i = 0; i < 8;i++)
    {
      pos.y = 100*i;
      for(int j = 0; j < 4;j++)
	{
	  pos.x = 200*j;
	  if(!(i%2))
	    {
	      pos.x += 100;
	    }

	  SDL_BlitSurface(carree,NULL,ecran,&pos);
	}
    }
  SDL_Flip(ecran);
  SDL_FreeSurface(carree);

  boucle();
  
  return 0;
			   
}
