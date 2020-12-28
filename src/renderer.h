#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "base.h"
#include "enemy.h"
#include "player.h"
#include "boss_enemy.h"
#include "bullet.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();
  
  void Render(std::vector<enemy*> &ArrayEnemies, std::vector<bullet*> &PlayerBullets, std::vector<bullet*> &BossBullets, std::vector<bullet*> &EnemyBullets, 
  player &player_one, boss * boss_enemy_one, int NumberOfEnemies, int Score);
  
  void Render(std::string gameover);
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  void RenderText( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
  void loadMedia(std::string text); 
  void fillarray(std::vector<enemy*> &ArrayEnemies, int &NumberOfEnemies, SDL_Rect *arr);
  void fillarray(std::vector<bullet*> &Bullets, SDL_Rect *arr);

  void RenderBullets(std::vector<bullet*> &Bullets, SDL_Rect *arr );
  void RenderTextbar(int Score,player &player_one,boss * boss_enemy_one);
  void RenderObjects(player &player_one,std::vector<enemy*> &ArrayEnemies, SDL_Rect *enemy_array, int &NumberOfEnemies, boss * boss_enemy_one);

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif