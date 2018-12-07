#include <iostream>
#include <thread>
#include <functional>
#include <time.h>

#include "window.h"

using namespace sf;
using namespace std;



int main()
{
  auto map = new int *[TILE_COUNT_VER];
  for (int i = 0; i < TILE_COUNT_VER; ++i)
  { map[i] = new int[TILE_COUNT_HOR]; }

  auto **rects = new RectangleShape *[TILE_COUNT_VER];
  for (int i = 0; i < TILE_COUNT_VER; ++i)
  { rects[i] = new RectangleShape[TILE_COUNT_HOR]; }
  for (int i = 0; i < TILE_COUNT_VER; ++i)
  {
    for (int j = 0; j < TILE_COUNT_HOR; ++j)
    {
      rects[i][j] = RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE));
      rects[i][j].setPosition(j * TILE_SIZE, i * TILE_SIZE);
      rects[i][j].setFillColor(Color::Transparent);
    }
  }

  auto v_mode = VideoMode(WIN_W, WIN_H);
  auto window = new RenderWindow(v_mode, "Lee algorythm");
  window->setPosition(
    Vector2i(
      VideoMode::getDesktopMode().width / 2 - WIN_W / 2,
      VideoMode::getDesktopMode().height / 2 - WIN_H / 2
    ));
//  window->setFramerateLimit(60);
//  window->setVerticalSyncEnabled(false);
  window->setActive(false);


  auto *window_thread_terminated = new bool(false);
  thread win_th = thread([&]() -> void {
    win_thread(window, rects, window_thread_terminated);
  });

  while (!*window_thread_terminated);

  win_th.join();

  delete window;
  for (int i = 0; i < TILE_COUNT_VER; ++i)
  { delete[] rects[i]; }
  delete[] rects;

  return 0;
}
